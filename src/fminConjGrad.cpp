#include<armadillo>
#include"printMat.hpp"
#include"costFuction.hpp"

using namespace arma;

mat minimize(vec guess, vec& grad, int max_iter){
	//TODO write this function
	double rho = 0.01; //constant for line search
	double sig = 0.5; // constant for Wolfe-Powell conditions
	double eval_limit = 0.1; //dont reevaluate within 0.1 of the limit of the current bracket
	double extr_limit = 2.0; //extrapolate maximun of 3 times in the current bracket
	int max_eval_line_search = 20; //determines the maximun number of evaluations for a line search
	int max_ration = 100; //gives the max slope ratio to be define

	bool lines_search_failed = false;

	double cost1 = costFunction;
}

