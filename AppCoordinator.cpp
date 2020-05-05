#include <iostream>
#include "Film.h"
#include "Artist.h"
#include "ServiceUtilizator.h"
#include "Console.h"
#include "Repo.h"
#include "Test.h"
using namespace std;
int main() {
	Test t;
	t.testEntitati();
	t.testRepo();
	Repo<Utilizator> repo_utilizator("Utilizatori.txt");
	ServiceUtilizator s(repo_utilizator);
	Console console(s);

	console.run_console();

	

	return 0;

}
