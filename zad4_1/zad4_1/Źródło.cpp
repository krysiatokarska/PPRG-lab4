// zad4.1 ZnajdŸ najwiêkszy element danej tablicy liczb ca³kowitych. 
// Liczbê elementów tablicy i ich wartoœci pobierz od u¿ytkownika

#include <iostream>
using namespace std;


int main() {
	// Program pobiera liczbê, i je¿eli jest mniejsza od 1 wyœwietla komunikat i 
	// prosi o ponowne jej podanie.
	int n;
	cout << "Please enter a number of elements in the table: ";
	cin >> n;
	while (n < 1) {
		cout << endl << "Please enter a number higher than 0: ";
		cin >> n;
	}

	// Tablica zapisywana jest przez wskaŸnik, ¿eby mo¿liwe by³o podanie jej 
	// wymiaru przez u¿ytkownika. Bez tego by³yby b³êdy.
	// Program pobiera od u¿ytkownika elementy tabeli
	int* tablica = new int[n];
	cout << endl << "Please enter the table elements: ";
	for (int i = 0; i < n; i++) {
		cin >> tablica[i];
	}

	// Program szuka najwiêkszej wartoœci tabeli. (jeœli iteracja by³aby od 0 te¿ 
	// by³oby dobrze
	int max = tablica[0];
	for (int i = 0; i < n; i++) {
		if (max < tablica[i]) {
			max = tablica[i];
		}
	}
	cout << endl << "The highest number in this table is: " << max;
	
	// Jeœli na pocz¹tku zarezerwowa³am pamiêæ przez new, to na koñcu musi byæ delete
	delete[] tablica;

	return 0;
}

