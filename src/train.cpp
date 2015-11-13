#include<iostream>
#include<tuple>
#include<armadillo>
#include<nlopt.hpp>
#include"randomInitialize.hpp"
#include"costFunction.hpp"
#include"printMat.hpp"
#include"sigmoid.hpp"

using namespace arma;

typedef std::tuple<mat, umat, int,int,int,double> nnParams;

vec train(int examples, nnParams cost_parameters, vec& guess, vec& starting_grad){
	nlopt::opt opt(nlopt::LD_LBFGS, examples);
	
	opt.set_min_objective(costFunction, cost_parameters);
	opt.set_ftol_rel(1e-15);
	double minCost = 0;
	
	nlopt::result optimizedResult = opt.optimize(guess);

	std::cout<<minCost<<std::endl;
		
}

int main(){
	mat X = randu(20,20)*10;
	umat y = conv_to<umat>::from(randu(20,1)*10);

	vec initialTheta = join_vert(vectorise(generateRandomMatrix(21,15)), vectorise(generateRandomMatrix(16,10)));
	vec grad = vectorise(zeros(3,3));
	auto cost_function_parameters = std::make_tuple(X, y, 20, 15, 10, 1.0);
	double cost =  costFunction(initialTheta, cost_function_parameters, grad);
	cout<<cost<<endl;
	train(20, cost_function_parameters, initialTheta, grad);
	return 0;
}
