#pragma once
//
// Olio-ohjelmointi syksy 2019
// Jens von Weissenberg
// 
// vko41 ja harjoitustyö
//
// Sovellus.h

#include<iostream>
#include <string>
#include <vector>

using std::string; using std::endl; using std::getline; using std::vector; using std::cout; using std::cin;

class Sovellus
{
public:
	Sovellus();
	Sovellus(const string& nimi);
	~Sovellus();

	string annaNimi() const;
	void asetaNimi(const string& nimi);

	void aja() const;
	string valikko() const;

private:
	string tulostaValikko() const;
	string nimi_;

};
