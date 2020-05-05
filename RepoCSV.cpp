#include "RepoCSV.h"

RepoCSV::RepoCSV(const char* fileName)
{
	this->setFileName(fileName);
	this->loadFromFile();
}

void RepoCSV::loadFromFile()
{
	this->clear();

	if (this->fileName != NULL) {

		ifstream file(this->fileName);


		vector<vector<string>> dataList;
		string line;


		// Iterate through each line and split the content using delimeter
		while (getline(file, line))
		{
			vector<string> informatii;
			boost::algorithm::split(informatii, line, boost::is_any_of(","));
			dataList.push_back(informatii);

		}

		file.close();

		int n = dataList.size();

		for (int i = 0; i < n; i++) {

			vector < string > info = dataList[i];
			string initiala = info[0];

			info.erase(info.begin());

			if (initiala == "A") {
				AtractieFestival* elem = new Artist;
				elem->getCsvObject(info);
				this->addElem(elem);

				delete elem;
			}
			else {
				AtractieFestival* elem = new Film;
				elem->getCsvObject(info);
				this->addElem(elem);
				delete elem;
			}


		}
	}
}

void RepoCSV::saveToFile()
{
	ofstream fout(this->fileName);

	int n = RepoPoli::getSize();

	for (int i = 0; i < n; i++) {
		fout << this->elem[i]->getCsvString();
	}

	fout.close();
}
