

#include <iostream>
using namespace std;
bool isPalindrom(int);
int DecToBin(int);
int sum(int);
int main(){
	int n;
	do {
		cout << "Unesite broj(n>=2) ";
		cin >> n;
		if (n < 2) {
			cout << "Niste ispostavali uslov!"<<endl;
		}

	} while (n < 2);
	cout << endl;
	for (int i = 2; i <= n; i++) {
		if(isPalindrom(DecToBin(i))){
		cout << i << ". => " << DecToBin(i)<<". a suma cifara je: "<<sum(DecToBin(i))<<endl;
		}
	}
} 
int DecToBin(int broj) {
	int ostatak=0;
	int index=1;
	int binarni=0;
	while (broj > 0) {
		ostatak = broj % 2;
		binarni += index * ostatak;
		index *= 10;
		broj /= 2;
	}
	return binarni;
}
bool isPalindrom(int broj) {
	int zc=0;
	int obrnut=0;
	int org = broj;
	do {
		zc= broj % 10;
		obrnut = obrnut * 10 + zc;
		broj /= 10;
	} while (broj != 0);
	return obrnut==org ;
}
int sum(int x) {
	int suma = 0;
	int zc = 0;
	do {
		zc = x % 10;
		suma = suma + zc;
		x /= 10;
	} while (x != 0);
	return suma;
}

