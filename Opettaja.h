#pragma once
//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Opettaja.h

#include "Tyontekija.h"
#include <string>

using std::string;


class Opettaja :
	public Tyontekija
{
public:
	Opettaja();
	Opettaja(const string& etunimi, const string& sukunimi,
		const string& osoite, const string& puhelinnumero,
		const string& tunnus, const float& palkka, const string& opetusala);
	Opettaja(const Opettaja& alkup);
	~Opettaja();
	Opettaja& operator= (const Opettaja& alkup);

	// getters
	string annaOpetusala() const;

	// setters
	void asetaOpetusala(const string& opetusala);

	void tulosta() const;
	void kysyTiedot();

private:
	string opetusala_;

};

