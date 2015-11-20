#include<armadillo>
#include<math.h>
#include<tuple>
#include"printMat.hpp"
#include"costFunction.hpp"

using namespace arma;

mat minimize(vec guess, int max_iter, std::tuple parameters){
	//TODO write this function
	double rho = 0.01; //constant for line search
	double sig = 0.5; // constant for Wolfe-Powell conditions
	double eval_limit = 0.1; //dont reevaluate within 0.1 of the limit of the current bracket
	double extr_limit = 2.0; //extrapolate maximun of 3 times in the current bracket
	int max_eval_line_search = 20; //determines the maximun number of evaluations for a line search
	int max_slope_ratio = 100; //gives the max slope ratio to be define

	bool line_search_failed = false;
	int red =1;
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

		guess += step1*search_direction; //begins the line search
		
		vec gradient2 = vec(); // same pointless initialization
		double cost2 = costFunction(paramteres,gradient2);
		double step2;
		double slope2 = gradient2.t()*search_direction;
		
		double cost3 = cost1;  // clone for a point 3
		double slope3 = slope1;
		double step3 = -step1;

		int max_iter_line_search = (max_iter>0?) max_eval_line_search : -length-i; //set max iterations for the line search
		bool success = false;
		double limit =-1;

		while(true){
			while (((cost2 > cost1+step1*rho*slope1 || slope2 > -sig*slope1)) && (max_iter_line_search >0)){
				limit = step1;

				if(cost2>cost1)
					step2 = cost3 - ((0.5*slope3*step3*step3)/(step3*slope3+cost3-cost3));
				else{
					//quadratic approximation
					double alpha = 6*(cost2-cost3)/slope3+3*(slope3+slope2);
					double beta = 3*(cost3-cost3) - cost3*(slope3+2*slope2);
					step2 = (sqrt(beta*beta-alpha*slope2*step3*step3)-beta)/alpha;
				}
				if (isnan(step2) || isinf(step2))
					step2 = step3/2;
				
				step2 = std::max(std::min(step2, eval_limit*step3), (1-eval_limit)*step3); //dont get too close to the limit
				step1 += step2;
				guess += step2*search_direction;

				cost2 = costFunction(parameter, gradient2);

				max_iter_line_search--;
				i++;

				slope2 = gradient2.t()*search_direction;
				step3 -= step2;
			}

			if ((cost2 > cost1+step1*rho*slope1)) || (slope2> -sig*slope1)
				break;
			else if(slope2 > sig*slope1){
				//line search was a success
				success = true;
				break;
			}
			else if(max_iter_line_search ==0)
				break;

			//cubic approximation now
			double alpha = 6*(cost2-cost3)/slope3+3*(slope3+slope2);
			double beta = 3*(cost3-cost3) - cost3*(slope3+2*slope2);
			
			step2  = -slope2*step3*step3/(beta+sqrt(beta*Beta-alpha*slope2*step3*step3));
			if(isnan(step2 || isinf(step2)|| step2 <0){
				if(limit < -0.5)
					step2 = step1 * (extr_limit - 1);
				else
					step2 = (limit-step1)/2;
			}
			else if (limit > -0.5 && step2+step1>limit)
				step2 = (limit-step1)/2;
			else if (limit < -0.5 && step2+step1 > step1*extr_limit)
				step2 = step1*(extr_limit -1);
			else if (step2 < -step3*eval_limit)
				step2 = -step3*eval_limit;
			else if (limit > -0.5 && step2 < (limit-step1)*(1.0-eval_limit))
				step2 = (limit-step1)*(1-eval_limit);

			cost3 = cost2;
			slope3 = slope2
			step3 = -step2;
			step1 += step2;
			X+= step2*search_direction;

			cost2 = costFunction(guess, params, gradient2);
			max_iter_line_search--;
			i++;
			slope2 = gradient2.t()*search_direction;
		}

		if(success){
			cost1 = cost2 //set cost to right cost
			//print out variables
			std::cout.precision(10);
			std::cout.fixed;
			std::cout<<"Iteration "<<i <<" | Cost: "<<cost1<<std::endl;							
			// Polack-Ribiere derivative
			search_direction = (gradient2.t()*gradient1 + gradient1.t()*gradient2)/(gradient1.t()*gradient1)*search_direction - gradient2;
			
			//swap derivative
			vec temp = vec(gradient1);
			gradient1 = gradient2;
			gradient2 = temp;

			slope2 = gradient2.t()*search_direction;
			if(slope2 > 0){
				search_direction = -gradient1;
				slope2 = -search_direction.t() *search_direction;
			}

			step1 += std::min(RATIO, slope1/(slope2));
			slope1 = slope2;
			line_search_failed = false;
		}
		else{
			guess = guess0; //reset values
			cost1 = cost0;
			gradient1 = gradient0;
			if (line_search_failed || i > max_iter){
				break;
			}
		//swap derivatives	
			vec temp = vec(gradient1);
			gradient1 = gradient2;
			gradient2 = temp;
			search_direction = -gradient1;

			slope1 = -search_direction.t()*search_direction;
			step1 = 1/(1-slope1);
			line_search_failed = true;
		}
	}
}

