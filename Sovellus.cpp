#include "Sovellus.h"
//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Sovellus.h


#include "Sovellus.h"
#include "Koulu.h"
#include "Koulutusohjelma.h"
#include <iostream>
#include <string>
#include <vector>

using std::string; using std::endl; using std::getline; using std::vector; using std::cout; using std::cin;

Sovellus::Sovellus()
{
}

Sovellus::Sovellus(const string& nimi): nimi_(nimi)
{
}

Sovellus::~Sovellus()
{
}

string Sovellus::annaNimi() const
{
	return nimi_;
}

void Sovellus::asetaNimi(const string& nimi)
{
	nimi_ = nimi;
}

void pause()
{
	system("@echo off");
	system("echo Paina jotain jatkaaksesi");
	system("pause > nul");
	system("cls");
}

void Sovellus::aja() const
{
	
	string valinta;
	Koulu TAMK;
	Koulutusohjelma TiTe;

	do
	{
		valinta = tulostaValikko();
		if (valinta == "1")
		{
			TAMK.lisaaKoulutusohjelma();
			pause();
		}
		else if (valinta == "2")
		{
			TAMK.tulostaKoulutusohjelmat();
			pause();
		}
		else if (valinta == "3")
		{
			TAMK.tulostaKoulutusohjelmienMaara();
			pause();
		}
		else if (valinta == "4")
		{
			TAMK.lisaaKoulutusohjelmaanOpettaja();
			pause();
		}
		else if (valinta == "5")
		{
			TAMK.tulostaKoulutusohjelmanOpettajat();
			pause();
		}
		else if (valinta == "6")
		{
			TAMK.lisaaKoulutusohjelmaanOpiskelija();
			pause();
		}
		else if (valinta == "7")
		{
			TAMK.tulostaKoulutusohjelmanOpiskelijat();
			pause();
		}
		else if (valinta == "8")
		{
			TAMK.poistaKoulutusohjelma();
			pause();
		}
		else if (valinta == "9")
		{
			TAMK.poistaOpettaja();
			pause();
		}
		else if (valinta == "10")
		{
			TAMK.poistaOpiskelija();
			pause();
		}
		else if (valinta == "11")
		{
			TAMK.paivitaKoulutusohjelmanNimi();
			pause();
		}
		else if (valinta == "12")
		{
			TAMK.paivitaOpettajanTiedot();
			pause();
		}
		else if (valinta == "13")
		{
			TAMK.paivitaOpiskelijanTiedot();
			pause();
		}
		else if (valinta == "14")
		{
			TAMK.lueTiedot();
			pause();
		}
		else if (valinta == "15")
		{
			TAMK.tallennaTiedot();
			pause();
		}
		else if (valinta == "0")
		{
			cout << "Nakemmin ja tervetuloa uudelleen!" << endl;
		}
		else

			cout << "Ole hyva ja syota 1 - 15 tai 0." << endl << endl;
	} while (valinta != "0");
}

string Sovellus::valikko() const
{
	return string();
}

string Sovellus::tulostaValikko() const
{
	string valinta;
	cout << "1) \tLisaa koulutusohjelma " << endl;
	cout << "2) \tTulosta koulutusohjelmien nimet " << endl;
	cout << "3) \tTulosta koulutusohjelmien maara " << endl;
	cout << "4) \tLisaa koulutusohjelmaan opettaja " << endl;
	cout << "5) \tTulosta koulutusohjelman opettajat " << endl;
	cout << "6) \tLisaa koulutusohjelmaan opiskelija " << endl;
	cout << "7) \tTulosta koulutusohjelman opiskelijat " << endl;
	cout << "8) \tPoista koulutusohjelma " << endl;
	cout << "9) \tPoista opettaja " << endl;
	cout << "10) \tPoista opiskelija " << endl;
	cout << "11) \tPaivita koulutusohjelman nimi " << endl;
	cout << "12) \tPaivita opettajan tiedot " << endl;
	cout << "13) \tPaivita opiskelijan tiedot " << endl;
	cout << "14) \tLue tiedot " << endl;
	cout << "15) \tTallenna tiedot " << endl;
	cout << "0) \tLopeta " << "\n" << endl;
	cout << "Valintasi: \t";
	getline(cin, valinta);
	return valinta;
}