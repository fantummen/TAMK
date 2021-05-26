//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Opiskelija.cpp

#include "Opiskelija.h"
#include <string>
#include <iostream>

using std::string; using std::cout; using std::cin;

Opiskelija::Opiskelija(): Henkilo(), opiskelijanumero_()
{
}

Opiskelija::Opiskelija(const string& etunimi, const string& sukunimi, 
	const string& osoite, const string& puhelinnumero, 
	const string& opiskelijanumero): Henkilo(etunimi, sukunimi, osoite, puhelinnumero), 
	opiskelijanumero_(opiskelijanumero)
{
}

Opiskelija::Opiskelija(const Opiskelija& alkup): Henkilo(alkup), 
opiskelijanumero_(alkup.opiskelijanumero_)
{
}

Opiskelija::~Opiskelija()
{
}

Opiskelija& Opiskelija::operator= (const Opiskelija& alkup) 
{
	if (this != &alkup) {
		Henkilo::operator=(alkup);
		opiskelijanumero_ = alkup.opiskelijanumero_;
	}
	return *this;
}

string Opiskelija::annaOpiskelijanumero() const
{
	return opiskelijanumero_;
}

void Opiskelija::asetaOpiskelijanumero(const string& opiskelijanumero)
{
	opiskelijanumero_ = opiskelijanumero;
}

void Opiskelija::tulosta() const
{
	Henkilo::tulosta();						// Otetaan ensiksi Henkilon kamat
	cout << opiskelijanumero_ << "\n";
}

void Opiskelija::kysyTiedot()
{
	Henkilo::kysyTiedot();

	cout << "Anna opiskelijanumero: ";
	getline(cin, opiskelijanumero_);
}
