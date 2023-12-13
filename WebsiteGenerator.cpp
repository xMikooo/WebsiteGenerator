#include <iostream>

using namespace std;

int main(){
	// obsluga polskich znakow
	SetConsoleOutputCP(65001);

	cout << "Chcesz wczytać dane z pliku czy wprowadzić je ręcznie? (1 - plik, 2 - ręcznie)" << endl;
	int choice;
	cin >> choice;
	ifstream plik;


	if (choice == 2) { //ręcznie
		cout << "Ładowanie ręcznie"
	}else if (choice == 1) { // z pliku
		cout << "Ładowanie z pliku"
	}
	else {
		cout << "Niepoprawny wybór" << endl;
		return 0;
	}


	return 0;
}

