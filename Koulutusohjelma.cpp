//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Koulutusohjelma.cpp

#include <string>
#include <iostream>
#include <vector>
#include "Koulutusohjelma.h"

using std::string; using std::vector; using std::cin; using std::cout;



Koulutusohjelma::Koulutusohjelma() : nimi_(), opiskelijat_(), opettajat_()
{
}

Koulutusohjelma::Koulutusohjelma(const string& nimi): nimi_(nimi), opiskelijat_(), opettajat_()
{
}

Koulutusohjelma::~Koulutusohjelma()
{
}

Koulutusohjelma& Koulutusohjelma::operator=(const Koulutusohjelma& alkup) 
{
	if (this != &alkup) {
		nimi_ = alkup.nimi_;
		opiskelijat_ = alkup.opiskelijat_;
		opettajat_ = alkup.opettajat_;
	}
	return *this;
}

string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

void Koulutusohjelma::asetaNimi(const string& nimi)
{
	nimi_ = nimi;
}

void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja temp;		// Luodaan opettajaolio nimeltään temp
	temp.kysyTiedot();
	opettajat_.push_back(temp);

}

void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija temp;		// Luodaan opiskelijaolio nimeltään temp
	temp.kysyTiedot();
	opiskelijat_.push_back(temp);
}

void Koulutusohjelma::tulostaOpettajat() const
{
	cout << "\n";

	for (unsigned int i = 0; i < opettajat_.size(); i++)
	{
		opettajat_[i].tulosta();
	}

}

void Koulutusohjelma::tulostaOpiskelijat() const
{
	cout << "\n";

	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
	{
		opiskelijat_[i].tulosta();
	}
}

int Koulutusohjelma::etsiOpettaja() const
{
	string temp_nimi;
	cout << "Anna opettajan tunnus: ";
	getline(cin, temp_nimi);


	for (unsigned i = 0; i < opettajat_.size(); i++) {

		if (temp_nimi == opettajat_[i].annaTunnus()) {

			return i;	// Opettaja löytyi, palautetaan sen indeksin numero
		}
	}

	return -1;			// Opettajaa ei löytynyt, palautetaan -1
}

int Koulutusohjelma::etsiOpiskelija() const
{
	string temp_nimi;
	cout << "Anna opiskelijanumero: ";
	getline(cin, temp_nimi);


	for (unsigned i = 0; i < opiskelijat_.size(); i++) {

		if (temp_nimi == opiskelijat_[i].annaOpiskelijanumero()) {

			return i;	// Opiskelijaa löytyi, palautetaan sen indeksin numero
		}
	}

	return -1;			// Opiskelija ei löytynyt, palautetaan -1
}

