//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Koulu.h

#include <string>
#include <iostream>
#include <vector>
#include "Koulu.h"
#include "Koulutusohjelma.h"
#include <fstream>			// Tiedostoon kirjoittamista ja sieltä lukemista varten

using std::string; using std::cout; using std::cin; using std::vector; using std::endl;
using std::ofstream; using std::ifstream;

Koulu::Koulu(): nimi_(), koulutusohjelmat_()
{
}

Koulu::Koulu(const string& nimi): nimi_(), koulutusohjelmat_()
{
}

Koulu::~Koulu()
{
}

Koulu& Koulu::operator=(const Koulu& alkup) 
{
	if (this != &alkup) {
		nimi_ = alkup.nimi_;
		koulutusohjelmat_ = alkup.koulutusohjelmat_;
	}
	return *this;
}

string Koulu::annaNimi() const
{
	return nimi_;
}

void Koulu::lisaaKoulutusohjelma()
{
	cout << "Anna koulutusohjelman nimi: ";
	string temp_nimi;
	getline(cin, temp_nimi);
	koulutusohjelmat_.push_back(Koulutusohjelma(temp_nimi));

}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int temp_i = etsiKoulutusohjelma();
	if (temp_i >= 0)
		koulutusohjelmat_[temp_i].lisaaOpettaja();

	else
		cout << "Etsimaasi koulutusohjelmaa ei ole. Tarkasta ohjelman nimi.\n";
}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int temp_i = etsiKoulutusohjelma();
	if (temp_i >= 0)
		koulutusohjelmat_[temp_i].lisaaOpiskelija();

	else
		cout << "Etsimaasi koulutusohjelmaa ei ole. Tarkasta ohjelman nimi.\n";
}

void Koulu::tulostaKoulutusohjelmat() const
{
	cout << "\n";

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		cout << i + 1 << ": " << koulutusohjelmat_[i].annaNimi() << "\n";
	}
}

void Koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << koulutusohjelmat_.size() << "\n";
}

void Koulu::tulostaKoulutusohjelmanOpettajat() const
{
	int temp_i = etsiKoulutusohjelma();
	if (temp_i >= 0)
		koulutusohjelmat_[temp_i].tulostaOpettajat();

	else
		cout << "Etsimaasi koulutusohjelmaa ei ole. Tarkasta ohjelman nimi.\n";
}

void Koulu::tulostaKoulutusohjelmanOpiskelijat() const
{
	int temp_i = etsiKoulutusohjelma();
	if (temp_i >= 0)
		koulutusohjelmat_[temp_i].tulostaOpiskelijat();

	else
		cout << "Etsimaasi koulutusohjelmaa ei ole. Tarkasta ohjelman nimi.\n";
}

void Koulu::poistaKoulutusohjelma()
{
	string temp_nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, temp_nimi);
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (temp_nimi == koulutusohjelmat_[i].annaNimi())
		{
			cout << "Koulutusohjelma " << koulutusohjelmat_[i].annaNimi() << " poistetaan." << endl;
			koulutusohjelmat_.erase(koulutusohjelmat_.begin() + i);
			break;
		}
		else
		{
			cout << "Koulutusohjelmaa ei loytynyt" << endl;
		}
	}

}

void Koulutusohjelma::poistaOpettaja_1()
{
	int indeksi = etsiOpettaja();

	if (indeksi >= 0)
	{
		opettajat_.erase(opettajat_.begin() + indeksi);
	}
	else
		cout << "Opettajaa ei loytynyt ";
}


void Koulu::poistaOpettaja()
{
	cout << "Haluat poistaa opettajan. Tarvitsen koulutusohjelman nimen." << endl;
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].poistaOpettaja_1();
	}
	else
	{
		cout << "Opettajaajaa ei loytynyt." << endl;
	}
}

void Koulutusohjelma::poistaOpiskelija_1()
{
	int indeksi = etsiOpiskelija();

	if (indeksi >= 0)
	{
		opiskelijat_.erase(opiskelijat_.begin() + indeksi);
	}
	else
		cout << "Opiskelijaa ei loytynyt.";
}

void Koulu::poistaOpiskelija()
{
	cout << "Haluat poistaa opiskelijan. Tarvitsen koulutusohjelman nimen." << endl;
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].poistaOpiskelija_1();
	}
	else
	{
		cout << "Opiskelijaa ei loytynyt." << endl;
	}
}

void Koulu::paivitaKoulutusohjelmanNimi()
{
	int indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
	{
		cout << "Tassa on koulutusohjelman nykyinen nimi: \n";
		koulutusohjelmat_[indeksi].tulosta();
		cout << "Ole hyva ja syota uusi nimi: \n";
		koulutusohjelmat_[indeksi].kysyNimi();
	}
	else
		cout << "Opettajaa ei loytynyt ";
}

void Koulutusohjelma::kysyNimi()
{
	getline(cin, nimi_);
}


void Koulutusohjelma::paivitaOpettaja_1()
{
	int indeksi = etsiOpettaja();

	if (indeksi >= 0)
	{
		cout << "Tassa ovat opettajan nykyiset tiedot: \n";
		opettajat_[indeksi].tulosta();
		cout << "Ole hyva ja syota uudet tiedot: \n";
		opettajat_[indeksi].kysyTiedot();
	}
	else
		cout << "Opettajaa ei loytynyt ";
}

void Koulu::paivitaOpettajanTiedot()
{
	cout << "Haluat paivitaa opettajan tiedot. Tarvitsen koulutusohjelman nimen." << endl;
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].paivitaOpettaja_1();
	}
}

void Koulutusohjelma::paivitaOpiskelija_1()
{
	int indeksi = etsiOpiskelija();

	if (indeksi >= 0)
	{
		cout << "Tassa ovat opettajan nykyiset tiedot: \n";
		opiskelijat_[indeksi].tulosta();
		cout << "Ole hyva ja syota uudet tiedot: \n";
		opiskelijat_[indeksi].kysyTiedot();
	}
	else
		cout << "Opettajaa ei loytynyt ";
}

void Koulu::paivitaOpiskelijanTiedot()
{
	cout << "Haluat paivitaa opiskelijan tiedot. Tarvitsen koulutusohjelman nimen." << endl;
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].paivitaOpiskelija_1();
	}
}

void Koulu::lueKoulutusohjelmat()
{
	ifstream l_tied;
	string ko_Nimi;

	l_tied.open("koulutusohjelmat.csv");

	if (l_tied.is_open())
	{
		while (l_tied.peek() != EOF)			// EOF = "End Of File" TAI "En ofaa fanoa"
		{
			getline(l_tied, ko_Nimi, '\n');		// Luetaan nimi, kunnes tulee rivin loppu

			koulutusohjelmat_.push_back(Koulutusohjelma(ko_Nimi));
		}
	}
	else
		cout << "Tiedostoa koulutusohjelmat.csv ei loytynyt, tai se ei aukea. ";


	cout << "Luettiin koulutusohjelmat: \n";

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		koulutusohjelmat_[i].tulosta();
	}

	l_tied.close();
}

void Koulu::tallennaKoulutusohjelmat() const
{
	ofstream k_tied;
	k_tied.open("koulutusohjelmat.csv");

	if (k_tied.is_open())
	{
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
		{
			k_tied << koulutusohjelmat_[i].annaNimi() << endl;
		}
	}
	else
		cout << "Tiedostoa koulutusohjelmat.csv ei voitu luoda tai avata. ";

	k_tied.close();
}

void Koulutusohjelma::lueOpettajat()
{
	ifstream l_tied;
	string ko_Nimi, eNimi, sNimi, osoite, puhNro, tunnus, s_palkka, ala;
	float palkka;

	// Avataan tiedosto opettajat.csv:
	l_tied.open("opettajat.csv");

	if (l_tied.is_open())
	{
		while (l_tied.peek() != EOF)			// EOF = "End Of File" TAI "En ofaa fanoa"
		{
			getline(l_tied, ko_Nimi, ';');		// luetaan koulutusohjelman nimi
			getline(l_tied, eNimi, ';');		// Luetaan etunimi, kunnes tulee puolipiste.
			getline(l_tied, sNimi, ';');		// jne
			getline(l_tied, osoite, ';');
			getline(l_tied, puhNro, ';');
			getline(l_tied, tunnus, ';');
			getline(l_tied, s_palkka, ';');
			getline(l_tied, ala, '\n');				// Tiedoston lopussa ei ole puolipiste vaan endline.
			palkka = std::stof(s_palkka.c_str());		// Muutetaan palkka stringistä numeroksi

			if (ko_Nimi == Koulutusohjelma::annaNimi())
				opettajat_.push_back(Opettaja(eNimi, sNimi, osoite, puhNro, tunnus, palkka, ala));
		}
	}
	else
		cout << "Tiedostoa opettajat.csv ei loytynyt, tai se ei aukea. ";


	cout << "Luettiin opettaja: ";

	for (unsigned int i = 0; i < opettajat_.size(); i++)
	{
		opettajat_[i].tulosta();
	}

	l_tied.close();
}

void Koulutusohjelma::lueOpiskelijat()
{
	ifstream l_tied;
	string ko_Nimi, eNimi, sNimi, osoite, puhNro, opNro;

	// Avataan tiedosto opettajat.csv:
	l_tied.open("opiskelijat.csv");

	if (l_tied.is_open())
	{
		while (l_tied.peek() != EOF)			// EOF = "End Of File" TAI "En ofaa fanoa"
		{
			getline(l_tied, ko_Nimi, ';');		// luetaan koulutusohjelman nimi
			getline(l_tied, eNimi, ';');		// Luetaan etunimi, kunnes tulee puolipiste.
			getline(l_tied, sNimi, ';');		// jne
			getline(l_tied, osoite, ';');
			getline(l_tied, puhNro, ';');
			getline(l_tied, opNro, '\n');		// Tiedoston lopussa ei ole puolipiste vaan endline.

			if (ko_Nimi == Koulutusohjelma::annaNimi())
				opiskelijat_.push_back(Opiskelija(eNimi, sNimi, osoite, puhNro, opNro));
		}
	}
	else
		cout << "Tiedostoa opiskelijat.csv ei loytynyt, tai se ei aukea. ";

	cout << "Luettiin opiskelija: ";

	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
	{
		opiskelijat_[i].tulosta();
	}

	l_tied.close();
}


void Koulu::lueTiedot()
{
	// Ensin haetaan koulutusohjelmat ja populoidaan koultusohjelmat_ -vecotri
	lueKoulutusohjelmat();
	cout << endl;

	// Sitten haetaan opettajat ja laitetaan oikeaan paikkaan koulutusohjelmat_ -vecoria
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		cout << koulutusohjelmat_[i].annaNimi() << ": ";
		koulutusohjelmat_[i].lueOpettajat();
	}
	cout << endl;

	// Sama temppu opiskelijoille
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		cout << koulutusohjelmat_[i].annaNimi() << ": ";
		koulutusohjelmat_[i].lueOpiskelijat();
	}

}

void Koulu::tallennaTiedot() const
{
	tallennaKoulutusohjelmat();

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		koulutusohjelmat_[i].tallennaOpettajat();
	}

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		koulutusohjelmat_[i].tallennaOpiskelijat();
	}
}

void Koulutusohjelma::tallennaOpettajat() const
{
	ofstream k_tied;
	k_tied.open("opettajat.csv", std::ios::app);

	if (k_tied.is_open())
	{
		for (unsigned int i = 0; i < opettajat_.size(); i++)
		{
			k_tied << annaNimi() << ";"
				<< opettajat_[i].annaEtunimi() << ";"
				<< opettajat_[i].annaSukunimi() << ";"
				<< opettajat_[i].annaOsoite() << ";"
				<< opettajat_[i].annaPuhelinnumero() << ";"
				<< opettajat_[i].annaTunnus() << ";"
				<< opettajat_[i].annaPalkka() << ";"
				<< opettajat_[i].annaOpetusala() << endl;
		}
	}
	else
		cout << "Tiedostoa opettajat.csv ei voitu luoda tai avata. ";

	k_tied.close();
}


void Koulutusohjelma::tallennaOpiskelijat() const
{
	ofstream k_tied;
	k_tied.open("opiskelijat.csv", std::ios::app);

	if (k_tied.is_open())
	{
		for (unsigned int i = 0; i < opiskelijat_.size(); i++)
		{
			k_tied << annaNimi() << ";"
				<< opiskelijat_[i].annaEtunimi() << ";"
				<< opiskelijat_[i].annaSukunimi() << ";"
				<< opiskelijat_[i].annaOsoite() << ";"
				<< opiskelijat_[i].annaPuhelinnumero() << ";"
				<< opiskelijat_[i].annaOpiskelijanumero() << endl;
		}
	}
	else
		cout << "Tiedostoa opiskelijat.csv ei voitu luoda tai avata. ";

	k_tied.close();
}

void Koulutusohjelma::tulosta()
{
	cout << nimi_ << endl;
}

int Koulu::etsiKoulutusohjelma() const
{
	string temp_nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, temp_nimi);


	for (unsigned i = 0; i < koulutusohjelmat_.size(); i++) {

		if (temp_nimi == koulutusohjelmat_[i].annaNimi()) {

			return i;	// Koulutusohjelma löytyi, palautetaan sen indeksin numero
		}
	}

	return -1;			// Koulutusohjelma ei löytynyt, palautetaan -1
}
