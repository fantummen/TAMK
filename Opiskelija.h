#pragma once
//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Opiskelija.h

#include "Henkilo.h"
#include <string>

using std::string;

class Opiskelija :
	public Henkilo
{
public:
	Opiskelija();
	Opiskelija(const string& etunimi, const string& sukunimi, 
		const string& osoite, const string& puhelinnumero,
		const string& opiskelijanumero);
	Opiskelija(const Opiskelija& alkup);
	~Opiskelija();
	Opiskelija& operator= (const Opiskelija& alkup);

	// getters
	string annaOpiskelijanumero() const;

	// setters
	void asetaOpiskelijanumero(const string& opiskelijanumero);

	void tulosta() const;
	void kysyTiedot();

private:
	string opiskelijanumero_;
};

