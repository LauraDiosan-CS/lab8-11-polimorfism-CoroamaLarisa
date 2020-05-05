#pragma once
#include <string>
#include "Utilizator.h"
#include "Repo.h"

class ServiceUtilizator {

private:

	Repo<Utilizator> repo_utilizatori;

public:

	ServiceUtilizator() {};

	ServiceUtilizator(const Repo<Utilizator>& r_u);

	void addUtilizator(string nume, string parola);

	ServiceUtilizator& operator=(const ServiceUtilizator& s_a);

	ServiceUtilizator(const ServiceUtilizator& s_a);
	

	bool seeIfExistentUser(string nume, string parola);

};