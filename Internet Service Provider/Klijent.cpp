#include "Klijent.h"
#include <cstdlib>
#include <ctime>

Klijent::Klijent()
{
	srand(time(NULL));
	this->klijentID = rand() % 89 + 10;
	strcpy_s(this->email, "ime.prezime20@gamil.com");
	this->stanje = nista;
}

void Klijent::setEmail()
{
	std::cout << "\t\t\t\t  Unesite email: ";
	do {
		std::cin.getline(this->email, sizeof this->email);
		if (!provjeriMail(this->email)) std::cout << "\n\t\t\t\t  Greska - Email nepravilno unesen.\n\t\t\t\t  Ponovo unesite email (formata ime.prezime@gmail.com): ";
	} while (!provjeriMail(this->email));
}

void Klijent::setStanje()
{
	std::cout << "\n\t\t\t\t  1. Penzioner\n\t\t\t\t  2. Student\n\t\t\t\t  3. Nezaposlen\n\t\t\t\t  4. Nista od navedenog";
	std::cout << "\n\t\t\t\t  Izbor: ";
	int izbor = 0;
	while (izbor < 1 || izbor > 4) {
		std::cin >> izbor;
		if (izbor < 1 || izbor > 4) std::cout << "\n\t\t\t\t  Greska - Nepravilan izbor (1-4).\n\t\t\t\t  Ponovo unesite izbor: ";
	}
	if (izbor == 1) this->stanje = penzioner;
	else if (izbor == 2) this->stanje = student;
	else if (izbor == 3) this->stanje = nezaposlen;
	else this->stanje = nista;
}

void Klijent::setKlijentID(std::string klijentID) {
	this->klijentID = stringtoint(klijentID.c_str());
}

void Klijent::setEmail(std::string email) {
	strcpy_s(this->email, email.c_str());
}

void Klijent::setStanje(const Stanje stanje) {
	this->stanje = stanje;
}

int Klijent::getKlijentID()
{
	return this->klijentID;
}

char* Klijent::getEmail()
{
	return this->email;
}

Stanje Klijent::getStanje()
{
	return this->stanje;
}

std::istream& operator>>(std::istream& stream, Klijent& k)
{
	std::cout << "\n\t\t\t\t  Info - Unos podataka o klijentu.\n\n";
	k.setIme();
	k.setPrezime();
	k.setJMBG();
	k.setMjestoRodjenja();
	k.setDatumRodjenja();
	k.setMjestoBoravka();
	k.setAdresa();
	k.setDrzavljanstvo();
	k.setEmail();
	k.setStanje();
	loading("Spremanje klijenta...");
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Klijent& k)
{
	stream << "\n\t\t\t\t  Info - Podaci o Klijentu!";
	stream << "\n\t\t\t\t  Ime: " << k.getIme();
	stream << "\n\t\t\t\t  Prezime " << k.getPrezime();
	stream << "\n\t\t\t\t  JMBG: " << k.getJMBG();
	stream << "\n\t\t\t\t  Datum rodjenja: " << k.getDatumRodjenja();
	stream << "\n\t\t\t\t  Mjesto rodjenja: " << k.getMjestoRodjenja();
	stream << "\n\t\t\t\t  Mjesto boravka: " << k.getMjestoBoravka();
	stream << "\n\t\t\t\t  Adresa: " << k.getAdresa();
	stream << "\n\t\t\t\t  Drzavljanstvo: " << k.getDrzavljanstvo();
	stream << "\n\t\t\t\t  Email: " << k.getEmail();
	stream << "\n\t\t\t\t  Stanje: ";
	if (k.getStanje() == penzioner) stream << "\n\t\t\t\t  Penzioner";
	else if (k.getStanje() == student) stream << "\n\t\t\t\t  Student";
	else if (k.getStanje() == nezaposlen) stream << "\n\t\t\t\t  Nezaposlen";
	else stream << "\n\t\t\t\t  None";
	return stream;
}

