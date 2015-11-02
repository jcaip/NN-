#include<iostream>
#include<armadillo>

#include"randomInitialize.hpp"
#include"costFunction.hpp"
#include"printMat.hpp"
#include"sigmoid.hpp"

using namespace arma;

int main(){
	mat X = randu(3,20)*10;
	umat y = conv_to<umat>::from(randu(10,1)*10);

	vec initialTheta = vec(join_vert(vectorise(generateRandomMatrix(250,50)) , vectorise(generateRandomMatrix(50,10))));

	mat grad = zeros(3,3);
	printMat(grad, "grad");
	double cost =  costFunction(initialTheta, 250,50,10,X,y,1, grad);
	cout<<cost<<endl;	
	return 0;
}
