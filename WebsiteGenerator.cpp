#include <iostream>
#include <fstream>
#include "CustomizationOptions.h"
#include "FileOut.h"
#include "PropertiesGenerator.h"
#include <windows.h>

using namespace std;

void writeWebsite(CustomizationOptions& customizationOptions) {
	FileOut fileOut;
	// html
	fileOut.writeHtmlOption("html", { {"lang", "pl"} }, false);
	fileOut.writeHtmlOption("head", {}, false);
	fileOut.writeHtmlOption("meta", { {"charset", "utf-8"} }, false, "", 1);
	fileOut.writeHtmlOption("meta", { {"name", "viewport"}, {"content", "width=device-width, initial-scale=1"} }, false, "", 1);
	fileOut.writeHtmlOption("link", { {"rel", "stylesheet"}, {"type", "text/css"}, {"href", "style.css"}}, false, "", 1);
	fileOut.writeHtmlOption("title", {}, true, customizationOptions.siteName, 1);
	fileOut.writeClosingTag("head");
	fileOut.writeHtmlOption("body", {}, false, "");
	fileOut.writeHtmlOption("header", { {"class", "header"} }, true, customizationOptions.siteName, 1);
	fileOut.writeHtmlOption("table", { {"class", "table"} }, false, "", 1);
	fileOut.writeHtmlOption("tr", {}, false, "", 2);
	for (int i = 0; i < customizationOptions.colNum; i++) {
		fileOut.writeHtmlOption("td", { {"class", "col" + to_string(i+1)} }, true, customizationOptions.colContent[i], 3);
	}
	fileOut.writeClosingTag("tr", 2);
	fileOut.writeClosingTag("table", 1);
	fileOut.writeClosingTag("body", 0);
	fileOut.writeHtmlOption("footer", { {"class", "footer"} }, true, customizationOptions.footerText);
	fileOut.writeClosingTag("html", 0);
}


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

