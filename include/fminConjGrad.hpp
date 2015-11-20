#ifndef FMINCONJGRAD_HPP
#define FMINCONJGRAD_HPP
typedef std::tuple<arma::mat, arma::umat, int, int,int,double> nnParams;

arma::mat minimize(arma::mat, nnParams& params);

#endif
