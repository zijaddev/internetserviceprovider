#pragma once
#include <iostream>
#include <string>
class Osoba {

private:
	char ime[20], prezime[30], JMBG[14], mjestoRodjenja[20], datumRodjenja[11], mjestoBoravka[20], adresa[30],
		 drzavljanstvo[20];
public:
	Osoba();

	// Seteri
	void setIme();
	void setPrezime();
	void setJMBG();
	void setDatumRodjenja();
	void setMjestoRodjenja();
	void setMjestoBoravka();
	void setAdresa();
	void setDrzavljanstvo();
	// Preoptereceni seteri
	void setIme(std::string);
	void setPrezime(std::string);
	void setJMBG(std::string);
	void setDatumRodjenja(std::string);
	void setMjestoRodjenja(std::string);
	void setMjestoBoravka(std::string);
	void setAdresa(std::string);
	void setDrzavljanstvo(std::string);
	// Geteri
	char* getIme();
	char* getPrezime();
	char* getJMBG();
	char* getDatumRodjenja();
	char* getMjestoRodjenja();
	char* getMjestoBoravka();
	char* getAdresa();
	char* getDrzavljanstvo();
	//friend std::istream& operator>>(std::istream& stream, Osoba& o);
	//friend std::ostream& operator<<(std::ostream& stream, Osoba& o);
	~Osoba() = default;
};