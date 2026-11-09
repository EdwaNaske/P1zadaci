//Napisati program koji omogućuje korisniku unos jedne od 4 numeričke opcije :
//1 - Odabir ove opcije primorava korisnika na unos dvije cjelobrojne vrijednosti m i n,
// pri čemu mora biti ispoštovano ograničenje(0 < m < n).Program treba ispisati sve proste brojeve u intervalu[m, n],
// čije su cifre sortirane uzlaznim redoslijedom.
//	2 - Odabir ove opcije primorava korisnika na unos jedne cjelobrojne vrijednosti n, za koju važi ograničenje n≥10.
// Program treba da ispiše sve brojeve u intervalu[10, n] za koje važi da su prva i zadnja cifra u broju iste.
//	3 - Odabir ove opcije primorava korisnika na unos jedne cjelobrojne vrijednosti n, za koju važi ograničenje 200.
// Program treba da ispiše sve brojeve u intervalu[10, n], čije su sve cifre jednake.
//	4 - Odabir ove opcije označava izlaz iz programa.
//	Ukoliko korisnik odabere opciju koja nije niti jedna od 4 navedene,
// potrebno je ispisati poruku za nevalidan unos i nastaviti sa izvršenjem programa
// (tj.ponovo prikazati menu sa svim opcijama)
#include <iostream>
using namespace std;
bool IsProst(int);
bool IsUzlazan(int);
bool PrvaZadnja(int);
bool IsteCifre(int);
int main() {
	int opcija;
	bool pronadjen = false;
	do {
		cout << "==MENI==" << endl;
		cout << "1 - Prosti brojevi sa sortiranim ciframa" << endl;
		cout << "2 - Brojevi sa prvom i zadnjom cifrom istom" << endl;
		cout << "3 - Brojevi gdje su sve cifre iste" << endl;
		cout << "4 - Izlaz iz programa" << endl;
		cout << "Unesite opciju (1-4) : ";
		cin >> opcija;
		switch (opcija) {
			//******************************************************************************************
		case 1: {
			int m, n;
			do {
				cout << "Unesite m i n (0<m<n):";
				cin >> m >> n;
				if (m < 0 || n < m) {
					cout << "Niste ispostovali uslov u zagradi!!" << endl;
				}
			} while (m < 0 || n < m);
			pronadjen = false;
			cout << "Prosti brojevi uzlazni: " << endl;
			for (int i = m; i <= n; i++) {
				if (IsProst(i) && IsUzlazan(i)){
					cout << i << " ";
				pronadjen = true;
				}
			}
			if (pronadjen==false) cout << "U ovom obsegu nema takvih brojeva!";
			cout << endl << endl;
		}break;
			//********************************************************************************************
		case 2:
		{
			int n=0;
			do {
				cout << "Unesite broj n (n>=10): ";
				cin >>n;
				if (n < 10) cout << "Niste ispostavali uvijet! Pokusajte ponovo." << endl;
			} while (n < 10);
			cout << "Brojevi sa istom prvom i zadnjom cifrom su:" << endl;
			for (int i = 10; i <= n; i++) {
				if (PrvaZadnja(i)) cout << i << " ";
			}	
			cout << endl << endl;
		}break;
		//********************************************************************************************
		case 3:
		{
			int n = 0;
			do {
				cout << "Unesite broj n (n>=200): ";
				cin >> n;
				if (n < 200) cout << "Niste ispostavali uvijet! Pokusajte ponovo." << endl;
			} while (n < 200);
			cout << "Brojevi sa svim istim ciframa:" << endl;
			for (int i = 10; i <= n; i++) {
				if (IsteCifre(i)) cout << i << ' ';
			}
			cout << endl << endl;
		}	break;
		//********************************************************************************************
		case 4: {
			cout << "Kraj programa!" << endl;
			break;
		default:
			cout << "Nepostojeca opcija! Pokusajte ponovo." << endl << endl;
		}break;
	   //********************************************************************************************
	}
	} while (opcija!=4);
return 0;
}
bool IsProst(int broj) {
	if (broj <= 1) return false;
	for (int i = 2; i * i <= broj; i++) {
		if (broj % i == 0) {
			return false;
		}
	}
	return true;
}
bool IsUzlazan(int broj) {
	if (broj < 10) return true;
	int zc = broj % 10;
	broj = broj / 10;
	do {
		int tc = broj % 10;
		if (tc >= zc) return false;
		tc = zc;
		broj = broj / 10;
	} while (broj != 0);
	return true;
}
bool PrvaZadnja(int broj){
	int ZadnjaC = broj % 10;
	int pc=broj;
	while (pc >= 10){
		pc /= 10;
	}
	return pc == ZadnjaC;
}
bool IsteCifre(int broj) {
	int zc;
	int rzc= broj%10;
	broj = broj / 10;
	do {
		zc = broj % 10;
		if (zc != rzc) return false;
		broj = broj / 10;
	} while (broj!=0);
	return true;
}