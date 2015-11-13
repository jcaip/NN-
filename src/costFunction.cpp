#include<armadillo>
#include<tuple>
#include"costFunction.hpp"
#include"printMat.hpp"
#include"sigmoid.hpp"

using namespace arma; 

double costFunction(vec& theta_large, std::tuple<mat, umat, int, int, int, double> & params , vec& grad){
	mat& X = std::get<0>(params);
	umat& y = std::get<1>(params);
	int input_layer_size = std::get<2>(params);
	int hidden_layer_size = std::get<3>(params);
	int num_labels = std::get<4>(params);
	double lambda = std::get<5>(params);
	
	//TODO change this so that it takes in a std::tuple instead of so much stuff
	//This cost function takes in a theta_large vector and then unrolls the parameters. 
	//Also takes in the input layer size, hidden layer size, and the output layer size
	//Cost function also updates the gradient matrix refrenced
	std::cout<<std::endl;
	std::cout<<"Computing Cost Function\n-----------------------"<<std::endl;

	//defining some variables 
	int m = X.n_rows;
	double J = 0;
	
	mat theta1 = mat((input_layer_size+1)*hidden_layer_size, 1);
	mat theta2 = mat(num_labels*(hidden_layer_size+1), 1);

	//unrolls the parameters	
	for(int i=0;i<theta_large.size();i++){
		i < hidden_layer_size*(input_layer_size+1)? theta1(i,0) = theta_large(i) : theta2(i-(hidden_layer_size*(input_layer_size+1)),0) = theta_large(i);
	}
	theta1.resize(hidden_layer_size,input_layer_size+1);
	theta2.resize(num_labels,hidden_layer_size+1);

	std::cout<<"Finished unrolling theta values"<<std::endl;
	
	//this implements the feedforward part of the neural network function
	
	mat A1 = join_horiz(ones<mat>(m,1), X);	
	mat A2 = join_horiz(ones<mat>(m,1), sigmoid(A1*theta1.t()));
	mat h_theta = sigmoid(A2*theta2.t());

	std::cout<<"Finished neural network feed-forward" <<std::endl;
	
	mat delta3 = mat(h_theta);	

	//computes the cost, parallelized for each y_i individually on each thread
	#pragma omp parallel
	{
		#pragma omp for
		for (int i=0; i<num_labels; i++){
			mat y_i = conv_to<mat>::from(y==i);
			J += accu(-y_i%log(h_theta.col(i)) - (1-y_i)%log(1-h_theta.col(i))) / m;
jj			delta3.col(i) = delta3.col(i)-y_i;
	}
	}
	
	//adds regularization term to cost
	J += (accu(square(theta1)) + accu(square(theta2)) - 2*m) * (lambda/(2*m));

	std::cout<<"Finished computing cost regularized cost function" <<std::endl;
	//now it updates the gradient
	
	mat delta2 = delta3*theta2.cols(1,theta2.n_cols-1) % sigmoidGradient(A1*theta1.t());
	
	mat theta2_grad = (delta3.t()*A2)/m;
	mat theta1_grad = (delta2.t()*A1)/m;

	theta1_grad.cols(1, theta1_grad.n_cols-1) += lambda/m*theta1.cols(1, theta1.n_cols-1);
	theta2_grad.cols(1, theta2_grad.n_cols-1) += lambda/m*theta2.cols(1, theta2.n_cols-1);

	grad = join_vert(vectorise(theta1_grad), vectorise(theta2_grad));	
	
	std::cout<<"Finished updating gradient vector"<<std::endl;

	return J;
}
