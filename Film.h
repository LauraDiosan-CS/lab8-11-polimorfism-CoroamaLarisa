#pragma once
#include <vector>
#include "AtractieFestival.h"
#include "string.h"

class Film : public AtractieFestival {
private:
	string titlu;
	vector<string> actori;
public:
	Film();
	Film(string titlu, vector<string> actori, string data, string loc, int nrLocuriDisponibile, int nrLocuriDejaVandute);
	Film(const Film& f);
	~Film() {};
	Film& operator=(const Film& f);
	string getTitlu();
	vector<string> getActori();
	bool operator==(const Film& f);
	void setTitlu(string titlu);
	void setActori(vector<string> actori);
	string getCsvString();
	Film* clone();
	string toString();
	void getCsvObject(vector<string> data);
	string getForHTML(int i);
	void getTXTObject(vector<string> informatii);

};