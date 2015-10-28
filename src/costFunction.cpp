#include<armadillo>

using namespace arma;

double costFunction(row theta_large,int input_layer_size,int hidden_layer_size,int num_labels,mat X,col y,int lambda){
	int m = X.n_rows;
	double J = 0;
	
	mat theta1 = mat(rowvec(input_layer_size*hidden_layer_size)).resize(input_layer_size, hidden_layer_size);
	mat theta2 = mat(rowvec(sizeof(theta_large)-(input_layer_size*hidden_layer_size))).resize(hidden_layer_size,num_labels);
	

	

	for(int i=0;i<sizeof(theta_large);i++){
		while(i<input_layer_size){
		
		}
	}
}
