#include "ServiceUtilizator.h"

ServiceUtilizator::ServiceUtilizator(const Repo<Utilizator>& r_u)
{
	this->repo_utilizatori = r_u;
}

void ServiceUtilizator::addUtilizator(string nume, string parola)
{
	Utilizator u(nume, parola);
	repo_utilizatori.addElem(u);
}

ServiceUtilizator& ServiceUtilizator::operator=(const ServiceUtilizator& s_a)
{
	this->repo_utilizatori = s_a.repo_utilizatori;

	return *this;
}

ServiceUtilizator::ServiceUtilizator(const ServiceUtilizator& s_a)
{
	this->repo_utilizatori = s_a.repo_utilizatori;
}

bool ServiceUtilizator::seeIfExistentUser(string nume, string parola)
{
	int n = this->repo_utilizatori.getSize();
	vector<Utilizator> utilizatori = this->repo_utilizatori.getAll();

	for (int i = 0; i < n; i++) {
		if (utilizatori[i].getNume() == nume && utilizatori[i].getParola() == parola)
			return true;

	}

	return false;
}
