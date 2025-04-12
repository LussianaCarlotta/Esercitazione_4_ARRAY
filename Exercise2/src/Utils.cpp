#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "utils.hpp"

using namespace std;

//Funzione che legge data.txt
bool LetturaData(const string& filename,double &S, int &n, double*& w, double*& r)
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
	
	for (int i = 0; i < n; ++i)
	{		
		char separatore;
        file >> w[i] >> separatore >> r[i];
	}
	file.close();
	return true;
}

// Funzione che calcola il tasso di rendimento 
double RateReturn(const double* w, const double* r, int n) 
{
    double sum = 0.0;
    for (int i = 0; i < n; ++i) 
	{
        sum += w[i] * r[i];
    }
    return sum;
}

//Stampa dei risultati 
void PrintResult(double S, int n, const double* w, const double* r, double R, double FinalValue, ostream& out) 
{
    out << fixed << setprecision(2);
    out << "S = " << S << ", n = " << n << endl;;

	//torno alla precisione normale
	cout.unsetf(ios::fixed);
	cout.precision(6);

    out << "w = [ ";
    for (int i = 0; i < n; ++i){
        out << w[i] << " ";
	}
    out << "] " <<endl;

    out << "r = [ ";
    for (int i = 0; i < n; ++i){
        out << r[i] << " ";
	}
    out << "] " << endl;

    out << setprecision(4);
    out << "Rate of return of the portfolio: " << R << endl;

    out << fixed << setprecision(2);
    out << "V: " << FinalValue << endl;
}
