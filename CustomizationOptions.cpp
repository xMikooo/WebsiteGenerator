#include "CustomizationOptions.h"
#include <iostream>
#include <istream>

#include <vector>

using namespace std;

CustomizationOptions::CustomizationOptions()
{
}

CustomizationOptions::CustomizationOptions(istream &strumien)
{
	strumien >> bgColor;


	strumien >> bgPath;

	string bgOptions;
	if (bgPath == "BRAK") {
		bgOptions = "NIE"; //jesli nie ma sciezki do obrazka to nie ma tez opcji
	}else {
		bgPictureEnabled = true;
	}
	strumien >> bgOptions;

	if (bgOptions == "NIE") {
		bgPictureEnabled = false;
		bgVerticalRepeat = false;
		bgHorizontalRepeat = false;
		bgStretch = false;
		bgFixed = false;
	}
	else {
		string delimiter = ";"; //czym oddzielamy opcje
		string token = bgOptions.substr(0, bgOptions.find(delimiter));
		if (token == "RY_TAK") {
			bgHorizontalRepeat = true;
		} else if (token == "RY_NIE") {
			bgHorizontalRepeat = false;
		}
		bgOptions.erase(0, bgOptions.find(delimiter) + delimiter.length());
		token = bgOptions.substr(0, bgOptions.find(delimiter));
		if (token == "RX_TAK") {
			bgVerticalRepeat = true;
		}
		else if (token == "RX_NIE") {
			bgVerticalRepeat = false;
		}
		bgOptions.erase(0, bgOptions.find(delimiter) + delimiter.length());
		token = bgOptions.substr(0, bgOptions.find(delimiter));
		if (token == "ROZ_TAK") {
			bgStretch = true;
		}
		else if (token == "ROZ_NIE") {
			bgStretch = false;
		}
		bgOptions.erase(0, bgOptions.find(delimiter) + delimiter.length());
		token = bgOptions.substr(0, bgOptions.find(delimiter));
		if (token == "FIX_TAK") {
			bgFixed = true;
		}
		else if (token == "FIX_NIE") {
			bgFixed = false;
		}
	}


	strumien.ignore(); //ignorujemy znak nowej linii aby getline dzialalo poprawnie
	getline(strumien, siteName); //uzywamy getline bo nazwa strony moze zawierac spacje

	strumien >> nameSize;

	strumien >> nameColor;


	strumien >> colNum;
	//zmieniamy rozmiar vectorow na podstawie liczby kolumn
	colContent.resize(colNum);
	colFontSize.resize(colNum);
	colFontColor.resize(colNum);
	colBgColor.resize(colNum);
	colBgPath.resize(colNum);
	colBgPictureEnabled.resize(colNum);
	colVerticalRepeat.resize(colNum);
	colHorizontalRepeat.resize(colNum);
	colStretch.resize(colNum);
	colFixed.resize(colNum);
	colRoundedCornersRadius.resize(colNum);


	strumien.ignore(); //ignorujemy znak nowej linii aby getline dzialalo poprawnie
	string colsContent; //tymczasowa zmienna do wczytywania zawartosci kolumn
	getline(strumien, colsContent); //uzywamy getline bo zawartosc moze zawierac spacje
	string delimiter = ";"; //czym oddzielamy zawartosci kolumn
	string token;
	for (int i = 0; i < colNum; i++) {
		token = colsContent.substr(0, colsContent.find(delimiter));
		colContent[i] = token;
		//zamiana \n na <br> aby nowa linia w kolumnie byla widoczna

		colsContent.erase(0, colsContent.find(delimiter) + delimiter.length()); //usuwamy juz wczytana zawartosc
	}

	// wczytac rozmiary czcionek w poszczegolnych kolumnach oddzielne przestrumienkami
	string colFontSizes;
	strumien >> colFontSizes;
	delimiter = ";"; //czym oddzielamy rozmiary czcionek kolumn
	for (int i = 0; i < colNum; i++) {
		token = colFontSizes.substr(0, colFontSizes.find(delimiter));
		colFontSize[i] = stoi(token); //stoi konwertuje string na int
		colFontSizes.erase(0, colFontSizes.find(delimiter) + delimiter.length());
	}
	

	string colFontColors;
	strumien >> colFontColors;
	delimiter = ";"; //czym oddzielamy kolory czcionek kolumn
	for (int i = 0; i < colNum; i++) {
		token = colFontColors.substr(0, colFontColors.find(delimiter));
		colFontColor[i] = token;
		colFontColors.erase(0, colFontColors.find(delimiter) + delimiter.length());
	}

	string colBgColors;
	strumien >> colBgColors;
	delimiter = ";"; //czym oddzielamy kolory tla kolumn
	for (int i = 0; i < colNum; i++) {
		token = colBgColors.substr(0, colBgColors.find(delimiter));
		colBgColor[i] = token;
		colBgColors.erase(0, colBgColors.find(delimiter) + delimiter.length());
	}

	string colBgPaths;
	strumien >> colBgPaths;
	delimiter = ";"; //czym oddzielamy sciezki do obrazkow tla kolumn
	for (int i = 0; i < colNum; i++) {
		token = colBgPaths.substr(0, colBgPaths.find(delimiter));
		colBgPath[i] = token;
		colBgPaths.erase(0, colBgPaths.find(delimiter) + delimiter.length());
	}

	for (int i = 0; i < colNum; i++) {
		if (colBgPath[i] == "BRAK") {
			colBgPictureEnabled[i] = false;
		}
		else {
			colBgPictureEnabled[i] = true;
		}
	}
	
	string colOptions;
	strumien >> colOptions;
	string optionsDelimiter = "-"; //czym oddzielamy poszczeolne opcje kolumn
	//kod odpowiedzialny za rozdzielenie opcji poszczegolnych kolumn
	vector<string> colOptionsVector;
	colOptionsVector.resize(colNum);
	for (int i = 0; i < colNum; i++) {
		token = colOptions.substr(0, colOptions.find(optionsDelimiter));
		colOptionsVector[i] = token;
		colOptions.erase(0, colOptions.find(optionsDelimiter) + optionsDelimiter.length());
	}
	//kod odpowiedzialny za rozdzielenie opcji poszczegolnych kolumn na poszczegolne opcje
	for (int i = 0; i < colNum; i++) {
		if (colOptionsVector[i] == "NIE") {
			colBgPictureEnabled[i] = false;
			colVerticalRepeat[i] = false;
			colHorizontalRepeat[i] = false;
			colStretch[i] = false;
			colFixed[i] = false;
		}
		else {
			delimiter = ";"; //czym oddzielamy opcje
			string token = colOptionsVector[i].substr(0, colOptionsVector[i].find(delimiter));
			if (token == "RY_TAK") {
				colHorizontalRepeat[i] = true;
			}
			else if (token == "RY_NIE") {
				colHorizontalRepeat[i] = false;
			}
			colOptionsVector[i].erase(0, colOptionsVector[i].find(delimiter) + delimiter.length());
			token = colOptionsVector[i].substr(0, colOptionsVector[i].find(delimiter));
			if (token == "RX_TAK") {
				colVerticalRepeat[i] = true;
			}
			else if (token == "RX_NIE") {
				colVerticalRepeat[i] = false;
			}
			colOptionsVector[i].erase(0, colOptionsVector[i].find(delimiter) + delimiter.length());
			token = colOptionsVector[i].substr(0, colOptionsVector[i].find(delimiter));
			if (token == "ROZ_TAK") {
				colStretch[i] = true;
			}
			else if (token == "ROZ_NIE") {
				colStretch[i] = false;
			}
			colOptionsVector[i].erase(0, colOptionsVector[i].find(delimiter) + delimiter.length());
			token = colOptionsVector[i].substr(0, colOptionsVector[i].find(delimiter));
			if (token == "FIX_TAK") {
				colFixed[i] = true;
			}
			else if (token == "FIX_NIE") {
				colFixed[i] = false;
			}
		}
	}

	string roundedCornersRadius;
	strumien >> roundedCornersRadius;
	delimiter = ";"; //czym oddzielamy kolory tla kolumn
	for (int i = 0; i < colNum; i++) {
		token = roundedCornersRadius.substr(0, colBgColors.find(delimiter));
		colRoundedCornersRadius[i] = stoi(token);
		roundedCornersRadius.erase(0, roundedCornersRadius.find(delimiter) + delimiter.length());
	}


	strumien >> footerBgColor;

	strumien >> footerBgPath;

	string footerBgOptions;
	strumien >> footerBgOptions;

	if (footerBgOptions == "NIE") {
		footerBgPictureEnabled = false;
	}
	else
	{
		footerBgPictureEnabled = true;
		delimiter = ";"; //czym oddzielamy opcje
		token = footerBgOptions.substr(0, footerBgOptions.find(delimiter));
		if (token == "RY_TAK") {
			footerBgHorizontalRepeat = true;
		}
		else if (token == "RY_NIE") {
			footerBgHorizontalRepeat = false;
		}
		footerBgOptions.erase(0, footerBgOptions.find(delimiter) + delimiter.length());
		token = footerBgOptions.substr(0, footerBgOptions.find(delimiter));
		if (token == "RX_TAK") {
			footerBgVerticalRepeat = true;
		}
		else if (token == "RX_NIE") {
			footerBgVerticalRepeat = false;
		}
		footerBgOptions.erase(0, footerBgOptions.find(delimiter) + delimiter.length());
		token = footerBgOptions.substr(0, footerBgOptions.find(delimiter));
		if (token == "ROZ_TAK") {
			footerBgStretch = true;
		}
		else if (token == "ROZ_NIE") {
			footerBgStretch = false;
		}
		footerBgOptions.erase(0, footerBgOptions.find(delimiter) + delimiter.length());
		token = footerBgOptions.substr(0, footerBgOptions.find(delimiter));
		if (token == "FIX_TAK") {
			footerBgFixed = true;
		}
		else if (token == "FIX_NIE") {
			footerBgFixed = false;
		}
	}
	strumien >> footerFontColor;

	strumien >> footerFontSize;

	strumien.ignore(); //ignorujemy znak nowej linii aby getline dzialalo poprawnie
	getline(strumien, footerText); //uzywamy getline bo zawartosc moze zawierac spacje

}
