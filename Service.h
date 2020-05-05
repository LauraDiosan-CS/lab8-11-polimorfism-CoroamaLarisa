#pragma once
#include "Artist.h"
#include "RepoPoli.h"
#include "Utilizator.h"
#include "Film.h"
#include "RepoCSV.h"
#include "RepoTXT.h"
#include "Validare.h"

class Service{
private:

	RepoPoli* repo[1];
	Validare e;

public:

	Service();

	Service(const Service& s_a);

	Service& operator=(const Service& s_a);

	~Service() {
		delete this->repo[0];
	};

	void setRepo(string option);

	vector<AtractieFestival*> getAll() {
		return repo[0]->getAll();
	}

	vector<AtractieFestival*> getAtractieCareAreSpectacolInZiuaCutare(string initial_cautare, string zi);

	Artist* getArtistBasedOnName(string name);

	void cumparare_bilet_artist(string nume_artist, string nume, int numar);

	Film* getFilmBasedOnName(string titlu);

	void cumparare_bilet_film(string nume_film, string nume, int numar);

	void delArtist(string nume, string data, string loc, int nrdisp, int nrvandute);
	void addArtist(string nume, string data, string loc, int nrdisp, int nrvandute);
	void delFilm(string titlu, vector<string> actori, string data, string loc, int nrdisp, int nrvandute);
	void addFilm(string titlu, vector<string> actori, string data, string loc, int nrdisp, int nrvandute);

};