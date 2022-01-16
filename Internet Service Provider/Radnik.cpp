#include "Funkcije.h"
#include "Radnik.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int Radnik::brojRadnika = 0;

Radnik::Radnik() {

    this->radnikID = rand() % 89 + 10;
    this->plata = 0;
    this->pozicija = bezPozicije;
    strcpy_s(this->datumZaposljenja, "dd.mm.gggg");
    strcpy_s(this->strucnaSprema, "Nema");
}

void Radnik::setDatumZaposljenja() {
    std::cout << "\t\t\t\t  Datum zaposljenja: ";
    do {
        std::cin.getline(this->datumZaposljenja, sizeof this->datumZaposljenja);
        if (!provjeriDatum(this->datumZaposljenja)) std::cout << "\n\t\t\t\t  Greska - Datum nepravilno unesen.\n\t\t\t\t  Ponovo unesite datum (formata dd.mm.gggg): ";
    } while (!provjeriDatum(this->datumZaposljenja));
}

void Radnik::setStrucnaSprema() {
    std::cout << "\t\t\t\t  Strucna sprema: ";
    do {
        std::cin.getline(this->strucnaSprema, sizeof this->strucnaSprema);
        if (strlen(this->strucnaSprema) == 0 || strlen(this->strucnaSprema) < 3) {
            std::cout << "\n\t\t\t\t  Morate popuniti podatke." << std::endl;
            std::cout << "\n\t\t\t\t  Ponovo unesite strucnu spremu: ";
        }
    } while (strlen(this->strucnaSprema) == 0 || strlen(this->strucnaSprema) < 3);
}

void Radnik::vrijemeProvedenoUFirmi(const char* datumZaposljenjaRadnika) {

    int dan = vratiSpoj(0, 0, *datumZaposljenjaRadnika - '0', *(datumZaposljenjaRadnika + 1) - '0');
    int mje = vratiSpoj(0, 0, *(datumZaposljenjaRadnika + 3) - '0', *(datumZaposljenjaRadnika + 4) - '0');
    int god = vratiSpoj(*(datumZaposljenjaRadnika + 6) - '0', *(datumZaposljenjaRadnika + 7) - '0', *(datumZaposljenjaRadnika + 8) - '0', *(datumZaposljenjaRadnika + 9) - '0');
    
    time_t t = time(0);
    tm now;
    localtime_s(&now, &t);

    int godina = (now.tm_year + 1900), mjesec = (now.tm_mon + 1), trenutnidan = now.tm_mday;

    int dani_za_unesenu_godinu = 0;
    int dani_za_trenutnu_godinu = 0;

    dani_za_unesenu_godinu = pretvaranjeUDane(dan, mje, god);
    dani_za_trenutnu_godinu = pretvaranjeUDane(trenutnidan, mjesec, godina);

    provjeravanje(dan, mje, god, trenutnidan, mjesec, godina);
}

void Radnik::setPlata() {
    std::cout << "\t\t\t\t  Plata: ";
    do {
        std::cin >> this->plata;
        if (this->plata < 500 || this->plata > 3000) std::cout << "\n\t\t\t\t  Greska - Plata mora da bude u rasponu 500-3000.\n\t\t\t\t  Ponovo unesite platu: ";
    } while (this->plata < 500 || this->plata > 3000);
}

void Radnik::setPozicija() {
    std::cout << "\n\t\t\t\t  1. Direktor\n\t\t\t\t  2. Radnik za salterom";
    std::cout << "\n\t\t\t\t  Izbor: ";
    int izbor = 0;
    while (izbor < 1 || izbor > 2) {
        std::cin >> izbor;
        if (izbor < 1 || izbor > 2) std::cout << "\n\t\t\t\t  Greska - Nepravilan izbor (1-2).\n\t\t\t\t  Ponovo unesite izbor: ";
    }
    if (izbor == 1) pozicija = direktor;
    else pozicija = radnikZaSalterom;
}

void Radnik::setUsername() {
    std::cout << "\n\t\t\t\t  Unesite username: ";
    std::cin >> this->username;
}

void Radnik::setPassword() {
    std::cout << "\t\t\t\t  Unesite password: ";
    std::cin >> this->password;
}

void Radnik::setRadnikID(std::string radnikID) {
    this->radnikID = stringtoint(radnikID.c_str());
}

void Radnik::setDatumZaposljenja(std::string datumZaposljenja) {
    strcpy_s(this->datumZaposljenja, datumZaposljenja.c_str());
}

void Radnik::setStrucnaSprema(std::string strucnaSprema) {
    strcpy_s(this->strucnaSprema, strucnaSprema.c_str());
}

void Radnik::setPlata(const float plata) {
    this->plata = plata;
}

void Radnik::setPozicija(std::string pozicija) {
    if (stringtoint(pozicija.c_str()) == 0) this->pozicija = direktor;
    else this->pozicija = radnikZaSalterom;
}

void Radnik::setUsername(std::string username) {
    this->username = username;
}

void Radnik::setPassword(std::string password) {
    this->password = password;
}

int Radnik::getRadnikID() {
    return this->radnikID;
}

char* Radnik::getDatumZaposljenja() {
    return this->datumZaposljenja;
}

char* Radnik::getStrucnaSprema() {
    return this->strucnaSprema;
}

float Radnik::getPlata() {
    return this->plata;
}

pozicijaUFirmi Radnik::getPozicija() {
    return this->pozicija;
}

std::string Radnik::getUsername() {
    return this->username;
}

std::string Radnik::getPassword() {
    return this->password;
}

std::istream& operator>>(std::istream& stream, Radnik& r) {
    std::cout << "\n\t\t\t\t  Info - Unos podataka o radniku.\n";
    r.setIme();
    r.setPrezime();
    r.setJMBG();
    r.setMjestoRodjenja();
    r.setDatumRodjenja();
    r.setMjestoBoravka();
    r.setAdresa();
    r.setDrzavljanstvo();
    r.setDatumZaposljenja();
    r.setStrucnaSprema();
    r.setPlata();
    r.setPozicija();
    r.setUsername();
    r.setPassword();
    loading("Spremanje radnika...");
    return stream;
}

std::ostream& operator<<(std::ostream& stream, Radnik& r) {
    stream << "\n\t\t\t\t  Info - Podaci o Radniku!";
    stream << "\n\t\t\t\t  Username: " << r.getUsername();
    stream << "\n\t\t\t\t  Password: " << r.getPassword();
    stream << "\n\t\t\t\t  Ime: " << r.getIme();
    stream << "\n\t\t\t\t  Prezime " << r.getPrezime();
    stream << "\n\t\t\t\t  JMBG: " << r.getJMBG();
    stream << "\n\t\t\t\t  Datum rodjenja: " << r.getDatumRodjenja();
    stream << "\n\t\t\t\t  Mjesto rodjenja: " << r.getMjestoRodjenja();
    stream << "\n\t\t\t\t  Mjesto boravka: " << r.getMjestoBoravka();
    stream << "\n\t\t\t\t  Adresa: " << r.getAdresa();
    stream << "\n\t\t\t\t  Drzavljanstvo: " << r.getDrzavljanstvo();
    stream << "\n\t\t\t\t  Datum zaposljenja: " << r.getDatumZaposljenja();
    stream << "\n\t\t\t\t  Strucna sprema: " << r.getStrucnaSprema();
    stream << "\n\t\t\t\t  Plata: " << r.getPlata();
    stream << "\n\t\t\t\t  Pozicija u firmi: ";
    if (r.pozicija == 0) std::cout << "Direktor";
    else std::cout << "Radnik za salterom";
    r.vrijemeProvedenoUFirmi(r.getDatumZaposljenja());
    return stream;
}