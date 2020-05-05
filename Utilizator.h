#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <ostream>
using namespace std;
class Utilizator {
private:
	string nume;
	string parola;

public:

	Utilizator();

	Utilizator(string nume, string parola);

	Utilizator(const Utilizator& u);

	Utilizator* clone();

	Utilizator& operator=(const Utilizator& u);

	string getNume();

	string getParola();

	void setNume(string nume);

	void setParola(string parola);

	friend ostream& operator<<(ostream& os, const Utilizator& u);

	friend istream& operator>>(istream& is, Utilizator& u);

	bool operator==(const Utilizator& u);

	void getCsvObject(vector<string> info);

	string getCsvString();

};