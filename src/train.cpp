#include<iostream>
#include<armadillo>

#include"randomInitialize.hpp"
#include"sigmoid.hpp"
#include"costFunction.hpp"
#include"printMat.hpp"

using namespace arma;

int main(){
	mat X = randu(3,20)*10;
	umat y = conv_to<umat>::from(randu(10,1)*10);

	vec initialTheta = join_vert(vectorise(generateRandomMatrix(250,50)) , vectorise(generateRandomMatrix(50,10)));
	
	cout << costFunction(initialTheta, 250,50,10,X,y,1) << endl;
	
	return 0;
}
