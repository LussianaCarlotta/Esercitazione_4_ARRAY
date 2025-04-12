#include <iostream>
#include <fstream>
#include <iomanip>
#include "utils.hpp"

using namespace std;

int main() {
    double S;
    int n;
    double *w;
	double *r;


    // LETTURA DEL FILE 
    LetturaData("./data.txt", S, n, w, r);
    

    // Calcolo del tasso di rendimento
    double R = RateReturn(w, r, n);
	
	// Calcolo del valore finale dell'intero portafoglio
    double FinalValue = (1 + R) * S;


    // OUTPUT SU SCHERMO
	PrintResult(S, n, w, r, R, FinalValue, cout);


    // OUTPUT SU FILE 
    std::ofstream OutputFile("result.txt");
    if (OutputFile.fail()) 
	{
        cerr << "Errore nell'apertura di result.txt" << endl;
        return 1;
    }
    PrintResult(S, n, w, r, R, FinalValue, OutputFile);
    OutputFile.close();
	
	delete[] w;
	delete[] r;
	
    return 0;
}
