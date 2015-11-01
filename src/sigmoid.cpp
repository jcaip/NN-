#include<armadillo>
using namespace arma;

mat sigmoid(mat input){
	//returns the sigmoid of a matrix
	input = 1/( ones(input.size())+ exp(-input));
	return input;	
}
