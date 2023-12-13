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

	// css
	vector<pair<string, string>> bgOptions;
	bgOptions.push_back({"background-color", customizationOptions.bgColor});
	if (customizationOptions.bgPictureEnabled) {
		bgOptions.push_back({"background-image", "url(\"" + customizationOptions.bgPath + "\")"});
		if (customizationOptions.bgVerticalRepeat && customizationOptions.bgHorizontalRepeat) {
			bgOptions.push_back({ "background-repeat", "repeat" });
		} else if (customizationOptions.bgVerticalRepeat) {
			bgOptions.push_back({ "background-repeat", "repeat-y" });
		} else if (customizationOptions.bgHorizontalRepeat) {
			bgOptions.push_back({ "background-repeat", "repeat-x" });
		}
		if (customizationOptions.bgStretch) {
			bgOptions.push_back({"background-size", "100% 100%"});
		}
		if (customizationOptions.bgFixed) {
			bgOptions.push_back({"background-attachment", "fixed"});
		}
	}
	fileOut.writeCssOption("body", bgOptions);
	fileOut.writeCssOption("table", { {"margin-left", "auto"}, {"margin-right", "auto"} });
	fileOut.writeCssOption("td", { {"border", "2px solid"} });

	fileOut.writeCssOption("header", { {"font-size", to_string(customizationOptions.nameSize)}, {"color", customizationOptions.nameColor} });
	fileOut.writeCssOption("title", { {"font-size", to_string(customizationOptions.nameSize)}, {"color", customizationOptions.nameColor} });
	for (int i = 0; i < customizationOptions.colNum; i++) {
		vector <pair<string, string>> colOptions;
		colOptions.push_back({"font-size", to_string(customizationOptions.colFontSize[i])});
		colOptions.push_back({"color", customizationOptions.colFontColor[i]});
		colOptions.push_back({"background-color", customizationOptions.colBgColor[i]});
		colOptions.push_back({ "border-radius", to_string(customizationOptions.colRoundedCornersRadius[i]) + "px" });
		if (customizationOptions.colBgPictureEnabled[i]) {
			if (customizationOptions.colVerticalRepeat[i] && customizationOptions.colHorizontalRepeat[i]) {
				colOptions.push_back({ "background-repeat", "repeat" });
			} else if (customizationOptions.colVerticalRepeat[i]) {
				colOptions.push_back({ "background-repeat", "repeat-y" });
			} else if (customizationOptions.colHorizontalRepeat[i]) {
				colOptions.push_back({ "background-repeat", "repeat-x" });
			}
			if (customizationOptions.colStretch[i]) {
				colOptions.push_back({ "background-size", "100% 100%" });
			}
			if (customizationOptions.colFixed[i]) {
				colOptions.push_back({ "background-attachment", "fixed" });
			}
			colOptions.push_back({"background-image", "url(\"" + customizationOptions.colBgPath[i] + "\")"});
		}
		fileOut.writeCssOption(".col" + to_string(i+1), colOptions);
	}
	vector<pair<string, string>> footerOptions;
	footerOptions.push_back({"font-size", to_string(customizationOptions.footerFontSize)});
	footerOptions.push_back({"color", customizationOptions.footerFontColor});
	footerOptions.push_back({"background-color", customizationOptions.footerBgColor});
	if (customizationOptions.footerBgPictureEnabled) {
		if (customizationOptions.footerBgVerticalRepeat && customizationOptions.footerBgHorizontalRepeat) {
			footerOptions.push_back({ "background-repeat", "repeat" });
		} else if (customizationOptions.footerBgVerticalRepeat) {
			footerOptions.push_back({ "background-repeat", "repeat-y" });
		} else if (customizationOptions.footerBgHorizontalRepeat) {
			footerOptions.push_back({ "background-repeat", "repeat-x" });
		}
		if (customizationOptions.footerBgStretch) {
			footerOptions.push_back({ "background-size", "100% 100%" });
		}
		if (customizationOptions.footerBgFixed) {
			footerOptions.push_back({ "background-attachment", "fixed" });
		}
		footerOptions.push_back({"background-image", "url(\"" + customizationOptions.footerBgPath + "\")"});
	}
	fileOut.writeCssOption("footer", footerOptions);

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
	writeWebsite(customizationOptions);
	
	cout << "Wygenerowano strone internetową!" << endl;
	cout << "Powstały dwa pliki: index.html oraz style.css" << endl;

	system("PAUSE");
	if (choice == 2) system("del /q WG-Temp.txt");
	plik.close();

	return 0;
}

