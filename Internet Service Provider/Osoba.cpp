#include "Osoba.h"
#include "Funkcije.h"

Osoba::Osoba() {
    strcpy_s(this->ime, "Niko");
    strcpy_s(this->prezime, "Nikic");
    strcpy_s(this->JMBG, "9999999999999");
    strcpy_s(this->mjestoRodjenja, "Nigdje");
    strcpy_s(this->datumRodjenja, "dd.mm.gggg");
    strcpy_s(this->mjestoBoravka, "Nigdje");
    strcpy_s(this->adresa, "Adresa bb");
    strcpy_s(this->drzavljanstvo, "Nema");
}

void Osoba::setIme() {

    std::cout << "\t\t\t\t  Ime: ";
    do {
        std::cin.getline(this->ime, sizeof this->ime);
        if (strlen(this->ime) == 0 || strlen(this->ime) < 3) {
            std::cout << "\n\t\t\t\t  Morate popuniti podatke." << std::endl;
            std::cout << "\n\t\t\t\t  Ponovo unesite ime: ";
        }
    } while (strlen(this->ime) == 0 || strlen(this->ime) < 3);
}

void Osoba::setPrezime() {

    std::cout << "\t\t\t\t  Prezime: ";
    do {
        std::cin.getline(this->prezime, sizeof this->prezime);
        if (strlen(this->prezime) == 0 || strlen(this->prezime) < 3) {
            std::cout << "\n\t\t\t\t  Morate popuniti podatke." << std::endl;
            std::cout << "\n\t\t\t\t  Ponovo unesite prezime: ";
        }
    } while (strlen(this->prezime) == 0 || strlen(this->prezime) < 3);
}

void Osoba::setJMBG() {

    std::cout << "\t\t\t\t  JMBG: ";
    do {
        std::cin.getline(this->JMBG, sizeof this->JMBG);
        if (strlen(this->JMBG) != 13) {
            std::cout << "\n\t\t\t\t  Morate popuniti podatke." << std::endl;
            std::cout << "\n\t\t\t\t  Ponovo unesite JMBG: ";
        }
    } while (strlen(this->JMBG) != 13);
}

void Osoba::setDatumRodjenja() {

    this->datumRodjenja[0] = this->JMBG[0];
    this->datumRodjenja[1] = this->JMBG[1];
    this->datumRodjenja[2] = '.';
    this->datumRodjenja[3] = this->JMBG[2];
    this->datumRodjenja[4] = this->JMBG[3];
    this->datumRodjenja[5] = '.';
    if(this->JMBG[4] == 48) this->datumRodjenja[6] = '2';
    else this->datumRodjenja[6] = '1';
    this->datumRodjenja[7] = this->JMBG[4];
    this->datumRodjenja[8] = this->JMBG[5];
    this->datumRodjenja[9] = this->JMBG[6];
    while (!provjeriDatum(this->getDatumRodjenja()) || !provjeriJMBG(this->getJMBG(), this->getMjestoRodjenja())) {
        std::cout << "\n\t\t\t\t  Greska - Niste pravilno unijeli JMBG te iz tog razloga\n\t\t\t\t  nije moguce "
            << "odrediti datum rodjenja.";
        std::cout << "\n\t\t\t\t  Ponovo unesite svoj maticni broj.\n";
        this->setJMBG();
        this->setMjestoRodjenja();
        this->setDatumRodjenja();
    }
}

void Osoba::setMjestoRodjenja() {

    std::cout << "\t\t\t\t  Mjesto rodjenja: ";
    do {
        std::cin.getline(this->mjestoRodjenja, sizeof this->mjestoRodjenja);
        if (strlen(this->mjestoRodjenja) == 0 || strlen(this->mjestoRodjenja) < 3) {
            std::cout << "\n\t\t\t\t  Morate popuniti podatke." << std::endl;
            std::cout << "\n\t\t\t\t  Ponovo unesite mjesto_rodjenja: ";
        }
    } while (strlen(this->mjestoRodjenja) == 0 || strlen(this->mjestoRodjenja) < 3);
}

void Osoba::setMjestoBoravka() {

    std::cout << "\t\t\t\t  Mjesto boravka: ";
    do {
        std::cin.getline(this->mjestoBoravka, sizeof this->mjestoBoravka);
        if (strlen(this->mjestoBoravka) == 0 || strlen(this->mjestoBoravka) < 3) {
            std::cout << "\n\t\t\t\t  Morate popuniti podatke." << std::endl;
            std::cout << "\n\t\t\t\t  Ponovo unesite mjesto stanovanja: ";
        }
    } while (strlen(this->mjestoBoravka) == 0 || strlen(this->mjestoBoravka) < 3);
}

void Osoba::setAdresa() {

    std::cout << "\t\t\t\t  Adresa: ";
    do {
        std::cin.getline(this->adresa, sizeof this->adresa);
        if (strlen(this->adresa) == 0 || strlen(this->adresa) < 5) {
            std::cout << "\n\t\t\t\t  Morate popuniti podatke." << std::endl;
            std::cout << "\n\t\t\t\t  Ponovo unesite adresu stanovanja: ";
        }
    } while (strlen(this->adresa) == 0 || strlen(this->adresa) < 5);
}

void Osoba::setDrzavljanstvo() {

    std::cout << "\t\t\t\t  Drzavljanstvo: ";
    do {
        std::cin.getline(this->drzavljanstvo, sizeof this->drzavljanstvo);
        if (strlen(this->drzavljanstvo) == 0 || strlen(this->drzavljanstvo) < 3) {
            std::cout << "\n\t\t\t\t  Morate popuniti podatke." << std::endl;
            std::cout << "\n\t\t\t\t  Ponovo unesite drzavljanstvo: ";
        }
    } while (strlen(this->drzavljanstvo) == 0 || strlen(this->drzavljanstvo) < 3);
}

void Osoba::setIme(std::string ime) {
    strcpy_s(this->ime, ime.c_str());
}

void Osoba::setPrezime(std::string prezime) {
    strcpy_s(this->prezime, prezime.c_str());
}

void Osoba::setJMBG(std::string JMBG) {
    strcpy_s(this->JMBG, JMBG.c_str());
}

void Osoba::setDatumRodjenja(std::string datumRodjenja) {
    strcpy_s(this->datumRodjenja, datumRodjenja.c_str());
}

void Osoba::setMjestoRodjenja(std::string mjestoRodjenja) {
    strcpy_s(this->mjestoRodjenja, mjestoRodjenja.c_str());
}

void Osoba::setMjestoBoravka(std::string mjestoBoravka) {
    strcpy_s(this->mjestoBoravka, mjestoBoravka.c_str());
}

void Osoba::setAdresa(std::string adresa) {
    strcpy_s(this->adresa, adresa.c_str());
}

void Osoba::setDrzavljanstvo(std::string drzavljanstvo) {
    strcpy_s(this->drzavljanstvo, drzavljanstvo.c_str());
}

char* Osoba::getIme() {

    return this->ime;
}

char* Osoba::getPrezime() {

    return this->prezime;
}

char* Osoba::getJMBG() {

    return this->JMBG;
}

char* Osoba::getDatumRodjenja() {

    return this->datumRodjenja;
}

char* Osoba::getMjestoRodjenja() {

    return this->mjestoRodjenja;
}

char* Osoba::getMjestoBoravka() {

    return this->mjestoBoravka;
}

char* Osoba::getAdresa() {

    return this->adresa;
}

char* Osoba::getDrzavljanstvo() {

    return this->drzavljanstvo;
}