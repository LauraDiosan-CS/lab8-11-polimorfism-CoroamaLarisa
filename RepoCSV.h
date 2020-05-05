#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "RepoPoli.h"
#include "AtractieFestival.h"
#include "Artist.h"
#include "Film.h"


class RepoCSV : public RepoPoli {
public:

	RepoCSV() : RepoPoli() {};

	RepoCSV(const char* fileName);

	RepoCSV(const RepoCSV& r) : RepoPoli(r) {};

	~RepoCSV() {};

	void loadFromFile();

	void saveToFile();

};