#include<iostream>
#include<armadillo>

#include"randomInitialize.hpp"
#include"costFunction.hpp"
#include"printMat.hpp"
#include"sigmoid.hpp"

using namespace arma;

int main(){
	mat X = randu(20,20)*10;
	umat y = conv_to<umat>::from(randu(20,1)*10);

	vec initialTheta = join_vert(vectorise(generateRandomMatrix(21,15)), vectorise(generateRandomMatrix(16,10)));
	vec grad = vectorise(zeros(3,3));
	double cost =  costFunction(initialTheta, 20,15,10,X,y,1, grad);
	cout<<cost<<endl;
	return 0;
}
