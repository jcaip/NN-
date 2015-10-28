#include<armadillo>
#include<iostream>
#include"costFunction.hpp"

using namespace arma;

double costFunction(vec theta_large,int input_layer_size,int hidden_layer_size,int num_labels,mat X,mat y,int lambda){
	int m = X.n_rows;
	double J = 0;
	
	mat theta1 = mat(input_layer_size*hidden_layer_size, 1);
	mat theta2 = mat(sizeof(theta_large) - input_layer_size*hidden_layer_size, 1);
	
	for(int i=0;i<sizeof(theta_large);i++){
		if(i<hidden_layer_size*input_layer_size){
			theta1(i,1) = theta_large(i);	
		}
		else{
			theta2(i-hidden_layer_size*input_layer_size,1) =theta_large(i);
		}
	}
	theta1.resize(input_layer_size,hidden_layer_size);
	theta2.resize(hidden_layer_size,num_labels);
	


	cout << "The y_large matrix is: " << endl;

	
	return 0;
}

