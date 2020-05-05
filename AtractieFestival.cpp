#include "AtractieFestival.h"

AtractieFestival::AtractieFestival()
{
	this->data = "";
	this->loc = "";
	this->nrLocuriDisponibile = 0;
	this->nrLocuriDejaVandute = 0;
}

AtractieFestival::AtractieFestival(string data, string loc, int nrLocuriDisponibile, int nrLocuriDejaVandute)
{
	this->data = data;
	this->loc = loc;
	this->nrLocuriDisponibile = nrLocuriDisponibile;
	this->nrLocuriDejaVandute = nrLocuriDejaVandute;

}

AtractieFestival::AtractieFestival(const AtractieFestival& a)
{
	this->data = a.data;
	this->loc = a.loc;
	this->nrLocuriDisponibile = a.nrLocuriDisponibile;
	this->nrLocuriDejaVandute = a.nrLocuriDejaVandute;
}

AtractieFestival::~AtractieFestival()
{
}

AtractieFestival& AtractieFestival::operator=(const AtractieFestival& a)
{
	this->data = a.data;
	this->loc = a.loc;
	this->nrLocuriDisponibile = a.nrLocuriDisponibile;
	this->nrLocuriDejaVandute = a.nrLocuriDejaVandute;

	return *this;

}

bool AtractieFestival::operator==(const AtractieFestival& a)
{
	return this->data == a.data && this->loc == a.loc && this->nrLocuriDisponibile == a.nrLocuriDisponibile && this->nrLocuriDejaVandute == a.nrLocuriDejaVandute;
}

string AtractieFestival::getZi()
{
	data = this->data;
	string zi = data.substr(6, 2);
	return zi;

}

string AtractieFestival::getOra()
{
	data = this->data;
	string ora = data.substr(0, 5);
	return ora;
}

AtractieFestival* AtractieFestival::clone()
{
	AtractieFestival* newAtractie = new AtractieFestival();
	newAtractie->setData(this->data);
	newAtractie->setLoc(this->loc);
	newAtractie->setNrLocuriDisponibile(this->nrLocuriDisponibile);
	newAtractie->setNrLocuriDejaVandute(this->nrLocuriDejaVandute);

	return newAtractie;

}

ostream& operator<<(ostream& os, const AtractieFestival& a)
{
	os << a.data << "/" << a.loc << "/" << a.nrLocuriDisponibile << "/" << a.nrLocuriDejaVandute<<"\n";

	return os;
}

istream& operator>>(istream& is, AtractieFestival& a)
{
	is >> a.data >> a.loc >> a.nrLocuriDisponibile >> a.nrLocuriDejaVandute;

	return is;
}



string AtractieFestival::getData()
{
	return this->data;
}

string  AtractieFestival::getLoc()
{
	return this->loc;
}

int  AtractieFestival::getNrLocuriDisponibile()
{
	return this->nrLocuriDisponibile;
}

int  AtractieFestival::getNrLocuriDejaVandute()
{
	return this->nrLocuriDejaVandute;
}

void  AtractieFestival::setData(string data)
{
	this->data = data;
}

void  AtractieFestival::setLoc(string loc)
{
	this->loc = loc;
}

void  AtractieFestival::setNrLocuriDisponibile(int nrLocuriDisponibile)
{
	this->nrLocuriDisponibile = nrLocuriDisponibile;
}

void  AtractieFestival::setNrLocuriDejaVandute(int nrLocuriDejaVandute)
{
	this->nrLocuriDejaVandute = nrLocuriDejaVandute;
}