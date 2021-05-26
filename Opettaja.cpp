//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Opettaja.cpp

#include "Opettaja.h"
#include <string>
#include <iostream>

using std::string; using std::cout; using std::cin;

Opettaja::Opettaja():Tyontekija(), opetusala_()
{
}

Opettaja::Opettaja(const string& etunimi, const string& sukunimi, 
	const string& osoite, const string& puhelinnumero, 
	const string& tunnus, const float& palkka, 
	const string& opetusala): Tyontekija(etunimi, sukunimi, osoite, puhelinnumero, tunnus, palkka),
	opetusala_(opetusala)
{
}

Opettaja::Opettaja(const Opettaja& alkup): Tyontekija(alkup),
opetusala_(alkup.opetusala_)
{
}

Opettaja::~Opettaja()
{
}

Opettaja& Opettaja::operator=(const Opettaja& alkup)
{
	if (this != &alkup) {
		Tyontekija::operator=(alkup);
		opetusala_ = alkup.opetusala_;
	}
	return *this;
}

string Opettaja::annaOpetusala() const
{
	return opetusala_;
}

void Opettaja::asetaOpetusala(const string& opetusala)
{
	opetusala_ = opetusala;
}

void Opettaja::tulosta() const
{
	Tyontekija::tulosta();
	cout << " "<< opetusala_ << "\n";
}

void Opettaja::kysyTiedot()
{
	Tyontekija::kysyTiedot();

	cout << "Anna opetusala: ";
	getline(cin, opetusala_);
}
