#include<armadillo>
#include<tuple>
#include"printMat.hpp"
#include"costFunction.hpp"

using namespace arma;

mat minimize(vec guess, vec& grad, int max_iter, std::tuple parameters){
	//TODO write this function
	//TODO actually learn this and what the fuck is going on
	double rho = 0.01; //constant for line search
	double sig = 0.5; // constant for Wolfe-Powell conditions
	double eval_limit = 0.1; //dont reevaluate within 0.1 of the limit of the current bracket
	double extr_limit = 2.0; //extrapolate maximun of 3 times in the current bracket
	int max_eval_line_search = 20; //determines the maximun number of evaluations for a line search
	int max_slope_ratio = 100; //gives the max slope ratio to be define

	bool lines_search_failed = false;
	int red =1;
	//TODO wtire tuple_cat function that concatenates a guess to the vector
	vec gradient1 =vec();//pointless initialziation, this will be changed later
	double cost1 = costFunction(parameters,gradient1);

	vec search_direction = -gradient;
	double slope1 = -search_direction.t()*search_direction;
	double step1 = red/(1-slope1);

	for(int i=0; i<max_iter; i++){
		
		//first we make a copy of all the variables that we need
		vec guess0 = vec(guess);
		double cost0 = cost1;
		vec gradient0 = vec(gradient1);

		guess += z1*s; //begins the line search
		
		vec gradient2 = vec(); // same pointless initialization
		double cost2 = costFunction(paramteres,gradient2);

		double slope2 = gradient2.t()*search_direction;
		
		double cost3 = cost1;  // clone for a point 3
		double slope3 = slope1;
		double step3 = -step1;

		int max_iter_line_search = (max_iter>0?) max_eval_line_search : -length-i; //set max iterations for the line search
		int success = 0;
		int limit =-1;

		while(true){
			while
		}
	}
}

