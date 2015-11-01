#include<armadillo>
#include"randomInitialize.hpp"

using namespace std;
using namespace arma;


arma::mat generateRandomMatrix(int xsize, int ysize){
	//generate a random matrix of size x by y
	std::cout<<"Generating random vlaues for a ("<< xsize <<"x"<< ysize <<") matrix"<<std::endl;
	mat A = randu<mat>(xsize,ysize);
	return A;
}



