#pragma once
#include "Osoba.h"
#include "Funkcije.h"
#include <iostream>
enum Stanje {
    kraj=0, penzioner, student, nezaposlen, nista, 
};
class Klijent :
    public Osoba {

private:
    int klijentID;
    char email[30];
    Stanje stanje;
public:
    Klijent();
    // Seteri
    void setEmail();
    void setStanje();
    // Preoptereceni seteri
    void setKlijentID(std::string);
    void setEmail(std::string);
    void setStanje(const Stanje);
    // Geteri
    int getKlijentID();
    char* getEmail();
    Stanje getStanje();

    friend std::istream& operator>>(std::istream& stream, Klijent& k);
    friend std::ostream& operator<<(std::ostream& stream, Klijent& k);

    ~Klijent() {};
};

