#pragma once
#include "Funkcije.h"
#include <iostream>

enum koristenje {
	ogranicen = 0, neogranicen
};

class Paket {
private:
	int brzinaInterneta, cijena;
	char imePaketa[20], dodatnaPonuda[100];
	koristenje koristenjeInterneta;
public:

	static int brojPaketa;

	Paket();
	// Seteri
	void setImePaketa();
	void setBrzinaInterneta();
	void setCijena();
	void setDodatnaPonuda();
	void setKoristenjeInterneta();
	// Preoptereceni seteri
	void setImePaketa(std::string);
	void setBrzinaInterneta(std::string);
	void setCijena(std::string);
	void setDodatnaPonuda(std::string);
	void setKoristenjeInterneta(const koristenje);
	// Geteri
	char* getImePaketa();
	int getBrzinaInterneta();
	int getCijena();
	char* getDodatnaPonuda();
	koristenje getKoristenjeInterneta();

	friend std::istream& operator>>(std::istream& stream, Paket& p);
	friend std::ostream& operator<<(std::ostream& stream, Paket& p);

	~Paket() = default;
};

