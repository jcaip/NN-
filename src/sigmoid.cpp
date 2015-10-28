#include<armadillo>
using namespace arma;

mat sigmoid(mat input){
	input = 1/( ones(input.size())+ exp(-input));
	return input;	
}
