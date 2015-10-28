#include<iostream>
#include<armadillo>

#include"randomInitialize.hpp"
#include"sigmoid.hpp"
#include"costFunction.hpp"

using namespace arma;

int main(){
	mat X = randu(30,250)*10;
	mat y = randu(10,1)*10;
	cout << (y == 1) <<endl;
	mat initialTheta = vectorise(generateRandomMatrix(250,50)) + vectorise(generateRandomMatrix(50,10));
	cout << initialTheta << endl;
	cout << sigmoid(initialTheta) << endl;
	//cout << costFunction(initialTheta, 250,50,10,X,y,1) << endl;
	return 0;
}
