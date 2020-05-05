#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "RepoPoli.h"
#include "AtractieFestival.h"
#include "Artist.h"
#include "Film.h"


class RepoTXT : public RepoPoli {
public:

	RepoTXT() : RepoPoli() {};

	RepoTXT(const char* fileName);

	RepoTXT(const RepoTXT& r) : RepoPoli(r) {};

	~RepoTXT() {};

	void loadFromFile();

	void saveToFile();

};