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

    // Dodaæ opcjê, ¿e jeœli jedn¹ wartoœæ ju¿ przeliczy³, to nie bêdzie liczy³ znowu
    for (int i = 0; i < n; i++) {
        value = tablica[i];
        int licznik = 0;
        // zaczynaj¹c od i zmniejszamy z³o¿onoœæ obliczeniow¹, a nie wp³ywa to na
        // wynik, bo jeœli np. 2 jest na pocz¹tku i na koñcu tablicy, to mimo ¿e na 
        // koñcu zliczy dwójkê tylko raz, to zliczy³ j¹ ju¿ poprawnie na pocz¹tku, 
        // a wynik z dwójki na koñcu tablicy nie bêdzie wrzucany do wektora, bo licznik 
        // bêdzie mniejszy
        for (int j = i; j < n; j++) {
            if (tablica[j] == value) {
                licznik += 1;
            }
        }
        if (licznik > max_licznik) {
            max_licznik = licznik;
            liczniki.clear();   // na pocz¹tku trzeba je wyczyœciæ, bo np. dla wektora
            wartosci.clear();   // {2,2,3,3,3} na pocz¹tku do wektorów zapisze nam siê
                                // dwójka z iloœci¹ powtórzeñ 2
            liczniki.push_back(licznik);
            wartosci.push_back(value);
        }
        // Sytuacja dla np. {2,2,2,3,3,3,4,5,6,6}, czyli gdzie s¹ 2 najczêœciej
        // wystêpujace wartoœci
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