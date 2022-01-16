#pragma once
#include "Osoba.h"
#include <iostream>

enum pozicijaUFirmi {
    // Admin - direktor
    // Obicni radnik - Radnik za salterom
    bezPozicije = -1, direktor, radnikZaSalterom
};

class Radnik :
    public Osoba {

private:
    int radnikID;
    char datumZaposljenja[11], strucnaSprema[50];
    float plata;
    pozicijaUFirmi pozicija;
    std::string username, password;
public:
    static int brojRadnika;
    // Konstruktor
    Radnik();
    // Seteri
    void setDatumZaposljenja();
    void setStrucnaSprema();
    void setPlata();
    void setPozicija();
    void setUsername();
    void setPassword();
    // Preoptereceni seteri
    void setRadnikID(std::string);
    void setDatumZaposljenja(std::string);
    void setStrucnaSprema(std::string);
    void setPlata(const float);
    void setPozicija(std::string);
    void setUsername(std::string);
    void setPassword(std::string);
    // Geteri
    int getRadnikID();
    char* getDatumZaposljenja();
    char* getStrucnaSprema();
    float getPlata();
    pozicijaUFirmi getPozicija();
    std::string getUsername();
    std::string getPassword();
    // Funkcije
    void vrijemeProvedenoUFirmi(const char*);
    // Operatori
    friend std::istream& operator>>(std::istream& stream, Radnik& r);
    friend std::ostream& operator<<(std::ostream& stream, Radnik& r);
    // Destruktor
    ~Radnik() {};
};

