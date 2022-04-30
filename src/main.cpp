#include <iostream>
#include <fstream>
#include "downloader.hpp"
#include "viewer.hpp"
#include "nlohmann/json.hpp"

using std::cout;
using nlohmann::json;

int main(int argv, char** argc)
{
	Viewer viewer(true);
	
	if (argv < 2) {
		cout << "Zadajte nazov ovocia !" << std::endl;
		cout << "./bot orange" << std::endl;
		return 1;
	}

	// Inicializuj dynamicke pole podla poctu argumentov
	auto fruits = new std::string[argv - 1];

	// Uloz ovocie do pola
	for (int i = 1; i < argv; i++) {
		fruits[i - 1] = argc[i];
	}

	for (int i = 0; i < (argv - 1); i++) {
		Downloader dl(std::string("https://www.fruityvice.com/api/fruit/") + std::string(fruits[i]));
	
		 viewer.show(dl);
	}

	return 0;
}