#pragma once
#include "ServiceUtilizator.h"
#include "Service.h"


class Console {
private:
	Service service;
	ServiceUtilizator service_utilizator;
	Validare e;
public:
	Console(const ServiceUtilizator& s_u) {

		this->service_utilizator = s_u;

	};

	Console() {};

	~Console() {};

	void menu() {
		cout << "1. Cautare \n";
		cout << "2. Cumparare \n";
	}

	void menu_2() {
		cout << "1. Cautare artisti care au spectacol intr-o zi data \n";
		cout << "2. Cautare filme care ruleaza intr-o zi data \n";
	}

	void menu_3() {
		cout << "1. Cumparare bilet artist \n";
		cout << "2. Cumparare bilet film \n";
	}

	void print_HTML(int j, vector<AtractieFestival*> vector_obj, string fileName)
	{

		ofstream myfile;
		myfile.open(fileName);
		myfile << "<!DOCTYPE html><html><head><link href='https://fonts.googleapis.com/css2?family=Dancing+Script:wght@562;700&family=Righteous&display=swap' rel='stylesheet'><link href ='StyleSheet.css' rel = 'stylesheet'></head><body>";

		int n = vector_obj.size();

		for (int i = 0; i < n; i++) {
			if (vector_obj[i]->getNrLocuriDisponibile() == 0)
				myfile << "<p>" << vector_obj[i]->getForHTML(j) << "</p>";
			else
				myfile << "<h>" << vector_obj[i]->getForHTML(j) << "<br><br></h>";

		}


		myfile << "</body></html>";
		myfile.close();

		ShellExecute(NULL, "open", fileName.c_str(), NULL, NULL, SW_SHOWNORMAL);

	};

	void run_console();

	int getInteger();

};