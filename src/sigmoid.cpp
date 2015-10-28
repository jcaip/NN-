#include<armadillo>
using namespace arma;

mat sigmoid(mat input){
	input = 1/( ++exp(-input));
	return input;	
}
