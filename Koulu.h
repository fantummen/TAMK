#pragma once
//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Koulu.h

#include <string>
#include <vector>
#include "Koulutusohjelma.h"

using std::string; using std::vector;

class Koulu
{
public:

	Koulu();
	Koulu(const string& nimi);
	~Koulu();
	Koulu& operator= (const Koulu& alkup);

	string annaNimi() const;

	void lisaaKoulutusohjelma();
	void lisaaKoulutusohjelmaanOpettaja();
	void lisaaKoulutusohjelmaanOpiskelija();

	void tulostaKoulutusohjelmat() const;
	void tulostaKoulutusohjelmienMaara() const;
	void tulostaKoulutusohjelmanOpettajat() const;
	void tulostaKoulutusohjelmanOpiskelijat() const;

	void poistaKoulutusohjelma();
	void poistaOpettaja();
	void poistaOpiskelija();

	void paivitaKoulutusohjelmanNimi();
	void paivitaOpettajanTiedot();
	void paivitaOpiskelijanTiedot();

	void lueTiedot();
	void tallennaTiedot() const;
	
	void lueKoulutusohjelmat();
	void tallennaKoulutusohjelmat() const;



private:
	string nimi_;
	vector <Koulutusohjelma> koulutusohjelmat_;
	int etsiKoulutusohjelma() const;	// Koulutusohjelman löytämistä varten
};

