#pragma once
#include <string>
#include "MyNumberException.h"
#include "MyInputStringException.h"
using namespace std;

class Validare {
public:
	Validare() {};
	~Validare() {};

	void option(string option) {
		if (option != ".csv" && option != ".txt")
			throw MyInputStringException("Fisierul poate fi ori TXT or CSV \n");
	}

	void option_out(string option) {
		if (option != "nu" && option != "da")
			throw  MyInputStringException("Ati introdus o optiune invalida \n");
	}

	template<class T>
	void exception_cumparare(T* a, int numar) {
		if (numar <= 0)
			throw MyNumberException("Numarul de bilete trebuie sa fie pozitiv nenul \n");

		if (a->getNrLocuriDisponibile() < numar)
			throw MyNumberException("Nu sunt atatea bilete disponibile \n");
	}

};