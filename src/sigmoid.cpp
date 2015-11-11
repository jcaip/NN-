#include<armadillo>
using namespace arma;

mat sigmoid(mat input){
	//returns the sigmoid of a matrix
	input = 1/( ones(size(input))+ exp(-input));
	return input;	
}

mat sigmoidGradient(mat input){
	//returns the gradient of the sigmoid function
	return sigmoid(input) % (1-sigmoid(input)); 
}
