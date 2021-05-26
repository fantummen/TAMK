//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// main.cpp

#include "Opiskelija.h"		// Tässä on Henkilo.h jo viitattu (#pragma.once huolehtii että otetaan vain kerran!)
#include "Opettaja.h"		// Tässä on Tyontekija.h viitattu, jossa Henkilo.h on viitattu
#include "Koulutusohjelma.h"
#include "Sovellus.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>			// Tiedostoon kirjoittamista ja sieltä lukemista varten

using std::string; using std::cout; using std::cin; using std::vector; using std::endl;
using std::ofstream; using std::ifstream;

int main()
{
	Koulutusohjelma tite("TiTe");

	Sovellus rekisteri("TAMK");
	rekisteri.aja();
	
	return 0;
}