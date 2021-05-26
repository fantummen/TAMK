#pragma once
//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Tyontekija.h

#include "Henkilo.h"
#include <string>

using std::string;

class Tyontekija :
	public Henkilo
{
public:
	Tyontekija();
	Tyontekija(const string& etunimi, const string& sukunimi,
		const string& osoite, const string& puhelinnumero,
		const string& tunnus, const float& palkka);
	Tyontekija(const Tyontekija& alkup);
	~Tyontekija();
	Tyontekija& operator= (const Tyontekija& alkup);

	// getters
	float annaPalkka() const;
	string annaTunnus() const;

	// setters
	void asetaPalkka(const float& palkka);
	void asetaTunnus(const string& tunnus);

	void tulosta() const;
	void kysyTiedot();

private:
	float palkka_;
	string tunnus_;
};

