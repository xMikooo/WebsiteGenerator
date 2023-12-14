#include "PropertiesGenerator.h"
#include <iostream>
#include <fstream>


using namespace std;

ofstream outProperties;

PropertiesGenerator::PropertiesGenerator()
{

	outProperties.open("WG-Temp.txt", ios_base::trunc);
	if (!outProperties) {
		throw runtime_error("Błąd otwierania pliku");
		delete this;
	}
	string option;
	cout << "Wpisz kolor tła strony (w formacie #RRGGBB): ";
	cin >> option;
	outProperties << option << endl;

	cout << "Wpisz ścieżkę do obrazka tła strony (BRAK w przypadku braku tła): ";
	cin >> option;
	for (int i = 0; i < option.length(); i++) {
		option[i] = toupper(option[i]);
	}
	outProperties << option << endl;

	bool bgOption;

	if (option != "BRAK") {
		cout << "Czy obrazek tła strony ma się powtarzać w pionie? (1 - tak, 0 - nie): ";
		cin >> bgOption;
		outProperties << (bgOption ? "RY_TAK;" : "RY_NIE;");

		cout << "Czy obrazek tła strony ma się powtarzać w poziomie? (1 - tak, 0 - nie): ";
		cin >> bgOption;
		outProperties << (bgOption ? "RX_TAK;" : "RX_NIE;");

		cout << "Czy obrazek tła strony ma się rozciągać? (1 - tak, 0 - nie): ";
		cin >> bgOption;
		outProperties << (bgOption ? "ROZ_TAK;" : "ROZ_NIE;");

		cout << "Czy obrazek tła strony ma być nieruchomy? (1 - tak, 0 - nie): ";
		cin >> bgOption;
		outProperties << (bgOption ? "FIX_TAK" : "FIX_NIE") << endl;
	} else {
		outProperties << "NIE" << endl;
	}

	cout << "Wpisz tytuł strony: ";
	//uzywamy getline bo inaczej nie pobierze calej linii
	cin.ignore();
	getline(cin, option);
	outProperties << option << endl;

	cout << "Wpisz rozmiar czcionki tytułu strony: ";
	cin >> option;
	outProperties << option << endl;

	cout << "Wpisz kolor czcionki tytułu strony (w formacie #RRGGBB): ";
	cin >> option;
	outProperties << option << endl;

	int iloscKolumn;
	cout << "Wpisz ilosc kolumn (1-4): ";
	cin >> iloscKolumn;
	outProperties << iloscKolumn << endl;

	cin.ignore();
	for (int i = 0; i < iloscKolumn; i++) {
		cout << "Wpisz treść kolumny " << i + 1 << " (<br> = nowa linijka): ";
		getline(cin, option);
		outProperties << option;
		if ((iloscKolumn - 1) != i) {
			outProperties << ";";
		}
		else {
			outProperties << endl;
		}
	}

	for (int i = 0; i < iloscKolumn; i++) {
		cout << "Wpisz rozmiar czcionki kolumny " << i + 1 << ": ";
		cin >> option;
		outProperties << option;
		if ((iloscKolumn - 1) != i) {
			outProperties << ";";
		}
		else {
			outProperties << endl;
		}
	}

	for (int i = 0; i < iloscKolumn; i++) {
		cout << "Wpisz kolor czcionki kolumny " << i + 1 << " (w formacie #RRGGBB): ";
		cin >> option;
		outProperties << option;
		if ((iloscKolumn - 1) != i) {
			outProperties << ";";
		}
		else {
			outProperties << endl;
		}
	}

	for (int i = 0; i < iloscKolumn; i++) {
		cout << "Wpisz kolor tła kolumny " << i + 1 << " (w formacie #RRGGBB): ";
		cin >> option;
		outProperties << option;
		if ((iloscKolumn - 1) != i) {
			outProperties << ";";
		}
		else {
			outProperties << endl;
		}
	}
	bool bgEnabled[4]{ 0 };
	for (int i = 0; i < iloscKolumn; i++) {
		cout << "Wpisz ścieżkę do obrazka tła kolumny " << i + 1 << " (BRAK w przypadku braku tła): ";
		cin >> option;
		for (int i = 0; i < option.length(); i++) {
			option[i] = toupper(option[i]);
		}
		outProperties << option;
		if (option != "BRAK") {
			bgEnabled[i] = true;
		}
		if ((iloscKolumn - 1) != i) {
			outProperties << ";";
		}
		else {
			outProperties << endl;
		}
	}

	for (int i = 0; i < iloscKolumn; i++) {
		if (bgEnabled[i]) {
			cout << "Czy obrazek tła kolumny " << i + 1 << " ma sie powtarzać w pionie? (1 - tak, 0 - nie): ";
			cin >> bgOption;
			outProperties << (bgOption ? "RY_TAK;" : "RY_NIE;");
			cout << "Czy obrazek tła kolumny " << i + 1 << " ma sie powtarzać w poziomie? (1 - tak, 0 - nie): ";
			cin >> bgOption;
			outProperties << (bgOption ? "RX_TAK;" : "RX_NIE;");
			cout << "Czy obrazek tła kolumny " << i + 1 << " ma sie rozciągać? (1 - tak, 0 - nie): ";
			cin >> bgOption;
			outProperties << (bgOption ? "ROZ_TAK;" : "ROZ_NIE;");
			cout << "Czy obrazek tła kolumny " << i + 1 << " ma być nieruchomy? (1 - tak, 0 - nie): ";
			cin >> bgOption;
			outProperties << (bgOption ? "FIX_TAK" : "FIX_NIE");
		}
		else {
			outProperties << "NIE";
		}
		if ((iloscKolumn - 1) != i) {
			outProperties << "-";
		}
		else {
			outProperties << endl;
		}
	}

	for (int i = 0; i < iloscKolumn; i++) {
		cout << "Wpisz promień zaokraglenia kolumny " << i + 1 << " (w px): ";
		cin >> option;
		outProperties << option;
		if ((iloscKolumn - 1) != i) {
			outProperties << ";";
		}
		else {
			outProperties << endl;
		}
	}

	cout << "Wpisz kolor tła stopki (w formacie #RRGGBB): ";
	cin >> option;
	outProperties << option << endl;

	cout << "Wpisz ścieżkę do obrazka tła stopki (BRAK w przypadku braku tła): ";
	cin >> option;
	for (int i = 0; i < option.length(); i++) {
		option[i] = toupper(option[i]);
	}
	outProperties << option << endl;

	if (option != "BRAK") {
		cout << "Czy obrazek tła stopki ma sie powtarzać w pionie? (1 - tak, 0 - nie): ";
		cin >> bgOption;
		outProperties << (bgOption ? "RY_TAK;" : "RY_NIE;");
		cout << "Czy obrazek tła stopki ma sie powtarzać w poziomie? (1 - tak, 0 - nie): ";
		cin >> bgOption;
		outProperties << (bgOption ? "RX_TAK;" : "RX_NIE;");
		cout << "Czy obrazek tła stopki ma sie rozciągać? (1 - tak, 0 - nie): ";
		cin >> bgOption;
		outProperties << (bgOption ? "ROZ_TAK;" : "ROZ_NIE;");
		cout << "Czy obrazek tła stopki ma być nieruchomy? (1 - tak, 0 - nie): ";
		cin >> bgOption;
		outProperties << (bgOption ? "FIX_TAK" : "FIX_NIE") << endl;
	}
	else {
		outProperties << "NIE" << endl;
	}

	cout << "Wpisz kolor czcionki stopki (w formacie #RRGGBB): ";
	cin >> option;
	outProperties << option << endl;

	cout << "Wpisz rozmiar czcionki stopki: ";
	cin >> option;
	outProperties << option << endl;

	cout << "Wpisz treść stopki (<br> = nowa linijka): ";
	cin.ignore();
	getline(cin, option);
	outProperties << option << endl;
	outProperties.close();

}

PropertiesGenerator::~PropertiesGenerator()
{
	if (outProperties.is_open()) outProperties.close(); //zamykamy jeżeli jeszcze nie zostało zamknięte
}
