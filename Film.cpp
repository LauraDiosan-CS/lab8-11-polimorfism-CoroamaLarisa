#include "Film.h"
#include <boost/algorithm/string.hpp>
Film::Film()
{
}

Film::Film(string titlu, vector<string> actori, string data, string loc, int nrLocuriDisponibile, int nrLocuriDejaVandute) : AtractieFestival(data, loc, nrLocuriDisponibile, nrLocuriDejaVandute)
{
	this->titlu = titlu;
	this->actori = actori;
}

Film::Film(const Film& f) : AtractieFestival(f)
{
	this->titlu = f.titlu;
	this->actori = f.actori;

}

Film& Film::operator=(const Film& f)
{
	AtractieFestival::operator=(f);
	this->titlu = f.titlu;
	this->actori = f.actori;

	return *this;
}

string Film::getTitlu()
{
	return this->titlu;
}

vector<string> Film::getActori()
{
	return this->actori;
}

bool Film::operator==(const Film& f)
{
	return this->titlu == f.titlu && AtractieFestival::operator==(f) && this->actori == f.actori;

}

void Film::setTitlu(string titlu)
{
	this->titlu = titlu;
}

void Film::setActori(vector<string> actori)
{
	this->actori = actori;
}


string Film::getCsvString()
{
	string csv;
	csv.append("F");
	csv.append(", ");
	csv.append(this->titlu);
	csv.append(", ");

	vector<string> actori = this->actori;
	int len = actori.size();

	for (int j = 0; j < len; j++) {
		csv.append(actori[j]);
		if (j == (len - 1))
			csv.append(", ");
		else
			csv.append("; ");
	}


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

Film* Film::clone()
{
	Film* newFilm = new Film();
	newFilm->setTitlu(this->titlu);
	newFilm->setActori(this->actori);
	newFilm->setData(this->data);
	newFilm->setLoc(this->loc);
	newFilm->setNrLocuriDisponibile(this->nrLocuriDisponibile);
	newFilm->setNrLocuriDejaVandute(this->nrLocuriDejaVandute);

	return newFilm;
}

string Film::toString()
{
	string str;
	str.append("F");
	str.append("/");
	str.append(this->titlu);
	str.append("/");


	vector<string> actori = this->actori;
	int n = actori.size();
	int i = 0;


	for (i = 0; i < n; i++) {
		str.append(actori[i]);
		if (i < n - 1)
			str.append(",");

	}


	str.append("/");
	str.append(this->data);
	str.append("/");
	str.append(this->loc);
	str.append("/");
	str.append(to_string(this->nrLocuriDisponibile));
	str.append("/");
	str.append(to_string(this->nrLocuriDejaVandute));
	str.append("\n");

	return str;
}




void Film::getCsvObject(vector<string> informatii)
{
	vector<string> vec;
	vector<string> ac;
	this->titlu = informatii[0];
	this->titlu.erase(0, 1);
	string actori_s = informatii[1];

	boost::algorithm::split(vec, actori_s, boost::is_any_of(";"));

	int len = vec.size();
	for (int j = 0; j < len; j++) {
		string a = vec[j];
		a.erase(0, 1);
		this->actori.push_back(a);
	}

	this->data = informatii[2];
	this->data.erase(0, 1);
	this->loc = informatii[3];
	this->loc.erase(0, 1);
	this->nrLocuriDisponibile = stoi(informatii[4], nullptr, 10);
	this->nrLocuriDejaVandute = stoi(informatii[5], nullptr, 10);


}

string Film::getForHTML(int i)
{
	
	string result;
	result.append("Titlul filmului este: ");
	result.append(this->titlu);
	result.append("<br>Distributia: ");

	int n = this->actori.size();
	for (int i = 0; i < n; i++) {
		result.append(this->actori[i]);
		if (i < n - 1)
			result.append(", ");
	}
	result.append("<br>Detalii suplimentare despre film<br>");
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

void Film::getTXTObject(vector<string> informatii)
{
	this->titlu = informatii[0];
	string actori_s = informatii[1];
	vector<string> vec;
	vector<string> ac;
	boost::algorithm::split(vec, actori_s, boost::is_any_of(","));

	int len = vec.size();

	for (int j = 0; j < len; j++) {
		string a = vec[j];
		this->actori.push_back(a);
	}

	this->data = informatii[2];
	this->loc = informatii[3];
	this->nrLocuriDisponibile = stoi(informatii[4], nullptr, 10);
	this->nrLocuriDejaVandute = stoi(informatii[5], nullptr, 10);
}

