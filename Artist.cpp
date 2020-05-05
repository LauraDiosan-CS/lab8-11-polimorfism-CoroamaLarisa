#include "Artist.h"

Artist::Artist() : AtractieFestival()
{
}

Artist::Artist(string nume, string data, string loc, int nrLocuriDisponibile, int nrLocuriDejaVandute) : AtractieFestival(data, loc, nrLocuriDisponibile, nrLocuriDejaVandute)
{
	this->nume = nume;

}

Artist::Artist(const Artist& a) : AtractieFestival(a)
{
	this->nume = a.nume;
}

Artist& Artist::operator=(const Artist& a)
{
	AtractieFestival::operator=(a);
	this->nume = a.nume;

	return *this;
}

void Artist::getCsvObject(vector<string> informatii)
{
	this->nume = informatii[0];
	this->nume.erase(0, 1);
	this->data = informatii[1];
	this->data.erase(0, 1);
	this->loc = informatii[2];
	this->loc.erase(0, 1);
	this->nrLocuriDisponibile = stoi(informatii[3], nullptr, 10);
	this->nrLocuriDejaVandute = stoi(informatii[4], nullptr, 10);


}

string Artist::getNume()
{
	return this->nume;
}

string Artist::getForHTML(int i)
{
	string result;
	result.append("Numele artistului este: ");
	result.append(this->nume);
	result.append("<br>Detalii despre spectacol <br>");
	result.append("Locatia: ");
	result.append(this->loc);
	result.append("<br>Numarul de locuri disponibile: ");
	result.append(to_string(this->nrLocuriDisponibile));
	if (i == 1) {
		result.append("<br>Data evenimentului: ");
		result.append(this->data);
		result.append("<br>Numarul de locuri deja vandute: ");
		result.append(to_string(this->nrLocuriDejaVandute));
	}
	else {
		result.append("<br>Ora inceperii: ");
		result.append(this->getOra());
	}
	return result;
}

void Artist::getTXTObject(vector<string> informatii)
{
	this->nume = informatii[0];
	this->data = informatii[1];
	this->loc = informatii[2];
	this->nrLocuriDisponibile = stoi(informatii[3], nullptr, 10);
	this->nrLocuriDejaVandute = stoi(informatii[4], nullptr, 10);

}

Artist* Artist::clone()
{
	Artist* newArtist = new Artist();
	newArtist->setNume(this->nume);
	newArtist->setData(this->data);
	newArtist->setLoc(this->loc);
	newArtist->setNrLocuriDisponibile(this->nrLocuriDisponibile);
	newArtist->setNrLocuriDejaVandute(this->nrLocuriDejaVandute);

	return newArtist;
}

string Artist::toString()
{
	string csv;
	csv.append("A");
	csv.append("/");
	csv.append(this->nume);
	csv.append("/");
	csv.append(this->data);
	csv.append("/");
	csv.append(this->loc);
	csv.append("/");
	csv.append(to_string(this->nrLocuriDisponibile));
	csv.append("/");
	csv.append(to_string(this->nrLocuriDejaVandute));
	csv.append("\n");
	return csv;
}


string Artist::getCsvString()
{
	string csv;
	csv.append("A");
	csv.append(", ");
	csv.append(this->nume);
	csv.append(", ");
	csv.append(this->data);
	csv.append(", ");
	csv.append(this->loc);
	csv.append(", ");
	csv.append(to_string(this->nrLocuriDisponibile));
	csv.append(", ");
	csv.append(to_string(this->nrLocuriDejaVandute));
	csv.append("\n");


	return csv;

}


void Artist::setNume(string nume)
{
	this->nume = nume;
}

ostream& operator<<(ostream& os, const Artist& a)
{
	os << a.nume << "/" << AtractieFestival(a);

	return os;
}

bool Artist::operator==(const Artist& a)
{
	return this->nume == a.nume && AtractieFestival::operator==(a);
}

istream& operator>>(istream& is, Artist& a)
{
	is >> a.nume >> static_cast<AtractieFestival&>(a);

	return is;
}


