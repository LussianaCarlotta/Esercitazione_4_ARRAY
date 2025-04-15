#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "utils.hpp"

using namespace std;

//Funzione che legge data.txt
bool LetturaData(const string& filename, double &S, size_t &n, double*& w, double*& r)
{
	ifstream file(filename);
    if(file.fail()) 
	{
        cerr << "Errore nell'apertura del file " << filename << endl;
        return false;
    }
	
	string line;
	string tmp;
		
	//leggo S
	getline(file, line);
	stringstream ss1(line);
	getline(ss1, tmp, ';');
	ss1 >> S;
	
	//Leggo n
	getline(file, line);
	stringstream ss2(line);
	getline(ss2,tmp,';');
	ss2 >> n;
		
	getline(file, line);
	
	//Leggo w e r 
	w = new  double[n];
	r = new  double [n];
	
	for (size_t i = 0; i < n; i++)
	{		
		char separatore;
        file >> w[i] >> separatore >> r[i];
	}
	file.close();
	
	return true;
}

// Funzione che calcola il tasso di rendimento 
double RateReturn(const double* w, const double* r, size_t &n) 
{
    double sum = 0.0;
    for (size_t i = 0; i < n; i++) 
	{
        sum += w[i] * r[i];
    }
    return sum;
}

//Stampa dei risultati 
void PrintResult(double &S, size_t &n, const double* const &w, const double* const &r, double &R, double &V, ostream& out)
{
	out << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;

	//torno alla precisione normale
	out << std::defaultfloat;
	
    out << "w = [ ";
    for (size_t i = 0; i < n; i++)
	{
        out << w[i] << " ";
	}
    out << "] " <<endl;

    out << "r = [ ";
    for (size_t i = 0; i < n; i++)
	{
        out << r[i] << " ";
	}
    out << "] " << endl;

    out << "Rate of return of the portfolio: " << fixed << setprecision(4) << R << endl;

    out << "V: " << fixed << setprecision(2) << V << endl;
}
