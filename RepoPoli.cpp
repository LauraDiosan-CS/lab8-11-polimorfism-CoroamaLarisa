#include "RepoPoli.h"


void RepoPoli::clear()
{
	if (!this->elem.empty()) {
		int n = this->elem.size();
		for (int i = 0; i < n; i++)
			delete this->elem[i];
	}
	this->elem.clear();
}

RepoPoli::~RepoPoli()
{
	delete[] this->fileName;
	if (!this->elem.empty()) {
		int n = this->elem.size();
		for (int i = 0; i < n; i++)
			delete this->elem[i];
	}
	this->elem.clear();
}

RepoPoli::RepoPoli(const char* fileName)
{
	this->fileName = new char[strlen(fileName) + 1];
	strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
	this->loadFromFile();
}

int RepoPoli::getSize()
{
	return this->elem.size();
}

AtractieFestival* RepoPoli::getElem(int i)
{
	return this->elem[i];
}

void RepoPoli::setFileName(const char* fileName)
{
	if (this->fileName != NULL) {
		delete[] this->fileName;
	}
	if (fileName != NULL) {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
	}
	else
		this->fileName = NULL;
}

RepoPoli::RepoPoli(const RepoPoli& r)
{
	this->fileName = new char[strlen(r.fileName) + 1];
	strcpy_s(this->fileName, strlen(r.fileName) + 1, r.fileName);
	this->loadFromFile();
}

void RepoPoli::addElem(AtractieFestival* c)
{
	this->elem.push_back(c->clone());
	this->saveToFile();
}

vector<AtractieFestival*> RepoPoli::getAll()
{
	return this->elem;
}

RepoPoli& RepoPoli::operator=(const RepoPoli& repo)
{
	this->setFileName(repo.fileName);
	this->loadFromFile();

	return *this;
}

AtractieFestival* RepoPoli::getAtractie(int pos)
{
	int n = this->elem.size();
	if (pos >= 0 && pos < n) {
		return this->elem[pos];
	}

	return new AtractieFestival;
}

void RepoPoli::stergere(AtractieFestival* c)
{
	int n = this->elem.size();
	for (int i = 0; i < n; i++) {

		if( (*(this->elem.begin() + i))->toString() == c->toString()) {

			delete this->elem[i];
			this->elem.erase(this->elem.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void RepoPoli::update(AtractieFestival* c1, AtractieFestival* c2)
{
	int n = this->elem.size();

	for (int i = 0; i < n; i++) {


		if (this->elem[i]->toString() == c1->toString()) {

			delete this->elem[i];
			this->elem[i] = c2->clone();
			this->saveToFile();
			return;

		}
	}
	
}
