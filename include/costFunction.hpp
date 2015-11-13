#ifndef COSTFUNCTION_HPP
#define COSTFUNCTION_HPP

typedef std::tuple<arma::mat, arma::umat, int,int,int,double> nnParams;

double costFunction(arma::vec& t_large, nnParams& params, arma::vec& grad);

#endif
