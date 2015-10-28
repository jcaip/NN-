#include<iostream>
#include<armadillo>
#include"randomInitialize.hpp"

using namespace std;
using namespace arma;


arma::mat generateRandomMatrix(int xsize, int ysize){
	std::cout<<"Generating random vlaues for a ("<< xsize <<"x"<< ysize <<") matrix"<<std::endl;
	mat A = randu<mat>(xsize,ysize);
	return A;
}



