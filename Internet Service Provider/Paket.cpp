#include "Paket.h"

int Paket::brojPaketa = 0;

Paket::Paket() {
   
}

void Paket::setImePaketa() {
    std::cout << "\n\t\t\t\t  Ime: ";
    do {
        std::cin.getline(this->imePaketa, sizeof this->imePaketa);
        if (strlen(this->imePaketa) == 0 || strlen(this->imePaketa) < 3) {
            std::cout << "\n\t\t\t\t  Morate popuniti podatke.";
            std::cout << "\n\t\t\t\t  Ponovo unesite ime paketa: ";
        }
    } while (strlen(this->imePaketa) == 0 || strlen(this->imePaketa) < 3);
}

void Paket::setBrzinaInterneta() {
    std::cout << "\t\t\t\t  Brzina interneta: ";
    do {
        std::cin >> this->brzinaInterneta;
        if (this->brzinaInterneta < 0) {
            std::cout << "\n\t\t\t\t  Greska - Nepravilan unos. Brzina interneta ne moze biti negativan broj.";
            std::cout << "\n\t\t\t\t  Ponovo unesite brzinu interneta: ";
        }
    } while (this->brzinaInterneta < 0);
}

void Paket::setCijena() {
    std::cout << "\t\t\t\t  Cijena paketa: ";
    do {
        std::cin >> this->cijena;
        if (this->cijena < 0) {
            std::cout << "\n\t\t\t\t  Greska - Nepravilan unos. Cijena paketa ne moze biti negativan broj.";
            std::cout << "\n\t\t\t\t  Ponovo unesite cijenu paketa: ";
        }
    } while (this->cijena < 0);
}

void Paket::setDodatnaPonuda() {
    std::cout << "\t\t\t\t  Dodatna ponuda: ";
    do {
        std::cin.getline(this->dodatnaPonuda, sizeof this->dodatnaPonuda);
        if (strlen(this->dodatnaPonuda) == 0 || strlen(this->dodatnaPonuda) < 3) {
            std::cout << "\n\t\t\t\t  Morate popuniti podatke." << std::endl;
            std::cout << "\n\t\t\t\t  Ponovo unesite dodatnu ponudu: ";
        }
    } while (strlen(this->dodatnaPonuda) == 0 || strlen(this->dodatnaPonuda) < 3);
}

void Paket::setKoristenjeInterneta() {
    std::cout << "\t\t\t\t  Ogranicen(0)/Neogranicen(1): ";
    int izbor;
    do {
        std::cin >> izbor;
        if (izbor < 0 || izbor > 1) std::cout << "\n\t\t\t\t  Greska - Pogresan izbor. Izbor mora da bude 0 za ogranicen ili 1 za neogranicen internet.\nPonovo unesite izbor: ";
    } while (izbor < 0 || izbor > 1);
    std::cin.ignore();
    if(izbor == 0) this->koristenjeInterneta = ogranicen;
    else this->koristenjeInterneta = neogranicen;
}

void Paket::setImePaketa(std::string imePaketa) {
    strcpy_s(this->imePaketa, imePaketa.c_str());
}

void Paket::setBrzinaInterneta(std::string brzinaInterneta) {
    this->brzinaInterneta = stringtoint(brzinaInterneta.c_str());
}

void Paket::setCijena(std::string cijenaPaketa) {
    this->cijena = stringtoint(cijenaPaketa.c_str());
}

void Paket::setDodatnaPonuda(std::string dodatnaPonuda) {
    strcpy_s(this->dodatnaPonuda, dodatnaPonuda.c_str());
}

void Paket::setKoristenjeInterneta(const koristenje koristenjeInterneta) {
    this->koristenjeInterneta = koristenjeInterneta;
}

char* Paket::getImePaketa() {
    return this->imePaketa;
}

int Paket::getBrzinaInterneta() {
    return this->brzinaInterneta;
}

int Paket::getCijena() {
    return this->cijena;
}

char* Paket::getDodatnaPonuda() {
    return this->dodatnaPonuda;
}

koristenje Paket::getKoristenjeInterneta() {
    return this->koristenjeInterneta;
}

std::istream& operator>>(std::istream& stream, Paket& p) {
    std::cout << "\n\t\t\t\t  Info - Unos paketa\n";
    p.setImePaketa();
    p.setBrzinaInterneta();
    p.setCijena();
    p.setKoristenjeInterneta();
    p.setDodatnaPonuda();
    loading("Spremanje paketa...");
    return stream;
}

std::ostream& operator<<(std::ostream& stream, Paket& p) {
    stream << "\n\t\t\t\t  Info - Podaci o paketu";
    stream << "\n\t\t\t\t  Ime: " << p.getImePaketa();
    stream << "\n\t\t\t\t  Brzina interneta: " << p.getBrzinaInterneta() << " Mbps";
    stream << "\n\t\t\t\t  Cijena paketa: " << p.getCijena() << " KM";
    stream << "\n\t\t\t\t  Internet: " << p.getKoristenjeInterneta();
    if (strlen(p.getDodatnaPonuda()) != 0) stream << "\n\t\t\t\t  Dodatna ponuda: " << p.getDodatnaPonuda();
    return stream;
}
