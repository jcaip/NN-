#ifndef COSTFUNCTION_HPP
#define COSTFUNCTION_HPP

double costFunction(arma::vec t_large,  int ils, int hls, int nl, arma::mat X, arma::umat y, int lambda, arma::vec& grad);

#endif
