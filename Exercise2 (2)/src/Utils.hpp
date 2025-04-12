#pragma once
#include <iostream>

using namespace std;

bool LetturaData(const string& filename,double &S, int &n, double*& w, double*& r);

double RateReturn(const double* w, const double* r, int n);

void PrintResult(double S, int n, const double* w, const double* r, double R, double FinalValue, std::ostream& out);


