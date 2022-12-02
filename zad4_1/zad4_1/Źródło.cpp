// zad4.1 Znajd� najwi�kszy element danej tablicy liczb ca�kowitych. 
// Liczb� element�w tablicy i ich warto�ci pobierz od u�ytkownika

#include <iostream>
using namespace std;


int main() {
	// Program pobiera liczb�, i je�eli jest mniejsza od 1 wy�wietla komunikat i 
	// prosi o ponowne jej podanie.
	int n;
	cout << "Please enter a number of elements in the table: ";
	cin >> n;
	while (n < 1) {
		cout << endl << "Please enter a number higher than 0: ";
		cin >> n;
	}

	// Tablica zapisywana jest przez wska�nik, �eby mo�liwe by�o podanie jej 
	// wymiaru przez u�ytkownika. Bez tego by�yby b��dy.
	// Program pobiera od u�ytkownika elementy tabeli
	int* tablica = new int[n];
	cout << endl << "Please enter the table elements: ";
	for (int i = 0; i < n; i++) {
		cin >> tablica[i];
	}

	// Program szuka najwi�kszej warto�ci tabeli. (je�li iteracja by�aby od 0 te� 
	// by�oby dobrze
	int max = tablica[0];
	for (int i = 0; i < n; i++) {
		if (max < tablica[i]) {
			max = tablica[i];
		}
	}
	cout << endl << "The highest number in this table is: " << max;
	
	// Je�li na pocz�tku zarezerwowa�am pami�� przez new, to na ko�cu musi by� delete
	delete[] tablica;

	return 0;
}

