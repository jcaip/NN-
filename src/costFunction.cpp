#include<armadillo>
#include"costFunction.hpp"
#include"printMat.hpp"

using namespace arma;

class nnCostFunction{	
	vec gradient;
	double cost;

	nnCostFunction(vec theta_large,int input_layer_size,int hidden_layer_size,int num_labels,mat X,umat y,int lambda){
		
		
	}	
	
	private double getCost(vec theta_large,int input_layer_size,int hidden_layer_size,int num_labels,mat X,umat y,int lambda){
		//defining some variables 
		int m = X.n_rows;
		double J = 0;
		
		mat theta1 = mat(input_layer_size*hidden_layer_size, 1);
		mat theta2 = mat(num_labels*hidden_layer_size, 1);
		
		//unrolls the parameters	
		for(int i=0;i<theta_large.size();i++){
			if(i<hidden_layer_size*input_layer_size){
				theta1(i,0) = theta_large(i);	
			}
			else{
				theta2(i-(hidden_layer_size*input_layer_size),0) =theta_large(i);
			}
		}
		theta1.resize(input_layer_size,hidden_layer_size);
		theta2.resize(hidden_layer_size,num_labels);
		
		//generate a large y array for the cost function
		umat y_large = (y==0);
		for(int i=1; i<y.size(); i++){
			y_large = join_horiz(y_large, y==i);
		}

		
		return 0;
	}

	private vec getGradient(){
	
	}

	private vec update()
}
