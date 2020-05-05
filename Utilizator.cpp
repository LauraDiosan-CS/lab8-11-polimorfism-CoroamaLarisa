#include "Utilizator.h"

Utilizator::Utilizator()
{
	this->nume = "";
	this->parola = "";
}

Utilizator::Utilizator(string nume, string parola)
{
	this->nume = nume;
	this->parola = parola;
}

Utilizator::Utilizator(const Utilizator& u)
{
	this->nume = u.nume;
	this->parola = u.parola;
}

Utilizator* Utilizator::clone()
{
	Utilizator* c = new Utilizator();

	c->setNume(this->nume);
	c->setParola(this->parola);

	return c;
}

Utilizator& Utilizator::operator=(const Utilizator& u)
{
	this->nume = u.nume;
	this->parola = u.parola;

	return *this;
}

string Utilizator::getNume()
{
	return this->nume;
}

string Utilizator::getParola()
{
	return this->parola;
}

void Utilizator::setNume(string nume)
{
	this->nume = nume;
}

void Utilizator::setParola(string parola)
{
	this->parola = parola;
}

bool Utilizator::operator==(const Utilizator& u)
{
	return this->nume == u.nume && this->parola == u.parola;
}

void Utilizator::getCsvObject(vector<string> info)
{
	this->nume = info[0];
	this->parola = info[1];
	this->parola.erase(0, 1);
}

string Utilizator::getCsvString()
{
	string csv;

	csv.append(this->nume);
	csv.append(", ");
	csv.append(this->parola);

	return csv;
}

ostream& operator<<(ostream& os, const Utilizator& u)
{
	os << u.nume << ", " << u.parola << "\n";
	return os;
}

istream& operator>>(istream& is, Utilizator& u)
{
	is >> u.nume >> u.parola;
	return is;
}
