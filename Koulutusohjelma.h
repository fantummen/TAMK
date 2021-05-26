#pragma once
//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Koulutusohjelma.h

#include <string>
#include <vector>
#include "Opiskelija.h"
#include "Opettaja.h"

using std::string; using std::vector;

class Koulutusohjelma
{
public:
	Koulutusohjelma();
	Koulutusohjelma(const string& nimi);
	~Koulutusohjelma();
	Koulutusohjelma& operator= (const Koulutusohjelma& alkup);

	// getters
	string annaNimi() const;

	// setters
	void asetaNimi(const string& nimi);

	void lisaaOpettaja();
	void lisaaOpiskelija();
	void tulostaOpettajat() const;
	void tulostaOpiskelijat() const;

	void poistaOpiskelija_1();
	void poistaOpettaja_1();

	void paivitaOpiskelija_1();
	void paivitaOpettaja_1();

	void lueOpettajat();
	void tallennaOpettajat() const;
	void lueOpiskelijat();
	void tallennaOpiskelijat() const;

	void kysyNimi();

	void tulosta();

private:
	string nimi_;
	int etsiOpettaja() const;
	int etsiOpiskelija() const;
	vector <Opiskelija> opiskelijat_;
	vector <Opettaja> opettajat_;
};

