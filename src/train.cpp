#include<iostream>
#include<armadillo>

#include"randomInitialize.hpp"
#include"sigmoid.hpp"

using namespace arma;

int main(){
	mat initialTheta = generateRandomMatrix(5,5);
	cout << initialTheta << endl;
	cout << sigmoid(initialTheta) << endl;
	return 0;
}
