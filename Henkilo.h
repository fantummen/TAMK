#pragma once
//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Henkilo.h

#include <string>

using std::string;

class Henkilo
{
public:
	Henkilo();
	Henkilo(const string& etunimi, const string& sukunimi, const string& osoite, const string& puhelinnumero);
	Henkilo(const Henkilo& alkup);
	// ~Henkilo();
	virtual ~Henkilo();				// 28.11.2019: DYNAAMINEN SITOMINEN eli bindaus!
	Henkilo& operator= (const Henkilo& alkup);

	// getters
	string annaEtunimi() const;		// const tarkoittaa ettei private-arvoja muuteta!
	string annaSukunimi() const;	// Eli toimii gettereille. Ei tule vahinkoja.
	string annaOsoite() const;		// Toimii myös ilman constia, mutta const mahdollistaa vakioviittaukset
	string annaPuhelinnumero() const;

	// setters
	void asetaEtunimi(const string& etunimi);
	void asetaSukunimi(const string& sukunimi);
	void asetaOsoite(const string& osoite);
	void asetaPuhelinnumero(const string& puhelinnumero);

	virtual void tulosta() const;	// 28.11.2019: DYNAAMINEN SITOMINEN eli bindaus!
	void kysyTiedot();

private:
	string etunimi_;
	string sukunimi_;
	string osoite_;
	string puhelinnumero_;
};

