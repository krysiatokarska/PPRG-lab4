#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

int main()
{
    cout << "Please enter size of the table: ";
    int n;
    cin >> n;

    while (n<0)
    {
        "Please enter a number higher than 0: ";
        cin >> n;
    }
    

    int* tablica = new int[n];
    cout << "Please enter elements of the table: ";
    for (int i = 0; i < n; i++)
    {
        cin >> tablica[i];
    }

    vector <int> liczniki;
    vector <int> wartosci;
    int value;
    int max_licznik = 0;

    // Doda� opcj�, �e je�li jedn� warto�� ju� przeliczy�, to nie b�dzie liczy� znowu
    for (int i = 0; i < n; i++) {
        value = tablica[i];
        int licznik = 0;
        // zaczynaj�c od i zmniejszamy z�o�ono�� obliczeniow�, a nie wp�ywa to na
        // wynik, bo je�li np. 2 jest na pocz�tku i na ko�cu tablicy, to mimo �e na 
        // ko�cu zliczy dw�jk� tylko raz, to zliczy� j� ju� poprawnie na pocz�tku, 
        // a wynik z dw�jki na ko�cu tablicy nie b�dzie wrzucany do wektora, bo licznik 
        // b�dzie mniejszy
        for (int j = i; j < n; j++) {
            if (tablica[j] == value) {
                licznik += 1;
            }
        }
        if (licznik > max_licznik) {
            max_licznik = licznik;
            liczniki.clear();   // na pocz�tku trzeba je wyczy�ci�, bo np. dla wektora
            wartosci.clear();   // {2,2,3,3,3} na pocz�tku do wektor�w zapisze nam si�
                                // dw�jka z ilo�ci� powt�rze� 2
            liczniki.push_back(licznik);
            wartosci.push_back(value);
        }
        // Sytuacja dla np. {2,2,2,3,3,3,4,5,6,6}, czyli gdzie s� 2 najcz�ciej
        // wyst�pujace warto�ci
        else if(licznik == max_licznik && value != wartosci[wartosci.size()-1]) {
            liczniki.push_back(licznik);
            wartosci.push_back(value);
        }
    }

    for (int i = 0; i < size(liczniki);i++) {
        cout << endl << "the most common variable, occuring in the table " <<
            liczniki[i] <<" times is " << wartosci[i];
    }

    delete[] tablica;
    return(0);
}