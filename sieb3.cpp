
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std; 

struct Sieb{
	int p; //  Anzahl der Primzahlen im Intervall
	int s; // Anzahl an Streichungen
}; typedef struct Sieb Sieb; 


/*Schreiben Sie eine C/C++-Funktion, die für ein als Funktionsargument übergebenes beliebiges N
sowohl P als auch S ermittelt und beide als Funktionswerte zurückliefert.
*/

int potenz(int basis, int exponent){
	int ergebnis = 1; 
	for(int i = 0; i < exponent; i++){
		ergebnis = ergebnis*basis;  
	}

	return ergebnis; 
}

//Basisverfahren: Es werden alle Vielfachen einer Primzahl markiert, die größer oder gleich deren Quadrat sind.
Sieb funktionSieb(int N){
	Sieb _sieb;
	_sieb.s = 0, _sieb.p = 0;
	int feld_s[N+1];  
	int counter = 2;  

	//Feld wird ertsellt
	for(int i = 2; i<N+1; i++){
		feld_s[i] = 0;   
	}

	for(int pz = 2; (pz*pz)<=N+1; pz++){ 
		
		if(feld_s[pz] != 1){ // nicht gestrichen, ist Primzahl 
			//_sieb.p++; 

			for(int j = pz*pz; j<N+1; j+=pz){ // Streichungen beginnen bei dem Quadrat der Primzahl
				//cout << j << " wird gestrichen" << endl; 
				feld_s[j] = 1; //Vielfache werden gestrichen 
				_sieb.s++; 

			}

		}
	}
	
	//Hier wird die Anzahl der Primzahlen im Feld definiert
	for(int i =2; i<N+1; i++){ 
		if(feld_s[i] != 1){
			_sieb.p++; 
		}

	}

	return _sieb; 
}

int main(){
	int N; 
	cout << "Der Sieb des Erastotenes" << endl; 
	Sieb _sieb; 


	cout << setw(8) << "N"; 
	cout << setw(8) << "S"; 
	cout << setw(8) << "P";
	cout << "\n"; 
	cout << "------------------------";
	cout << "\n";
	
	ofstream fout("eras.dat");
	
	for(int i= 2; i<= 20; i++){
		N = potenz(2, i); 
		_sieb = funktionSieb(N); 
		//cout << setfill('-');
		cout << right <<setw(8) << N; 
		cout << right << setw(8) << _sieb.s ; 
		cout << right << setw(8) << _sieb.p;
		fout << right <<setw(8) << N; 
		fout << right << setw(8) << _sieb.s ; 
		fout << right << setw(8) << _sieb.p; 
		
		cout << "\n"; 
	}

	fout.close(); 
	
}
