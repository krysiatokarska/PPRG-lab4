#include<iostream>
#include <math.h>
#include "Funkcje.h"

using namespace std;



void print2DArray(int array[n][n]){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
}

void deklaracjaTablicy() {
	int tab[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j == 0) tab[i][j] = i;
			else if (j == 1) tab[i][j] = 2 * tab[i][0];
			else if (j == 2 || j == 3) tab[i][j] = pow(tab[i][0], j);
			else if (j == 4) tab[i][j] = i - j;
			else tab[i][j] = 0;
		}
	}
	print2DArray(tab);
}
