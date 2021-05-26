//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Tyontekija.cpp

#include "Tyontekija.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>

using std::string; using std::cout; using std::cin; using std::stof; 

Tyontekija::Tyontekija(): Henkilo(), tunnus_(), palkka_()
{
}

Tyontekija::Tyontekija(const string& etunimi, const string& sukunimi, 
	const string& osoite, const string& puhelinnumero, 
	const string& tunnus, const float& palkka): Henkilo(etunimi, sukunimi, osoite, puhelinnumero), 
	tunnus_(tunnus), palkka_(palkka)
{
}

Tyontekija::Tyontekija(const Tyontekija& alkup): Henkilo(alkup), 
tunnus_(alkup.tunnus_), palkka_(alkup.palkka_)
{
}

Tyontekija::~Tyontekija()
{
}

Tyontekija& Tyontekija::operator=(const Tyontekija& alkup)
{
	if (this != &alkup) {
		Henkilo::operator=(alkup);
		palkka_ = alkup.palkka_;
		tunnus_ = alkup.tunnus_;
	}
	return *this;
}

float Tyontekija::annaPalkka() const
{
	return palkka_;
}

string Tyontekija::annaTunnus() const
{
	return tunnus_;
}

void Tyontekija::asetaPalkka(const float& palkka)
{
	palkka_ = palkka;
}

void Tyontekija::asetaTunnus(const string& tunnus)
{
	tunnus_ = tunnus;
}

void Tyontekija::tulosta() const
{
	Henkilo::tulosta();
	cout << tunnus_ << " " << palkka_ ;
}

void Tyontekija::kysyTiedot()
{
	Henkilo::kysyTiedot();
	int lippu = 0;

		try
		{
			cout << "Anna tyontekijatunnus: ";
			getline(cin, tunnus_);
			cout << "Anna palkka: ";

			size_t sz;
			string palkanApustringi;
			getline(cin, palkanApustringi);

			if (palkka_ > std::numeric_limits<float>::max())
				throw std::exception("Palkan syottaminen ei onnistunut");

			else
				palkka_ = stof(palkanApustringi, &sz);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Palkan syottaminen ei onnistunut: " << e.what() << std::endl;
			Tyontekija::kysyTiedot();
		}

	

	
	
	// debug
	// cout << "\nKuukausipalkka on " << palkka_ << " ja tuntipalkka on " << palkka_ / 166 << ".\n";
}
