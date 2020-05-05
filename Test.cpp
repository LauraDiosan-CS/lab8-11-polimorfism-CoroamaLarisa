#include "Test.h"
#include "Artist.h"
#include "Film.h"
#include "RepoCSV.h"
#include "Service.h"

void Test::testEntitati()
{
	this->testAtractieFestival();
	this->testArtisti();
	this->testFilme();

}

void Test::testRepo()
{
	this->testRepoCSV();
	this->testRepoTXT();
	this->testService();
}

void Test::testAtractieFestival()
{
	this->testGetAtractieFestival();
	this->testSetAtractieFestival();
	this->testOperatorAtractieFestival();
}

void Test::testGetAtractieFestival()
{
	AtractieFestival* at = new AtractieFestival("12:30 22.12.2019", "Ananas", 12, 30);
	assert(at->getData() == "12:30 22.12.2019");
	assert(at->getLoc() == "Ananas");
	assert(at->getNrLocuriDisponibile() == 12);
	assert(at->getNrLocuriDejaVandute() == 30);

	delete at;
}

void Test::testSetAtractieFestival()
{
	AtractieFestival* at = new AtractieFestival("12:30 22.12.2019", "Ananas", 12, 30);
	assert(at->getOra() == "12:30");
	assert(at->getZi() == "22");
	assert(at->getData() == "12:30 22.12.2019");
	assert(at->getLoc() == "Ananas");
	assert(at->getNrLocuriDisponibile() == 12);
	assert(at->getNrLocuriDejaVandute() == 30);

	at->setData("14:30 22.12.2019");
	at->setLoc("Banana");
	at->setNrLocuriDisponibile(50);
	at->setNrLocuriDejaVandute(50);

	assert(at->getData() == "14:30 22.12.2019");
	assert(at->getOra() == "14:30");
	assert(at->getZi() == "22");
	assert(at->getLoc() == "Banana");
	assert(at->getNrLocuriDisponibile() == 50);
	assert(at->getNrLocuriDejaVandute() == 50);

	delete at;
	at = NULL;

}

void Test::testOperatorAtractieFestival()
{
	AtractieFestival at("10:30 22.10.2018", "Bishies", 0, 36);
	AtractieFestival at_2("10:30 22.10.2018", "Bishies", 0, 36);

	assert(at == at_2);
	at_2.setNrLocuriDisponibile(50);
	assert(!(at == at_2));

}

void Test::testRepoCSV()
{
	RepoCSV repo_a("AtractieFestivalTest.csv");
	Artist* a1= new Artist("Coroama", "10:30 22.10.2018", "Bishies", 0, 36);
	vector<string> actori;
	actori.push_back("Cody Ko");
	actori.push_back("Noel Miller");
	actori.push_back("Kurtis Conner");
	actori.push_back("Danny Gonzalez");
	Film* f1 = new Film("Wassup my dudes", actori, "21:00 12.12.2012", "Unde vreau eu", 100, 89);
	Artist* a2 = new Artist("Duudete", "20:30 22.11.2012", "Bish", 20, 24);
	vector<AtractieFestival*> all = repo_a.getAll();
	assert(all[0]->toString() == a1->toString());
	assert(all[1]->toString() == f1->toString());
	assert(all[2]->toString() == a2->toString());
	assert(repo_a.getSize() == 3);
	Artist* a3 = new Artist("Blah", "22:30 22.12.2019", "bhs", 20, 20);
	repo_a.addElem(a3);
	assert(repo_a.getSize() == 4);
	assert(repo_a.getElem(3)->toString() == a3->toString());
	Artist* a4 = new Artist("Bish", "20:30 22.11.2012", "Bish", 20, 24);
	repo_a.update(a3, a4);
	assert(repo_a.getElem(3)->toString() == a4->toString());
	repo_a.stergere(a4);
	assert(repo_a.getSize() == 3);

	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete f1;
	a1 = NULL;
	a2 = NULL;
	a3 = NULL;
	a4 = NULL;
	f1 = NULL;

}

void Test::testRepoTXT()
{
	/*A / Coroama / 10:30 22.10.2018 / Bishies / 0 / 20
	F / Dude / Eu 1, Eu 2 / 10 : 30 22.10.2018 / Unde vreau eu / 100 / 20
	A / Duudete / 20 : 30 22.11.2012 / Swimming with the Fishes / 20 / 10*/
	RepoTXT repo_a("AtractieFestivalTest.txt");
	Artist* a1 = new Artist("Coroama", "10:30 22.10.2018", "Bishies", 0, 20);
	vector<string> actori;
	actori.push_back("Eu 1");
	actori.push_back("Eu 2");
	Film* f1 = new Film("Dude", actori, "10:30 22.10.2018", "Unde vreau eu", 100, 20);
	Artist* a2 = new Artist("Duudete", "20:30 22.11.2012", "Swimming with the Fishes", 20, 10);
	vector<AtractieFestival*> all = repo_a.getAll();
	assert(all[0]->toString() == a1->toString());
	assert(all[1]->toString() == f1->toString());
	assert(all[2]->toString() == a2->toString());
	assert(repo_a.getSize() == 3);
	Artist* a3 = new Artist("Blah", "22:30 22.12.2019", "bhs", 20, 20);
	repo_a.addElem(a3);
	assert(repo_a.getSize() == 4);
	assert(repo_a.getElem(3)->toString() == a3->toString());
	Artist* a4 = new Artist("Dudete", "20:30 22.11.2012", "Bish", 20, 24);
	repo_a.update(a3, a4);
	assert(repo_a.getElem(3)->toString() == a4->toString());
	repo_a.stergere(a4);
	assert(repo_a.getSize() == 3);

	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete f1;
	a1 = NULL;
	a2 = NULL;
	a3 = NULL;
	a4 = NULL;
	f1 = NULL;

}

void Test::testService()
{
	Service service;
	service.setRepo("AtractieFestivalTest.csv");
	Artist* a1 = new Artist("Coroama", "10:30 22.10.2018", "Bishies", 0, 36);
	vector<string> actori;
	actori.push_back("Cody Ko");
	actori.push_back("Noel Miller");
	actori.push_back("Kurtis Conner");
	actori.push_back("Danny Gonzalez");
	Film* f1 = new Film("Wassup my dudes", actori, "21:00 12.12.2012", "Unde vreau eu", 100, 89);
	Artist* a2 = new Artist("Duudete", "20:30 22.11.2012", "Bish", 20, 24);
	Artist* a3 = service.getArtistBasedOnName("Duudete");
	assert(a2->toString() == a3->toString());
	vector<AtractieFestival*> artisti = service.getAtractieCareAreSpectacolInZiuaCutare("A","22");
	assert(artisti[0]->toString() == a1->toString());
	assert(artisti[1]->toString() == a2->toString());
	service.cumparare_bilet_artist("Duudete", "Cumparator", 10);
	Artist* a4 = service.getArtistBasedOnName("Duudete");
	assert(a4->getNrLocuriDisponibile() == 10);
	service.cumparare_bilet_film("Wassup my dudes", "Cumparator", 10);
	Film* f2 = service.getFilmBasedOnName("Wassup my dudes");
	assert(f2->getNrLocuriDisponibile() == 90);
	service.delFilm("Wassup my dudes", actori, "21:00 12.12.2012", "Unde vreau eu", 90, 99);
	assert(service.getAll().size() == 2);
	service.addFilm("Wassup my dudes", actori, "21:00 12.12.2012", "Unde vreau eu", 100, 89);
	service.delArtist("Duudete", "20:30 22.11.2012", "Bish", 10, 34);
	assert(service.getAll().size() == 2);
	service.addArtist("Duudete", "20:30 22.11.2012", "Bish", 20, 24);


	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete f1;
	delete f2;
	a1 = NULL;
	a2 = NULL;
	a3 = NULL;
	a4 = NULL;
	f1 = NULL;
	f2 = NULL;


}

void Test::testArtisti() {

	this->testGetArtisti();
	this->testSetArtisti();
	this->testOperatorArtisti();
}

void Test::testGetArtisti() {

	Artist* at = new Artist("Andreea", "12:30 22.12.2019", "Ananas", 12, 30);
	assert(at->getNume() == "Andreea");
	assert(at->getData() == "12:30 22.12.2019");
	assert(at->getLoc() == "Ananas");
	assert(at->getOra() == "12:30");
	assert(at->getZi() == "22");
	assert(at->getNrLocuriDisponibile() == 12);
	assert(at->getNrLocuriDejaVandute() == 30);

	delete at;
	at = NULL;

}



void Test::testSetArtisti() {

	Artist* at = new Artist("Andreea", "12:30 22.12.2019", "Ananas", 12, 30);
	at->setNume("Ana");
	at->setData("14:30 22.12.2019");
	at->setLoc("Banana");
	at->setNrLocuriDisponibile(50);
	at->setNrLocuriDejaVandute(50);

	assert(at->getNume() == "Ana");
	assert(at->getData() == "14:30 22.12.2019");
	assert(at->getOra() == "14:30");
	assert(at->getZi() == "22");
	assert(at->getLoc() == "Banana");
	assert(at->getNrLocuriDisponibile() == 50);
	assert(at->getNrLocuriDejaVandute() == 50);

	delete at;
	at = NULL;

}

void Test::testOperatorArtisti()
{
	Artist at("Coroama", "10:30 22.10.2018", "Bishies", 0, 36);
	Artist at2("Coroama", "10:30 22.10.2018", "Bishies", 0, 36);
	assert(at == at2);
	at.setNrLocuriDisponibile(10);
	assert(!(at == at2));
	string csvString = at.getCsvString();
	assert(csvString == "A, Coroama, 10:30 22.10.2018, Bishies, 10, 36\n");
	string txtString = at.toString();
	assert(txtString == "A/Coroama/10:30 22.10.2018/Bishies/10/36\n");
	string getForHTML = at.getForHTML(1);
	assert(getForHTML == "Numele artistului este: Coroama<br>Detalii despre spectacol <br>Locatia: Bishies<br>Numarul de locuri disponibile: 10<br>Data evenimentului: 10:30 22.10.2018<br>Numarul de locuri deja vandute: 36");
	getForHTML = at.getForHTML(0);
	assert(getForHTML == "Numele artistului este: Coroama<br>Detalii despre spectacol <br>Locatia: Bishies<br>Numarul de locuri disponibile: 10<br>Ora inceperii: 10:30");
	Artist a;
	vector<string> info;
	info.push_back(" Coroama");
	info.push_back(" 10:30 22.10.2018");
	info.push_back(" Bishies");
	info.push_back(" 0");
	info.push_back(" 36");
	a.getCsvObject(info);

	assert(a == at2);

}

void Test::testFilme()
{
	this->testGetFilme();
	this->testSetFilme();
	this->testOperatorFilme();
}

void Test::testOperatorFilme()
{
	vector<string> actori;
	actori.push_back("Actor_nume Actor_prenume");
	actori.push_back("Actor_nume_2 Actor_prenume_2");
	Film at("titlu_film", actori, "12:30 22.12.2020", "Ananas", 12, 30);
	Film at_2("titlu_film", actori, "12:30 22.12.2020", "Ananas", 12, 30);
	assert(at == at_2);
	at.setNrLocuriDisponibile(100);
	assert(!(at == at_2));
	string csvString = at.getCsvString();
	assert(csvString == "F, titlu_film, Actor_nume Actor_prenume; Actor_nume_2 Actor_prenume_2, 12:30 22.12.2020, Ananas, 100, 30\n");
	string getForHTML = at.getForHTML(1);
	assert(getForHTML == "Titlul filmului este: titlu_film<br>Distributia: Actor_nume Actor_prenume, Actor_nume_2 Actor_prenume_2<br>Detalii suplimentare despre film<br>Locatia: Ananas<br>Numarul de locuri disponibile: 100<br>Data evenimentului: 12:30 22.12.2020<br>Numarul de locuri deja vandute: 30");
	string getTXT = at.toString();
	assert(getTXT == "F/titlu_film/Actor_nume Actor_prenume,Actor_nume_2 Actor_prenume_2/12:30 22.12.2020/Ananas/100/30\n");
	getForHTML = at.getForHTML(0);
	assert(getForHTML == "Titlul filmului este: titlu_film<br>Distributia: Actor_nume Actor_prenume, Actor_nume_2 Actor_prenume_2<br>Detalii suplimentare despre film<br>Locatia: Ananas<br>Numarul de locuri disponibile: 100<br>Ora inceperii: 12:30");
	Film f;
	vector<string> info;
	info.push_back(" titlu_film");
	info.push_back(" Actor_nume Actor_prenume; Actor_nume_2 Actor_prenume_2");
	info.push_back(" 12:30 22.12.2020");
	info.push_back(" Ananas");
	info.push_back(" 12");
	info.push_back(" 30");
	f.getCsvObject(info);

	assert(f == at_2);

}

void Test::testSetFilme()
{
	Film* at = new Film;
	at->setTitlu("titlu_film");
	at->setData("12:30 22.12.2019");
	at->setLoc("Ananas");
	at->setNrLocuriDisponibile(12);
	at->setNrLocuriDejaVandute(30);
	assert(at->getTitlu() == "titlu_film");
	assert(at->getData() == "12:30 22.12.2019");
	assert(at->getLoc() == "Ananas");
	assert(at->getOra() == "12:30");
	assert(at->getZi() == "22");
	assert(at->getNrLocuriDisponibile() == 12);
	assert(at->getNrLocuriDejaVandute() == 30);

	delete at;
	at = NULL;
}

void Test::testGetFilme() {
	vector<string> actori;

	actori.push_back("Actor_nume Actor_prenume");

	Film* at = new Film("Titlu", actori, "12:30 22.12.2019", "Ananas", 12, 30);

	assert(at->getTitlu() == "Titlu");
	assert(at->getActori()[0] == actori[0]);
	assert(at->getData() == "12:30 22.12.2019");
	assert(at->getLoc() == "Ananas");
	assert(at->getOra() == "12:30");
	assert(at->getZi() == "22");
	assert(at->getNrLocuriDisponibile() == 12);
	assert(at->getNrLocuriDejaVandute() == 30);

	delete at;
	at = NULL;
}







