#include "Console.h"

void Console::run_console()
{
	string option, nume, parola;
	string fileName1 = "HTMLPage1.htm";
	string fileName2 = "HTMLPage2.htm";
	while (true) {

		cout << "Introduceti numele de utilizator: ";
		cin >> nume;
		cout << "Introduceti parola: ";
		cin >> parola;


		if (this->service_utilizator.seeIfExistentUser(nume, parola) != true)
			cout << "Nu exista un utilizator cu aceast nume sau parola" << endl;
		else {
			string tip_fisier_1;
			cout << "Ce fisier doriti sa folositi? ";
			cin >> tip_fisier_1;

			try {
				service.setRepo(tip_fisier_1);

				while (true) {

					this->print_HTML(1, this->service.getAll(), fileName1);

					string option;
					this->menu();
					cout << "Introduceti o optiune: ";
					cin >> option;
					if (option == "1") {
						string option_2;
						this->menu_2();
						cin >> option_2;
						if (option_2 == "1") {

							cout << "In ce zi va avea loc evenimentul? ";
							int zi = this->getInteger();
							if (zi > 31)
								cout << "Ziua nu poate fi mai mare de 31 \n";
							else {
								vector<AtractieFestival*> artisti_cautare = this->service.getAtractieCareAreSpectacolInZiuaCutare("A", to_string(zi));
								if (!artisti_cautare.empty())
									this->print_HTML(0, artisti_cautare, fileName2);
								else
									cout << "Nu au loc spectacole in aceasta zi \n";
							}
							vector<AtractieFestival*> artisti_cautare = this->service.getAtractieCareAreSpectacolInZiuaCutare("A", to_string(zi));
							if (!artisti_cautare.empty())
								this->print_HTML(0, artisti_cautare, fileName1);
							else
								cout << "Niciun artist nu are spectacol in ziua aceasta";

						}
						else
							if (option_2 == "2") {
								cout << "In ce zi va avea loc evenimentul? ";
								int zi = this->getInteger();
								if (zi > 31)
									cout << "Ziua nu poate fi mai mare de 31 \n";
								else {
									vector<AtractieFestival*> filme_cautare = this->service.getAtractieCareAreSpectacolInZiuaCutare("F", to_string(zi));

									if (!filme_cautare.empty())
										this->print_HTML(0, filme_cautare, fileName2);
									else
										cout << "Nu au loc spectacole in aceasta zi \n";
								}

							}
							else break;

					}
					else
						if (option == "2") {
							string option_2;
							this->menu_3();
							cin >> option_2;
							if (option_2 == "1") {
								try {
									string nume_cumparator, nume_artist;
									int numar_bilete;
									cout << "Care este numele cumparatorului? ";
									cin.ignore();
									getline(cin,nume_cumparator);
									cout << "Care este numele artistului la spectacolul caruia doriti sa achizitionati bilete? ";
									getline(cin,nume_artist);
									cout << "Cate bilete doreste sa achizitioneze? ";
									numar_bilete = this->getInteger();
									this->service.cumparare_bilet_artist(nume_artist, nume_cumparator, numar_bilete);
									this->print_HTML(0, this->service.getAll(), fileName1);
								}
								catch (const char* msg) {
									cout << msg << endl;
								}
								catch (MyNumberException& msg) {
									cout << msg.what();
								}
								catch (...) {
									cout << "exception..." << endl;
								}

							}
							else
								if (option_2 == "2") {
									try {

										string nume_cumparator, nume_film;
										int numar_bilete;
										cout << "Care este numele cumparatorului? ";
										cin.ignore();
										getline(cin,nume_cumparator);
										cout << "Care este titlul filmului? ";
										getline(cin,nume_film);
										cout << "Cate bilete doreste sa achizitioneze? ";
										numar_bilete = this->getInteger();

										this->service.cumparare_bilet_film(nume_film, nume_cumparator, numar_bilete);

										this->print_HTML(0, this->service.getAll(), fileName2);
									}
									catch (MyNumberException& msg) {
										cout << msg.what()<<endl;
									}
									catch (const char* msg) {
										cout << msg << endl;
									}
									catch (...) {
										cout << "exception..." << endl;
									}
								}
						}
					try {
						cout << "Logout? (da/nu): ";

						string iesire;
						cin >> iesire;

						e.option_out(iesire);
						if (iesire == "da")
							break;
					}
					catch (MyInputStringException& msg) {
						cout << msg.what();
						cout << "Se va da logout de la sine \n";
						break;
					}

				}

			}
			catch (MyInputStringException& msg) {
				cout << msg.what();
			}

			try {
				cout << "Inchideti aplicatia? (da/nu): ";
				string iesire;
				cin >> iesire;
				e.option_out(iesire);
				if (iesire == "da")
					break;
			}
			catch (MyInputStringException& msg) {
				cout << msg.what();
				cout << "Se va inchide aplicatia \n";
				break;
			}

		}
	}
}

int Console::getInteger()
{
		int choice = 0;
	cin >> choice;

	while (!cin.good()) {
		cout << "Nu ati introdus un numar \n";

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << "Introduceti din nou: ";
		cin >> choice;
	}

	return choice;
}
