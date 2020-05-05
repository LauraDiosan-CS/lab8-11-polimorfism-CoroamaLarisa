#pragma once
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <string>
#include <fstream>
using namespace std;

template< class T>
class Repo {
protected:
	char* fileName;
	vector<T> elemente;
public:
	void addElem(T c) {
		this->elemente.push_back(c);
	};

	vector<T> getAll() {

		return this->elemente;
	};

	int getSize() {
		return this->elemente.size();
	};

	Repo(){
		this->fileName = NULL;
	}

	Repo(const char* fileName) {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		this->loadFromFile();
	}

	Repo(const Repo& r) {
		this->fileName = new char[strlen(r.fileName) + 1];
		strcpy_s(this->fileName, strlen(r.fileName) + 1, r.fileName);
		this->loadFromFile();

	}


	Repo& operator=(const Repo& r) {

		this->fileName = new char[strlen(r.fileName) + 1];
		strcpy_s(this->fileName, strlen(r.fileName) + 1, r.fileName);
		this->loadFromFile();

		return *this;
	}

	virtual
		~Repo() {
		this->elemente.clear();
		delete[] this->fileName;
	}

	void stergere(T& c) {
		typename vector<T>::iterator it;

		it = find(this->elemente.begin(), this->elemente.end(), c);
		if (!(it == this->elemente.end())) {

			this->elemente.erase(it);
		}

	};

	void update(T& c1, T& c2) {
		typename vector<T>::iterator it;

		it = find(this->elemente.begin(), this->elemente.end(), c1);
		if (!(it == this->elemente.end())) {

			*it = c2;
		}
	};


	void clear() {
		this->elemente.clear();
	}

	T getElem(int i) {

		return this->elemente[i];

	}

	void loadFromFile() {

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

				T elem;
				vector < string > info = dataList[i];
				elem.getCsvObject(info);
				this->elemente.push_back(elem);

			}
		}

	};


	void saveToFile() {

		ofstream fout(this->fileName);

		int n = this->elemente.size();

		for (int i = 0; i < n; i++) {
			T elem = this->elemente[i];
			fout << elem.getCsvSting();

		}

		fout.close();

	};

};