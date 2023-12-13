#include <iostream>
#include <fstream>
#include "CustomizationOptions.h"
#include "FileOut.h"
#include "PropertiesGenerator.h"
#include <windows.h>

using namespace std;

int main(){
	// obsluga polskich znakow
	SetConsoleOutputCP(65001);

	cout << "Chcesz wczytać dane z pliku czy wprowadzić je ręcznie? (1 - plik, 2 - ręcznie)" << endl;
	int choice;
	cin >> choice;
	ifstream plik;


	if (choice == 2) { //ręcznie
		new PropertiesGenerator();
		plik.open("WG-Temp.txt");
	}else if (choice == 1) { // z pliku
		plik.open("dane.txt");
	}
	else {
		cout << "Niepoprawny wybór" << endl;
		return 0;
	}

	if (!plik) {
		throw runtime_error("Błąd otwierania pliku");
		return 0;
	}
	CustomizationOptions customizationOptions = CustomizationOptions(plik);


	system("PAUSE");
	if (choice == 2) system("del /q WG-Temp.txt");
	plik.close();

	return 0;
}

