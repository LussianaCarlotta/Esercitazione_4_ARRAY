#pragma once
#include <iostream>

using namespace std;

//LetturaData legge il file data.txt e importa i vettori dal file
// S: somma totale investita
// n: numero di assets
// r: risultato del tasso di rendimento dell'i-esimo asset 
// w: frazione di S investita nell'i-esimo asset
bool LetturaData(const string& filename,
				double &S, 
				size_t& n, 
				double*& w,
				double*& r);

// RateReturn restituisce il tasso di rendimento totale
// n: numero di assets
// r: risultato del tasso di rendimento dell'i-esimo asset 
// w: frazione di S investita nell'i-esimo asset
double RateReturn(const double* w, 
				const double* r, 
				size_t &n);


// PrintResult stampa i risultati
// n: numero di assets
// r: risultato del tasso di rendimento dell'i-esimo asset 
// w: frazione di S investita nell'i-esimo asset
// R: tasso di rendimento totale 
// V: valore finale del portafoglio 
void PrintResult(double &S, 
				size_t &n, 
				const double* const &w, 
				const double* const &r, 
				double &R, 
				double &V, 
				ostream& out);


