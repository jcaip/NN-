#include<iostream>
#include<armadillo>
#include<string>
#include"printMat.hpp"

using namespace std;
using namespace arma;

void printMat(mat m, string name){
	cout << endl;
	cout << name << ": size (" << m.n_rows << "," << m.n_cols <<") :" <<endl;
	cout << m << endl;
	return;
}
void printMat(imat m, string name){
	cout << endl;
	cout << name << ": size (" << m.n_rows << "," << m.n_cols <<") :" <<endl;
	cout << m << endl;
	return;
}
void printMat(umat m, string name){
	cout << endl;
	cout << name << ": size (" << m.n_rows << "," << m.n_cols <<") :" <<endl;
	cout << m << endl;
	return;
}
