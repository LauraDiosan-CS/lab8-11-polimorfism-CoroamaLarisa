#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

class AtractieFestival {
protected:
	string data;
	string loc;
	int nrLocuriDisponibile;
	int nrLocuriDejaVandute;

public:

	AtractieFestival();
	AtractieFestival(string data, string loc, int nrLocuriDisponibile, int nrLocuriDejaVandute);
	AtractieFestival(const AtractieFestival& a);
	virtual ~AtractieFestival();
	string getData();
	string getLoc();
	int getNrLocuriDisponibile();
	int getNrLocuriDejaVandute();
	void setData(string data);
	void setLoc(string loc);
	void setNrLocuriDisponibile(int nrLocuriDisponibile);
	void setNrLocuriDejaVandute(int nrLocuriDejaVandute);
	AtractieFestival& operator=(const AtractieFestival& a);
	virtual bool operator==(const AtractieFestival& a);
	virtual string getCsvString() {
		return string();
	};
	friend ostream& operator<<(ostream& os, const AtractieFestival& a);
	friend istream& operator>>(istream& is, AtractieFestival& a);
	virtual string toString() {
		return string();
	};
	virtual void getTXTObject(vector<string> informatii) {};
	string getZi();
	string getOra();
	virtual void getCsvObject(vector<string>) {};
	virtual string getForHTML(int i) {
		return string();
	};
	virtual AtractieFestival* clone();
};