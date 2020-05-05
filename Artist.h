#pragma once
#include "AtractieFestival.h"
#include <vector>
class Artist : public AtractieFestival {
private:
	string nume;
public:
	Artist();
	Artist(string nume, string data, string loc, int nrLocuriDisponibile, int nrLocuriDejaVandute);
	Artist(const Artist& a);
	~Artist() {};
	Artist& operator=(const Artist& a);
	bool operator==(const Artist& a);
	string getCsvString();
	void setNume(string nume);
	void getCsvObject(vector<string> informatii);
	string getNume();
	string getForHTML(int i);
	void getTXTObject(vector<string> informatii);
	Artist* clone();
	friend ostream& operator<<(ostream& os, const Artist& a);
	friend istream& operator>>(istream& is, Artist& a);
	string toString();
};