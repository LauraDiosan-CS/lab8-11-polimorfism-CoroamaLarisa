#include "Service.h"

Service::Service()
{
	this->repo[0] = 0;
}

Service::Service(const Service& s_a)
{
	this->repo[0] = s_a.repo[0];
}

Service& Service::operator=(const Service& s_a)
{
	this->repo[0] = s_a.repo[0];
	return *this;
}

void Service::setRepo(string option)
{
	int len = option.length();
	string op = option.substr(len - 4, 4);
	e.option(op);

	if (op == ".csv")
		this->repo[0] = new RepoCSV(option.c_str());
	else
		this->repo[0] = new RepoTXT(option.c_str());
}

vector<AtractieFestival*> Service::getAtractieCareAreSpectacolInZiuaCutare(string initial_cautare, string zi)
{
	vector<AtractieFestival*> atractii = this->repo[0]->getAll();
	vector<AtractieFestival*> atractii_dupa_zi;

	int n = this->repo[0]->getSize();

	string initial;
	for (int i = 0; i < n; i++) {
		initial = atractii[i]->toString().substr(0, 1);
		if (initial == initial_cautare && zi == atractii[i]->getZi()) {
			atractii_dupa_zi.push_back(this->repo[0]->getAll()[i]);
		}
	}

	return atractii_dupa_zi;
}

Artist* Service::getArtistBasedOnName(string name)
{
	int n = this->repo[0]->getSize();
	string initial;
	for (int i = 0; i < n; i++) {
		initial = this->repo[0]->getAll()[i]->toString().substr(0, 1);
		if (initial == "A" && ((Artist*)this->repo[0]->getAll()[i])->getNume() == name)
			return (Artist*)this->repo[0]->getAll()[i]->clone();
	}

	throw "Nu exista un artist cu acest nume";
}

void Service::cumparare_bilet_artist(string nume_artist, string nume, int numar)
{
	Artist* cautare = this->getArtistBasedOnName(nume_artist);

	e.exception_cumparare(cautare, numar);

	Artist newArtist(cautare->getNume(), cautare->getData(), cautare->getLoc(), cautare->getNrLocuriDisponibile() - numar, cautare->getNrLocuriDejaVandute() + numar);

	this->repo[0]->update(cautare, &newArtist);

	delete cautare;
	cautare = NULL;
}

Film* Service::getFilmBasedOnName(string titlu)
{
	int n = this->repo[0]->getSize();
	string initial;
	for (int i = 0; i < n; i++) {
		initial = this->repo[0]->getAll()[i]->toString().substr(0, 1);
		if (initial == "F" && ((Film*)this->repo[0]->getAll()[i])->getTitlu() == titlu)
			return (Film*)this->repo[0]->getAll()[i]->clone();
	}

	throw "Nu exista un film cu acest titlu";
}

void Service::cumparare_bilet_film(string nume_film, string nume, int numar)
{
	Film* cautare = this->getFilmBasedOnName(nume_film);

	e.exception_cumparare(cautare, numar);

	Film newFilm(cautare->getTitlu(), cautare->getActori(), cautare->getData(), cautare->getLoc(), cautare->getNrLocuriDisponibile() - numar, cautare->getNrLocuriDejaVandute() + numar);

	this->repo[0]->update(cautare, &newFilm);

	delete cautare;
	cautare = NULL;

}

void Service::delArtist(string nume, string data, string loc, int nrdisp, int nrvandute)
{
	AtractieFestival* a = new Artist(nume, data, loc, nrdisp, nrvandute);
	this->repo[0]->stergere(a);

	delete a;
	a = NULL;
}

void Service::addArtist(string nume, string data, string loc, int nrdisp, int nrvandute)
{
	AtractieFestival* a = new Artist(nume, data, loc, nrdisp, nrvandute);
	this->repo[0]->addElem(a);

	delete a;
	a = NULL;
}

void Service::delFilm(string titlu, vector<string> actori, string data, string loc, int nrdisp, int nrvandute)
{
	AtractieFestival* a = new Film(titlu,actori, data, loc, nrdisp, nrvandute);
	this->repo[0]->stergere(a);

	delete a;
	a = NULL;

}

void Service::addFilm(string titlu, vector<string> actori, string data, string loc, int nrdisp, int nrvandute)
{
	AtractieFestival* a = new Film(titlu, actori, data, loc, nrdisp, nrvandute);
	this->repo[0]->addElem(a);

	delete a;
	a = NULL;
}


