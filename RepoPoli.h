#pragma once
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <cstddef>
#include <vector>
#include "AtractieFestival.h"
using namespace std;


class RepoPoli {
protected:
	char* fileName;
	vector<AtractieFestival*> elem;
public:

	RepoPoli() {
		this->fileName = NULL;
	};

	void clear();

	~RepoPoli();

	RepoPoli(const char* fileName);

	int getSize();

	AtractieFestival* getElem(int i);

	void setFileName(const char* fileName);

	RepoPoli(const RepoPoli& r);

	virtual void loadFromFile() {};

	virtual void saveToFile() {};

	void addElem(AtractieFestival* c);


	vector<AtractieFestival*> getAll();


	RepoPoli& operator=(const RepoPoli& repo);

	AtractieFestival* getAtractie(int pos);

	void stergere(AtractieFestival* c);
	void update(AtractieFestival* c1, AtractieFestival* c2);

};
