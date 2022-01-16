#include "Funkcije.h"

bool provjeriDatum(const char* datum) {

    for (int i = 0; i <= 9; i++) {
        if (datum[2] == 46 && datum[5] == 46) continue;
        if (*(datum + i) - '0' == i) {
            continue;
        } else return false;
    }
    if (strlen(datum) != 10) return false; 
    else {
        if (datum[2] != 46 && datum[5] != 46) return false;
        int godina = 0;
        if (datum[6] == 49) godina = 1000;
        else godina = 2000;
        for (int i = 0; i < 10; i++) if (datum[7] == 49 + i) godina += 100 * (i + 1);
        for (int i = 0; i < 10; i++) if (datum[8] == 49 + i) godina += 10 * (i + 1);
        for (int i = 0; i < 10; i++) if (datum[9] == 49 + i) godina += i + 1;
        if (godina < 2000 || godina > 2022) return false;
        int februar = 28;
        if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) februar = 29;
        int daniUMjesecima[12] = { 31, februar, 31, 30, 31,30,31,31,30,31,30,31 };
        int dan = 0, mjesec = 0;
        for (int i = 0; i < 10; i++) if (datum[0] == 49 + i) dan = 10 * (i + 1);
        for (int i = 0; i < 10; i++) if (datum[1] == 49 + i) dan += i + 1;
        for (int i = 0; i < 10; i++) if (datum[3] == 49 + i) mjesec = 10 * (i + 1);
        for (int i = 0; i < 10; i++) if (datum[4] == 49 + i) mjesec += (i + 1);
        if (dan < 1 || dan > daniUMjesecima[mjesec - 1]) return false;
        if (mjesec < 1 || mjesec > 12) return false;
    }
    return true;
}

bool provjeriMail(const char* email) {
    int brojLudihA = 0;
    for (int i = 0; i < strlen(email); i++) if (email[i] == '@') brojLudihA++;
    if (brojLudihA > 1 || brojLudihA == 0) return false;

    bool tacanMail = true;

    if (email[strlen(email) - 3] != '.') tacanMail = false;
    if (email[strlen(email) - 2] != 'b') tacanMail = false;
    if (email[strlen(email) - 1] != 'a') tacanMail = false;
    if (tacanMail) return true;
    tacanMail = true;
    if (email[strlen(email) - 1] != 'm') tacanMail = false;
    if (email[strlen(email) - 2] != 'o') tacanMail = false;
    if (email[strlen(email) - 3] != 'c') tacanMail = false;
    if (email[strlen(email) - 4] != '.') tacanMail = false;

    return tacanMail;
}

int pretvaranjeUDane(int d, int m, int g) {
    m--;
    int dani = 0;
    dani += d;
    if (g % 4 == 0 && g % 100 != 0 || g % 400 == 0) {
        int daniUMjesecima[12] = { 31, 29, 31, 30, 31,30,31,31,30,31,30,31 };
        for (int i = 0; i < m; i++) dani += daniUMjesecima[i];
    } else {
        int daniUMjesecima[12] = { 31, 28, 31, 30, 31,30,31,31,30,31,30,31 };
        for (int i = 0; i < m; i++) dani += daniUMjesecima[i];
    }
    if (m == 0) {
        if (g % 4 == 0 && g % 100 != 0 || g % 400 == 0) { dani += 366; }
    }

    for (int i = 1; i < g; i++) {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
            dani += 366;
        } else {
            dani += 365;
        }
    }
    return dani;
}

int vratiSpoj(int broj, int broj2, int broj3, int broj4) {
    int spoj = 0;
    spoj = broj * 1000 + broj2 * 100 + broj3 * 10 + broj4;
    return spoj;
}

void provjeravanje(int d1, int m1, int g1, int d2, int m2, int g2) {
    int dan1 = d1, mjesec1 = m1, god1 = g1,
        dan2 = d2, mjesec2 = m2, god2 = g2;

    int razlikaDana, razlikaMjeseci, razlikaGodina;

    if (dan2 < dan1) {
        if (mjesec2 == 3) {
            if ((god2 % 4 == 0 && god2 % 100 != 0) || (god2 % 400 == 0)) {
                dan2 += 29;
            } else {
                dan2 += 28;
            }
        } else if (mjesec2 == 5 || mjesec2 == 7 || mjesec2 == 10 || mjesec2 == 12) dan2 += 30;
        else dan2 += 31;
        mjesec2 = mjesec2 - 1;
    }

    if (mjesec2 < mjesec1) {
        mjesec2 += 12;
        god2 -= 1;
    }

    razlikaDana = dan2 - dan1;
    razlikaMjeseci = mjesec2 - mjesec1;
    razlikaGodina = god2 - god1;

    if (razlikaGodina == 0) {
        if (razlikaMjeseci == 0) {
            if (razlikaDana == 0) std::cout << "\n\t\t\t\t  Vrijeme provedeno u firmi: prvi dan";
            else if (razlikaDana == 1) std::cout << "\n\t\t\t\t  Vrijeme provedeno u firmi: 1 dan";
            else std::cout << "\n\t\t\t\t  Vrijeme provedeno u firmi: " << razlikaDana << " dana.";
        } else if (razlikaMjeseci == 1) {
            std::cout << "\n\t\t\t\t  Vrijeme provedeno u firmi: 1 mjesec";
            if (razlikaDana == 0) std::cout << ".";
            else if (razlikaDana == 1) std::cout << " i 1 dan";
            else std::cout << " i " << razlikaDana << " dana.";
        } else if (razlikaMjeseci < 5) {
            std::cout << "\n\t\t\t\t  Vrijeme provedeno u firmi: " << razlikaMjeseci << " mjeseca";
            if (razlikaDana == 0) std::cout << ".";
            else if (razlikaDana == 1) std::cout << " i 1 dan";
            else std::cout << " i " << razlikaDana << " dana.";
        } else {
            std::cout << "\n\t\t\t\t  Vrijeme provedeno u firmi: " << razlikaMjeseci << " mjeseci";
            if (razlikaDana == 0) std::cout << ".";
            else if (razlikaDana == 1) std::cout << " i 1 dan";
            else std::cout << " i " << razlikaDana << " dana.";
        }
    } else {
        if (razlikaGodina == 1 || razlikaGodina > 5) {
            std::cout << "\n\t\t\t\t  Vrijeme provedeno u firmi: " << razlikaGodina << " godina";
            if (razlikaMjeseci == 0) {
                if (razlikaDana == 0) std::cout << ".";
                else if (razlikaDana == 1) std::cout << " i 1 dan";
                else std::cout << " i " << razlikaDana << " dana.";
            } else if (razlikaMjeseci == 1) {
                if (razlikaDana == 0) std::cout << " i 1 mjesec.";
                else if (razlikaDana == 1) std::cout << ", 1 mjesec i 1 dan";
                else std::cout << ", 1 mjesec i " << razlikaDana << " dana.";
            } else if (razlikaMjeseci < 5) {
                if (razlikaDana == 0) std::cout << " i " << razlikaMjeseci << " mjeseca.";
                else if (razlikaDana == 1) std::cout << ", " << razlikaMjeseci << " mjeseca i 1 dan";
                else std::cout << ", " << razlikaMjeseci << " mjeseca i " << razlikaDana << " dana.";
            } else {
                if (razlikaDana == 0) std::cout << " i " << razlikaMjeseci << " mjeseci.";
                else if (razlikaDana == 1) std::cout << ", " << razlikaMjeseci << " mjeseci i 1 dan";
                else std::cout << ", " << razlikaMjeseci << " mjeseci i " << razlikaDana << " dana.";
            }
        } else {
            std::cout << "\n\t\t\t\t  Vrijeme provedeno u firmi: " << razlikaGodina << " godine";
            if (razlikaMjeseci == 0) {
                if (razlikaDana == 0) std::cout << ".";
                else if (razlikaDana == 1) std::cout << " i 1 dan";
                else std::cout << " i " << razlikaDana << " dana.";
            } else if (razlikaMjeseci == 1) {
                if (razlikaDana == 0) std::cout << " i 1 mjesec.";
                else if (razlikaDana == 1) std::cout << ", 1 mjesec i 1 dan";
                else std::cout << ", 1 mjesec i " << razlikaDana << " dana.";
            } else if (razlikaMjeseci < 5) {
                if (razlikaDana == 0) std::cout << " i " << razlikaMjeseci << " mjeseca.";
                else if (razlikaDana == 1) std::cout << ", " << razlikaMjeseci << " mjeseca i 1 dan";
                else std::cout << ", " << razlikaMjeseci << " mjeseca i " << razlikaDana << " dana.";
            } else {
                if (razlikaDana == 0) std::cout << " i " << razlikaMjeseci << " mjeseci.";
                else if (razlikaDana == 1) std::cout << ", " << razlikaMjeseci << " mjeseci i 1 dan";
                else std::cout << ", " << razlikaMjeseci << " mjeseci i " << razlikaDana << " dana.";
            }
        }
    }
}

bool provjeriJMBG(const char* JMBG, char* mjesto) {
    int A = 0, B = 0, V = 0, G = 0, D = 0, H = 0, E = 0, F = 0, Z = 0, I = 0, J = 0, K = 0, L = 0;
    A = *(JMBG + 0) - '0';
    B = *(JMBG + 1) - '0';
    V = *(JMBG + 2) - '0';
    G = *(JMBG + 3) - '0';
    D = *(JMBG + 4) - '0';
    H = *(JMBG + 5) - '0';
    E = *(JMBG + 6) - '0';
    F = *(JMBG + 7) - '0';
    Z = *(JMBG + 8) - '0';
    I = *(JMBG + 9) - '0';
    J = *(JMBG + 10) - '0';
    K = *(JMBG + 11) - '0';
    L = 11 - ((7 * (A + E) + 6 * (B + F) + 5 * (V + Z) + 4 * (G + I) + 3 * (D + J) + 2 * (H + K)) % 11);
    int brat = *(JMBG + 12) - '0';
    if (L != brat) { return false; }
    int region = vratiSpoj(0, 0, *(JMBG + 7) - '0', *(JMBG + 8) - '0');
    if (region == 19) {

        if (std::strcmp(mjesto, "Zenica")) {
            return false;
        }
        return true;
    }
    if (region == 10) {

        if (std::strcmp(mjesto, "Banja Luka")) {
            return false;
        }
        return true;
    }
    if (region == 11) {

        if (std::strcmp(mjesto, "Bihac")) {
            return false;
        }
        return true;
    }
    if (region == 12) {

        if (std::strcmp(mjesto, "Doboj")) {
            return false;
        }
        return true;
    }
    if (region == 13) {

        if (std::strcmp(mjesto, "Gorazde")) {
            return false;
        }
        return true;
    }
    if (region == 14) {

        if (std::strcmp(mjesto, "Livno")) {
            return false;
        }
        return true;
    }
    if (region == 15) {

        if (std::strcmp(mjesto, "Mostar")) {
            return false;
        }
        return true;
    }
    if (region == 16) {

        if (std::strcmp(mjesto, "Prijedor")) {
            return false;
        }
        return true;
    }
    if (region == 17) {

        if (std::strcmp(mjesto, "Sarajevo")) {
            return false;
        }
        return true;
    }
    if (region == 18) {

        if (std::strcmp(mjesto, "Tuzla")) {
            return false;
        }
        return true;
    }
    return true;
}

void loading(const char* poruka) {

    std::cout << "\n\t\t\t\t  " << poruka << "\n";
    unsigned char znak = 219;
    std::cout << "\t\t\t\t ";
    for (int i = 0; i < 42; i++) {
        if (i == 0) std::cout << " ";
        std::cout << znak;
        Sleep(80);
    }
    std::cout << std::endl;
}

void klijentskiMeni() {

    int izbor;
    while (izbor = klijentskiIzbor()) {
        switch (izbor) {
        case 1: {
            std::ifstream brPaketa;
            brPaketa.open("Baza Podataka/Paketi/brojpaketa.txt");
            if (brPaketa.fail()) return; 
            else {
                brPaketa >> Paket::brojPaketa;
                brPaketa.close();
            }
            Paket* paketi = new Paket[Paket::brojPaketa];
            if (Paket::brojPaketa == 0) {
                std::cout << "\n\t\t\t\t  Trenutno nema paketa u ponudi. Molimo pokusajte kasnije.";
                std::cout << "\n\t\t\t\t  Pritisnite enter za nastavak...";
                _getch();
                break;
            } else {
                std::string temp;
                for (int i = 0; i < Paket::brojPaketa; i++) {
                    std::string imedatoteke = "Baza Podataka/Paketi/Paket_" + std::to_string(i + 1) + ".txt";
                    std::ifstream datoteka;
                    datoteka.open(imedatoteke);
                    getline(datoteka, temp);
                    std::cout << "\n\t\t\t\t  " << i + 1 << ". " << temp;
                    paketi[i].setImePaketa(temp);
                    getline(datoteka, temp);
                    paketi[i].setBrzinaInterneta(temp);
                    getline(datoteka, temp);
                    paketi[i].setCijena(temp);
                    getline(datoteka, temp);
                    paketi[i].setDodatnaPonuda(temp);
                    getline(datoteka, temp);
                    if (stringtoint(temp.c_str()) == 0) paketi[i].setKoristenjeInterneta(ogranicen);
                    else paketi[i].setKoristenjeInterneta(neogranicen);
                }
            }
            int izbor = 0;
            std::cout << "\n\t\t\t\t  0. Odustani";
            std::cout << "\n\t\t\t\t  Unesite koji paket zelite vidjeti (0 - " << Paket::brojPaketa << "): ";

            do {
                std::cin >> izbor;
                if (izbor < 0 || izbor > Paket::brojPaketa) std::cout << "\n\t\t\t\t  Greska - Pogresan izbor. Ponovo unesite: ";
            } while (izbor < 0 || izbor > Paket::brojPaketa);
            if (izbor == 0) {
                std::cout << "\n\t\t\t\t  Odustali ste od prikaza paketa.";
            } else std::cout << paketi[izbor - 1];
            std::cout << "\n\t\t\t\t  Pritisnite enter za nastavak...";
            _getch();
            delete[] paketi;
            break;
        }
        case 2: {
            std::ifstream brPaketa;
            brPaketa.open("Baza Podataka/Paketi/brojpaketa.txt");
            if (brPaketa.fail()) return;
            else {
                brPaketa >> Paket::brojPaketa;
                brPaketa.close();
            }
            Paket* paketi = new Paket[Paket::brojPaketa];
            if (Paket::brojPaketa == 0) {
                std::cout << "\n\t\t\t\t  Trenutno nema paketa u ponudi. Molimo pokusajte kasnije.";
                std::cout << "\n\t\t\t\t  Pritisnite enter za nastavak...";
                _getch();
                break;
            } else {
                std::string temp;
                for (int i = 0; i < Paket::brojPaketa; i++) {
                    std::string imedatoteke = "Baza Podataka/Paketi/Paket_" + std::to_string(i + 1) + ".txt";
                    std::ifstream datoteka;
                    datoteka.open(imedatoteke);
                    getline(datoteka, temp);
                    paketi[i].setImePaketa(temp);
                    getline(datoteka, temp);
                    paketi[i].setBrzinaInterneta(temp);
                    getline(datoteka, temp);
                    paketi[i].setCijena(temp);
                    getline(datoteka, temp);
                    paketi[i].setDodatnaPonuda(temp);
                    getline(datoteka, temp);
                    if (stringtoint(temp.c_str()) == 0) paketi[i].setKoristenjeInterneta(ogranicen);
                    else paketi[i].setKoristenjeInterneta(neogranicen);
                }
            }

            int brojZahtjeva = 0;
            std::ifstream brZahtjeva;
            brZahtjeva.open("Baza Podataka/Zahtjevi/brojzahtjeva.txt", std::ios::in);
            if (brZahtjeva.fail()) return;
            else {
                brZahtjeva >> brojZahtjeva;
                brZahtjeva.close();
            }

            Klijent k;
            std::cin >> k;
            for(int i = 0; i < Paket::brojPaketa; i++) std::cout << "\n\t\t\t\t  " << i + 1 << ". " << paketi[i].getImePaketa();
            int izbor = 0;

            std::cout << "\n\t\t\t\t  Unesite koji paket zelite (1 - " << Paket::brojPaketa << "): ";

            do {
                std::cin >> izbor;
                if (izbor < 1 || izbor > Paket::brojPaketa) std::cout << "\n\t\t\t\t  Greska - Pogresan izbor. Ponovo unesite: ";
            } while (izbor < 1 || izbor > Paket::brojPaketa);

            std::ofstream datoteka;

            std::string imeDatoteke = "Baza Podataka/Zahtjevi/Zahtjev_";
            imeDatoteke += std::to_string(brojZahtjeva+1);
            imeDatoteke += ".txt";

            datoteka.open(imeDatoteke, std::fstream::in | std::fstream::out | std::fstream::app);
            if (datoteka.fail()) std::cout << "\n\t\t\t\t  Greska - Nije moguce otvoriti datoteku.";
            else {
                datoteka << k.getKlijentID() << std::endl;
                datoteka << k.getIme() << std::endl;
                datoteka << k.getPrezime() << std::endl;
                datoteka << k.getJMBG() << std::endl;
                datoteka << k.getMjestoRodjenja() << std::endl;
                datoteka << k.getDatumRodjenja() << std::endl;
                datoteka << k.getMjestoBoravka() << std::endl;
                datoteka << k.getAdresa() << std::endl;
                datoteka << k.getDrzavljanstvo() << std::endl;
                datoteka << k.getEmail() << std::endl;
                datoteka << k.getStanje() << std::endl;
                datoteka << paketi[izbor-1].getBrzinaInterneta() << std::endl;
                datoteka << paketi[izbor-1].getImePaketa() << std::endl;
                datoteka << paketi[izbor-1].getCijena() << std::endl;
                datoteka << paketi[izbor-1].getDodatnaPonuda() << std::endl;
                datoteka << paketi[izbor-1].getKoristenjeInterneta() << std::endl;
                datoteka.close();
                datoteka.open("Baza Podataka/Zahtjevi/brojzahtjeva.txt");
                datoteka << brojZahtjeva + 1;
                datoteka.close();
            }
            std::cout << "\n\t\t\t\t  Info - Zahtjev uspjesno predan.";
            std::cout << "\n\t\t\t\t  Pritisnite enter za nastavak...";
            _getch();
            delete[] paketi;
            break;
        }
        case 3: {

            auto brojUgovora = std::make_shared<int>();
            auto pom = std::make_shared<int>(0);
            auto nasao = std::make_shared<bool>(false);
            auto ID = std::make_shared<int>(0);
            std::vector<int> IDovi;

            std::ifstream brUgovora;
            brUgovora.open("Baza Podataka/Ugovori/brojugovora.txt");
            if (brUgovora.fail()) return;
            else {
                brUgovora >> *brojUgovora;
                brUgovora.close();
            }

            Klijent* Klijenti = new Klijent[*brojUgovora];
            Paket* Paketi = new Paket[*brojUgovora];

            try {

                if (*brojUgovora == 0) throw "\n\t\t\t\t  Nema ugovora u bazi podataka.";

                std::cout << "\n\t\t\t\t  Unesite vas ID da bi ste ponistili ugovor: ";
                do {
                    std::cin >> *ID;
                    if (*ID < 0 || *ID > 100) std::cout << "\n\t\t\t\t  Greska - Pogresan unos. Ponovite unos ID-a: ";
                } while (*ID < 0 || *ID > 100);

                brUgovora.open("Baza Podataka/Ugovori/zahtjevizabrisanjemugovora.txt");
                if (brUgovora.fail()) return;
                else while (brUgovora >> *pom) IDovi.push_back(*pom);
                brUgovora.close();
                for (int i = 0; i < IDovi.size(); i++) {
                    if (*ID == IDovi[i]) {
                        *nasao = true;
                        break;
                    }
                }
                if (*nasao) {
                    std::cout << "\n\t\t\t\t  Vec ste podnijeli zahtjev za brisanjem ugovora.";
                    std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                    _getch();
                    break;
                }

                for (int i = 0; i < *brojUgovora; i++) {
                    std::string imeDatoteke = "Baza Podataka/Ugovori/Ugovor_" + std::to_string(i + 1) + ".txt";
                    std::ifstream datoteka;
                    datoteka.open(imeDatoteke);
                    if (datoteka.fail()) continue;
                    std::string temp;
                    getline(datoteka, temp);
                    Klijenti[i].setKlijentID(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setIme(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setPrezime(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setJMBG(temp.c_str());
                    getline(datoteka, temp);
                    Klijenti[i].setMjestoRodjenja(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setDatumRodjenja(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setMjestoBoravka(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setAdresa(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setDrzavljanstvo(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setEmail(temp);
                    getline(datoteka, temp);
                    if (stringtoint(temp.c_str()) == 1) Klijenti[i].setStanje(penzioner);
                    else if (stringtoint(temp.c_str()) == 2) Klijenti[i].setStanje(student);
                    else if (stringtoint(temp.c_str()) == 3) Klijenti[i].setStanje(nezaposlen);
                    else Klijenti[i].setStanje(nista);
                    getline(datoteka, temp);
                    Paketi[i].setImePaketa(temp);
                    getline(datoteka, temp);
                    Paketi[i].setBrzinaInterneta(temp);
                    getline(datoteka, temp);
                    Paketi[i].setCijena(temp);
                    getline(datoteka, temp);
                    Paketi[i].setDodatnaPonuda(temp);
                    getline(datoteka, temp);
                    if (stringtoint(temp.c_str()) == 0) Paketi[i].setKoristenjeInterneta(ogranicen);
                    else Paketi[i].setKoristenjeInterneta(neogranicen);
                    datoteka.close();
                }
            } catch (const char* Greska) {
               std::cout << Greska;
               std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
               _getch();
               break;
            } catch (...) {
              std::cout << "\n\t\t\t\t  Nepoznata greska.";
              std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
              _getch();
              break;
            }

            *nasao = false;

            for (int i = 0; i < *brojUgovora; i++) {
                if (*ID == Klijenti[i].getKlijentID()) {
                    *nasao = true;

                    std::ofstream upisiID;
                    upisiID.open("Baza Podataka/Ugovori/zahtjevizabrisanjemugovora.txt", std::ofstream::app);
                    if (upisiID.fail()) {
                        return;
                    } else {
                        upisiID << *ID << std::endl;
                        upisiID.close();
                    }
                    std::cout << "\n\t\t\t\t  Uspjesno ste podnijeli zahtjev za brisanjem ugovora.";
                    std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                    _getch();
                    break;
                }
            }

            if (!*nasao) {
                std::cout << "\n\t\t\t\t  Vi niste nikada potpisali ugovor.";
                std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                _getch();
                break;
            }
            break;
        }
        case 4: {
            administratorskiMeni();
            break;
        }
        default: {
            return;
            break;
        }
        }
    }
}

void administratorskiMeni() {

    system("cls");
    std::ifstream brRadnika;
    brRadnika.open("Baza Podataka/Radnici/brojradnika.txt", std::ios::in);
    if (brRadnika.fail()) return;
    else {
        brRadnika >> Radnik::brojRadnika;
        brRadnika.close();
    }
    Radnik* radnici = new Radnik[Radnik::brojRadnika];
    int indeksi = 0;
    std::ifstream datotekaRadnici;
    for (int i = 0; i < Radnik::brojRadnika; i++) {
        std::string pomocna = "Baza Podataka/Radnici/Radnik_";
        pomocna += std::to_string(i+1) + ".txt";
        datotekaRadnici.open(pomocna);
        if (datotekaRadnici.fail()) continue;
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setRadnikID(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setUsername(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setPassword(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setIme(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setPrezime(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setJMBG(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setMjestoRodjenja(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setDatumRodjenja(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setMjestoBoravka(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setAdresa(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setDrzavljanstvo(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setDatumZaposljenja(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setStrucnaSprema(pomocna);
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setPlata(stringtoint(pomocna.c_str()));
        getline(datotekaRadnici, pomocna);
        radnici[indeksi].setPozicija(pomocna);
        datotekaRadnici.close();
        indeksi++;
    }
    int indexRadnika = 0;
    std::string username, sifra, usernamee, sifraa;
    bool prosao = false;
    int pokusaji = 5;
    std::cout << "\t\t\t\t      __                _     \n";
    std::cout << "\t\t\t\t     / /   ____  ____ _(_)___ \n";
    std::cout << "\t\t\t\t    / /   / __ \\/ __ `/ / __ \\\n";
    std::cout << "\t\t\t\t   / /___/ /_/ / /_/ / / / / /\n";
    std::cout << "\t\t\t\t  /_____/\\____/\\__, /_/_/ /_/\n";
    std::cout << "\t\t\t\t              /____/          \n";
    std::cout << "\t\t\t\t __________________________________________________________\n\n";
    while (pokusaji > 0) {
        std::cout << "\t\t\t\t  Unesite username: ";
        std::cin >> username;
        std::cin.ignore();
        std::cout << "\t\t\t\t  Unesite sifru: ";
        sifra.clear();
        char znak;
        while (znak = _getch()) {
            if (znak != 13) std::cout << "*";
            sifra += znak;
            if (znak == 13) break;
        }
        sifra.erase(sifra.length() - 1);
        usernamee = username, sifraa = sifra;
        if (Radnik::brojRadnika == 0 || (username == "root" && sifra == "root")) {
            if (provjera(username, sifra)) break;
            else pokusaji--;
        } else {
            indexRadnika = 0;
            for (int i = 0; i < Radnik::brojRadnika; i++) {
                usernamee = username;
                sifraa = sifra;
                if (strcmp(usernamee.c_str(), radnici[i].getUsername().c_str()) == 0) usernamee = "root";
                else usernamee = "noroot";
                if (strcmp(sifraa.c_str(), radnici[i].getPassword().c_str()) == 0) sifraa = "root";
                else sifraa = "noroot";
                if (provjera(usernamee, sifraa)) {
                    username = "root";
                    sifra = "root";
                    indexRadnika = i;
                    prosao = true;
                    break;
                }
            }
            if (provjera(username, sifra)) break;
            else pokusaji--;
        }

        std::cout << std::endl;
        if (pokusaji == 0) {
            std::cout << "\n\t\t\t\t  Previse pokusaja login-a.";
            std::cout << "\n\t\t\t\t  Izlazak iz sistema";
            for (int i = 0; i < 3; i++) {
                std::cout << ".";
                Sleep(1000);
            }
            resetujBazu();
            exit(0);
        } 
    }
    if (provjera(username, sifra)) {
        std::cout << std::endl;
        loading("Ucitavanje Administratorskih postavki:");
        system("cls");
        int izbor;
        while (izbor = administratorskiIzbor()) {
            switch (izbor) {
            case 1: {
                int brojZahtjeva = 0;
                std::ifstream brZahtjeva;
                brZahtjeva.open("Baza Podataka/Zahtjevi/brojzahtjeva.txt", std::ios::in);
                if (brZahtjeva.fail()) {
                    return;
                } else {
                    brZahtjeva >> brojZahtjeva;
                    brZahtjeva.close();
                }
                Klijent* Klijenti = new Klijent[brojZahtjeva];
                Paket* Paketi = new Paket[brojZahtjeva];
                for (int i = 0; i < brojZahtjeva; i++) {
                    std::string imeDatoteke = "Baza Podataka/Zahtjevi/Zahtjev_" + std::to_string(i+1) + ".txt";
                    std::ifstream datoteka;
                    datoteka.open(imeDatoteke);
                    if (datoteka.fail()) {
                        continue;
                    } 
                    std::string temp;
                    getline(datoteka, temp);
                    Klijenti[i].setKlijentID(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setIme(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setPrezime(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setJMBG(temp.c_str());
                    getline(datoteka, temp);
                    Klijenti[i].setMjestoRodjenja(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setDatumRodjenja(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setMjestoBoravka(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setAdresa(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setDrzavljanstvo(temp);
                    getline(datoteka, temp);
                    Klijenti[i].setEmail(temp);
                    getline(datoteka, temp);
                    if (stringtoint(temp.c_str()) == 1) Klijenti[i].setStanje(penzioner);
                    else if (stringtoint(temp.c_str()) == 2) Klijenti[i].setStanje(student);
                    else if (stringtoint(temp.c_str()) == 3) Klijenti[i].setStanje(nezaposlen);
                    else Klijenti[i].setStanje(nista);
                    getline(datoteka, temp);
                    Paketi[i].setBrzinaInterneta(temp);
                    getline(datoteka, temp);
                    Paketi[i].setImePaketa(temp);
                    getline(datoteka, temp);
                    Paketi[i].setCijena(temp);
                    getline(datoteka, temp);
                    Paketi[i].setDodatnaPonuda(temp);
                    getline(datoteka, temp);
                    if (stringtoint(temp.c_str()) == 0) Paketi[i].setKoristenjeInterneta(ogranicen);
                    else Paketi[i].setKoristenjeInterneta(neogranicen);
                    datoteka.close();
                }
                if (brojZahtjeva == 0) {
                    std::cout << "\n\t\t\t\t  Niko nije podnio zahtjev za Internetom.";
                    std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                    _getch();
                }
                else {
                    for (int i = 0; i < brojZahtjeva; i++) std::cout << "\n\t\t\t\t  " << i + 1 << ". " << Klijenti[i].getIme() << " " << Klijenti[i].getPrezime() << std::endl;
                    std::cout << "\n\t\t\t\t  -1. Odustani";
                    int izbor = 0, pokusaji = 0;
                    std::cout << "\n\t\t\t\t  Unesite redni broj kojem klijentu zelite odobriti ugovor: ";
                    do {
                        std::cin >> izbor;
                        if (izbor < -1 || izbor > brojZahtjeva) {
                            std::cout << "\n\t\t\t\t  Greska - Pogresan izbor. Ponovo unesite redni broj: ";
                            pokusaji++;
                        }
                        if (pokusaji == 5) {
                            std::cout << "\n\t\t\t\t  Previse pokusaja. Vraceni ste u meni.";
                            izbor = -1;
                            break;
                        }
                    } while (izbor < -1 || izbor > brojZahtjeva || pokusaji == 5);
                    if (izbor == -1) break;
                    else {

                        int brojUgovora = 0;
                        std::ifstream brUgovora;
                        brUgovora.open("Baza Podataka/Ugovori/brojugovora.txt", std::ios::in);
                        if (brUgovora.fail()) {
                            return;
                        } else {
                            brUgovora >> brojUgovora;
                            brUgovora.close();
                        }
                        std::ofstream datoteka;
                        std::string imeDatoteke = "Baza Podataka/Ugovori/Ugovor_";
                        imeDatoteke += std::to_string(brojUgovora+1);
                        imeDatoteke += ".txt";
                        datoteka.open(imeDatoteke, std::fstream::in | std::fstream::out | std::ios::trunc);

                        if (datoteka.fail()) std::cout << "\n\t\t\t\t  Greska - Nije moguce otvoriti datoteku.";
                        else {
                            datoteka << Klijenti[izbor - 1].getKlijentID() << std::endl;
                            datoteka << Klijenti[izbor - 1].getIme() << std::endl;
                            datoteka << Klijenti[izbor - 1].getPrezime() << std::endl;
                            datoteka << Klijenti[izbor - 1].getJMBG() << std::endl;
                            datoteka << Klijenti[izbor - 1].getMjestoRodjenja() << std::endl;
                            datoteka << Klijenti[izbor - 1].getDatumRodjenja() << std::endl;
                            datoteka << Klijenti[izbor - 1].getMjestoBoravka() << std::endl;
                            datoteka << Klijenti[izbor - 1].getAdresa() << std::endl;
                            datoteka << Klijenti[izbor - 1].getDrzavljanstvo() << std::endl;
                            datoteka << Klijenti[izbor - 1].getEmail() << std::endl;
                            datoteka << Klijenti[izbor - 1].getStanje() << std::endl;
                            datoteka << Paketi[izbor - 1].getBrzinaInterneta() << std::endl;
                            datoteka << Paketi[izbor - 1].getImePaketa() << std::endl;
                            datoteka << Paketi[izbor - 1].getCijena() << std::endl;
                            datoteka << Paketi[izbor - 1].getDodatnaPonuda() << std::endl;
                            datoteka << Paketi[izbor - 1].getKoristenjeInterneta() << std::endl;
                            if (!prosao) datoteka << "Root korisnik odobrio zahtjev." << std::endl;
                            else datoteka << radnici[indexRadnika].getIme() << " " << radnici[indexRadnika].getPrezime() << std::endl;
                            time_t t = time(0);
                            tm now;
                            localtime_s(&now, &t);
                            int godina = (now.tm_year + 1900), mjesec = (now.tm_mon + 1), trenutnidan = now.tm_mday;
                            if(trenutnidan < 10 && mjesec < 10) datoteka << "0" << trenutnidan << ".0" << mjesec << "." << godina;
                            else if(trenutnidan < 10 && mjesec > 10) datoteka << "0" << trenutnidan << "." << mjesec << "." << godina;
                            else if (trenutnidan > 10 && mjesec < 10) datoteka << trenutnidan << ".0" << mjesec << "." << godina;
                            else datoteka << trenutnidan << "." << mjesec << "." << godina;
                            datoteka.close();
                            datoteka.open("Baza Podataka/Ugovori/brojugovora.txt");
                            datoteka << brojUgovora + 1;
                            datoteka.close();
                            imeDatoteke = "Baza Podataka/Zahtjevi/Zahtjev_" + std::to_string(izbor) + ".txt";
                            remove(imeDatoteke.c_str());
                            for (int i = izbor; i < brojZahtjeva; i++) {
                                std::string preimenujFajlove = "Baza Podataka/Zahtjevi/Zahtjev_" + std::to_string(i + 1) + ".txt";
                                rename(preimenujFajlove.c_str(), imeDatoteke.c_str());
                                imeDatoteke = preimenujFajlove;
                            }
                            datoteka.open("Baza Podataka/Zahtjevi/brojzahtjeva.txt");
                            if (brojZahtjeva == 0 || brojZahtjeva == 1) datoteka << 0;
                            else datoteka << brojZahtjeva - 1;
                            std::cout << "\n\t\t\t\t  Uspjesno ste odobrili ugovor klijentu " << Klijenti[izbor - 1].getIme() << " " << Klijenti[izbor - 1].getPrezime() << "." << std::endl;
                            std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                            _getch();
                        }
                    }
                    delete[] Klijenti;
                    delete[] Paketi;
                    system("cls");
                }
                break;
            }
            case 2: {
                

                auto brojUgovora = std::make_shared<int>();

                std::ifstream brUgovora;
                brUgovora.open("Baza Podataka/Ugovori/brojugovora.txt");
                if (brUgovora.fail()) return; 
                else {
                    brUgovora >> *brojUgovora;
                    brUgovora.close();
                }

                if (*brojUgovora == 0) {
                    std::cout << "\n\t\t\t\t  Info - Nema ugovora u Bazi podataka.";
                    std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                    _getch();
                } else {
                    Klijent* Klijenti = new Klijent[*brojUgovora];
                    Paket* Paketi = new Paket[*brojUgovora];

                    for (int i = 0; i < *brojUgovora; i++) {
                        std::string imeDatoteke = "Baza Podataka/Ugovori/Ugovor_" + std::to_string(i + 1) + ".txt";
                        std::ifstream datoteka;
                        datoteka.open(imeDatoteke);
                        if (datoteka.fail()) {
                            continue;
                        }
                        std::string temp;
                        getline(datoteka, temp);
                        Klijenti[i].setKlijentID(temp);
                        getline(datoteka, temp);
                        Klijenti[i].setIme(temp);
                        getline(datoteka, temp);
                        Klijenti[i].setPrezime(temp);
                        getline(datoteka, temp);
                        Klijenti[i].setJMBG(temp.c_str());
                        getline(datoteka, temp);
                        Klijenti[i].setMjestoRodjenja(temp);
                        getline(datoteka, temp);
                        Klijenti[i].setDatumRodjenja(temp);
                        getline(datoteka, temp);
                        Klijenti[i].setMjestoBoravka(temp);
                        getline(datoteka, temp);
                        Klijenti[i].setAdresa(temp);
                        getline(datoteka, temp);
                        Klijenti[i].setDrzavljanstvo(temp);
                        getline(datoteka, temp);
                        Klijenti[i].setEmail(temp);
                        getline(datoteka, temp);
                        if (stringtoint(temp.c_str()) == 1) Klijenti[i].setStanje(penzioner);
                        else if (stringtoint(temp.c_str()) == 2) Klijenti[i].setStanje(student);
                        else if (stringtoint(temp.c_str()) == 3) Klijenti[i].setStanje(nezaposlen);
                        else Klijenti[i].setStanje(nista);
                        getline(datoteka, temp);
                        Paketi[i].setImePaketa(temp);
                        getline(datoteka, temp);
                        Paketi[i].setBrzinaInterneta(temp);
                        getline(datoteka, temp);
                        Paketi[i].setCijena(temp);
                        getline(datoteka, temp);
                        Paketi[i].setDodatnaPonuda(temp);
                        getline(datoteka, temp);
                        if (stringtoint(temp.c_str()) == 0) Paketi[i].setKoristenjeInterneta(ogranicen);
                        else Paketi[i].setKoristenjeInterneta(neogranicen);
                        datoteka.close();
                        std::cout << "\n\t\t\t\t  " << i + 1 << ". ID klijenta: " << Klijenti[i].getKlijentID() << " Ime i prezime: " << Klijenti[i].getIme() << " " << Klijenti[i].getPrezime() << std::endl;
                    }
                    std::cout << "\n\t\t\t\t  Pritisnite bilo koju tipku da se vratite u Admin meni.";
                    _getch();
                }
                system("cls");
                break;
            }
            case 3: {

                auto brojUgovora = std::make_shared<int>();

                std::ifstream brUgovora;

                brUgovora.open("Baza Podataka/Ugovori/brojugovora.txt");
                if (brUgovora.fail()) {
                    return;
                } else {
                    brUgovora >> *brojUgovora;
                    brUgovora.close();
                }

                if (*brojUgovora == 0) std::cout << "\n\t\t\t\t  Info - Nema ugovora u bazi podataka.";
                else {
                    auto pom = std::make_shared<int>(0);
                    auto nasao = std::make_shared<bool>(false);
                    std::vector<int> IDovi;

                    brUgovora.open("Baza Podataka/Ugovori/zahtjevizabrisanjemugovora.txt");
                    if (brUgovora.fail()) return;
                    else while (brUgovora >> *pom) IDovi.push_back(*pom);
                    brUgovora.close();

                    if (*brojUgovora == 0) {
                        std::cout << "\n\t\t\t\t  Info - Nema ugovora u Bazi podataka.";

                    }

                    auto pomocniKlijent = std::make_shared<Klijent>();
                    int brojacc = 0;
                    std::vector <int> pamtiDatoteke;
                    for (int i = 0; i < *brojUgovora; i++) {
                        std::string imeDatoteke = "Baza Podataka/Ugovori/Ugovor_" + std::to_string(i + 1) + ".txt";
                        std::ifstream datoteka;
                        datoteka.open(imeDatoteke);
                        std::string temp;
                        getline(datoteka, temp);
                        pomocniKlijent->setKlijentID(temp);
                        getline(datoteka, temp);
                        pomocniKlijent->setIme(temp);
                        getline(datoteka, temp);
                        pomocniKlijent->setPrezime(temp);
                        datoteka.close();
                        for (int j = 0; j < IDovi.size(); j++) if (IDovi[j] == pomocniKlijent->getKlijentID()) {
                            std::cout << "\n\t\t\t\t  " << ++brojacc << ". ID: " << pomocniKlijent->getKlijentID() << " Ime i prezime: " << pomocniKlijent->getIme() << " " << pomocniKlijent->getPrezime();
                            pamtiDatoteke.push_back(i + 1);
                        }
                    }
                    std::cout << "\n\t\t\t\t  0. Odustani";
                    std::cout << "\n\t\t\t\t  Unesite koji ugovor zelite da ponistite (0 - " << IDovi.size() << "): ";
                    auto izbor = std::make_shared<int>();
                    do {
                        std::cin >> *izbor;
                        if (*izbor < 0 || *izbor > IDovi.size()) {
                            std::cout << "\n\t\t\t\t  Pogresan izbor. Molimo ponovite unos: ";
                        }
                    } while (*izbor < 0 || *izbor > IDovi.size());

                    if (*izbor == 0) {
                        std::cout << "\n\t\t\t\t  Odustali ste od ponistavanja ugovora.";
                        std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                        _getch();
                        break;
                    }

                    std::string imeDatoteke = "Baza Podataka/Ugovori/Ugovor_" + std::to_string(pamtiDatoteke[*izbor - 1]) + ".txt";
                    auto pomocniID = std::make_shared<int>(0);
                    std::ifstream dobijID;
                    dobijID.open(imeDatoteke);
                    dobijID >> *pomocniID;
                    std::string pomocna;
                    getline(dobijID, pomocna);
                    pomocniKlijent->setIme(pomocna);
                    getline(dobijID, pomocna);
                    pomocniKlijent->setPrezime(pomocna);
                    dobijID.close();
                    remove(imeDatoteke.c_str());
                    std::ofstream outfile;
                    outfile.open("Baza Podataka/Ugovori/zahtjevizabrisanjemugovora.txt", std::ofstream::out | std::ofstream::trunc);
                    outfile.close();
                    std::ofstream otvoriFile;
                    otvoriFile.open("Baza Podataka/Ugovori/zahtjevizabrisanjemugovora.txt");
                    for (int i = 0; i < IDovi.size(); i++) {
                        if (*pomocniID == IDovi[i]) continue;
                        otvoriFile << IDovi[i] << std::endl;
                    }
                    otvoriFile.close();

                    if (*izbor == 0) {
                        for (int i = 0; i < *brojUgovora; i++) {

                            std::string preimenujFajlove = "Baza Podataka/Ugovori/Ugovor_" + std::to_string(i + 1) + ".txt";
                            rename(preimenujFajlove.c_str(), imeDatoteke.c_str());
                            imeDatoteke = preimenujFajlove;
                        }
                    } else {
                        for (int i = *izbor; i < *brojUgovora; i++) {

                            std::string preimenujFajlove = "Baza Podataka/Ugovori/Ugovor_" + std::to_string(i + 1) + ".txt";
                            rename(preimenujFajlove.c_str(), imeDatoteke.c_str());
                            imeDatoteke = preimenujFajlove;
                        }
                    }
                    std::cout << "\n\t\t\t\t  Uspjesno ste ponistili ugovor klijentu sa ID-om " << *pomocniID;
                    std::ofstream datoteka;
                    datoteka.open("Baza Podataka/Ugovori/brojugovora.txt");
                    datoteka << *brojUgovora - 1;
                    datoteka.close();
                }
                std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                _getch();
                break;
            }
            case 4: {

                auto noviPaket = std::make_shared<Paket>();
                std::cin >> *noviPaket;

                std::ofstream datoteka;

                std::ifstream brPaketa;
                brPaketa.open("Baza Podataka/Paketi/brojpaketa.txt");
                if (brPaketa.fail()) {
                    return;
                } else {
                    brPaketa >> Paket::brojPaketa;
                    brPaketa.close();
                }

                std::string imeDatoteke = "Baza Podataka/Paketi/Paket_";
                imeDatoteke += std::to_string(Paket::brojPaketa + 1);
                imeDatoteke += ".txt";
                datoteka.open(imeDatoteke, std::fstream::in | std::fstream::out | std::ios::trunc);
                
                try {
                    if (datoteka.fail()) throw "\n\t\t\t\t  Greska - Nije moguce otvoriti datoteku.";
                    else {
                        datoteka << noviPaket->getImePaketa() << std::endl;
                        datoteka << noviPaket->getBrzinaInterneta() << std::endl;
                        datoteka << noviPaket->getCijena() << std::endl;
                        datoteka << noviPaket->getDodatnaPonuda() << std::endl;
                        datoteka << noviPaket->getKoristenjeInterneta() << std::endl;
                        datoteka.close();
                        datoteka.open("Baza Podataka/Paketi/brojpaketa.txt");
                        datoteka << Paket::brojPaketa + 1;
                        datoteka.close();
                    }
                } catch (const char* Greska) {
                    std::cout << *Greska << std::endl;
                } catch (...) {
                    std::cout << "\n\t\t\t\t  Greska - Nepoznata greska";
                }
                std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                _getch();
                system("cls");
                break;
            }
            case 5: {

                std::ifstream brPaketa;
                brPaketa.open("Baza Podataka/Paketi/brojpaketa.txt");
                if (brPaketa.fail()) {
                    return;
                } else {
                    brPaketa >> Paket::brojPaketa;
                    brPaketa.close();
                }

                Paket* paketi = new Paket[Paket::brojPaketa];

                if (Paket::brojPaketa == 0) {
                    std::cout << "\n\t\t\t\t  Info - Nema paketa za urediti.";
                    std::cout << "\n\t\t\t\t  Pritisnite enter za nastavak...";
                    _getch();
                    break;
                } else {
                    std::string temp;
                    for (int i = 0; i < Paket::brojPaketa; i++) {
                        std::string imedatoteke = "Baza Podataka/Paketi/Paket_" + std::to_string(i + 1) + ".txt";
                        std::ifstream datoteka;
                        datoteka.open(imedatoteke);
                        getline(datoteka, temp);
                        paketi[i].setImePaketa(temp);
                        std::cout << "\n\t\t\t\t  " << i + 1 << ". " << paketi[i].getImePaketa();
                        getline(datoteka, temp);
                        paketi[i].setBrzinaInterneta(temp);
                        getline(datoteka, temp);
                        paketi[i].setCijena(temp);
                        getline(datoteka, temp);
                        paketi[i].setDodatnaPonuda(temp);
                        getline(datoteka, temp);
                        if (stringtoint(temp.c_str()) == 0) paketi[i].setKoristenjeInterneta(ogranicen);
                        else paketi[i].setKoristenjeInterneta(neogranicen);
                    }
                }
                std::cout << "\n\t\t\t\t  0. Odustani";
                int izbor = 0;

                std::cout << "\n\t\t\t\t  Unesite koji paket zelite da uredite (0 - " << Paket::brojPaketa << "): ";

                do {
                    std::cin >> izbor;
                    if (izbor < 0 || izbor > Paket::brojPaketa) std::cout << "Greska - Pogresan izbor. Ponovo unesite: ";       
                } while (izbor < 0 || izbor > Paket::brojPaketa);

                if (izbor == 0) {
                    std::cout << "\n\t\t\t\t  Odustali ste od uredjivanja paketa.";
                    std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                    _getch();
                    break;
                }

                std::cout << "\n\t\t\t\t  1. Promjeni ime paketa\n\t\t\t\t  2. Promjeni brzinu Interneta\n\t\t\t\t  3. Promjeni cijenu paketa\n\t\t\t\t  4. Promjeni dodatnu ponudu\n\t\t\t\t  5. Promjeni koristenje interneta\n\t\t\t\t  0. Odustani\n\t\t\t\t  Unesite opciju: ";

                int izbor2 = 0;

                do {
                    std::cin >> izbor2;
                    if (izbor2 < 0 || izbor2 > 5) std::cout << "\n\t\t\t\t  Greska - Pogresan izbor. Ponovo unesite izbor: ";
                } while (izbor2 < 0 || izbor2 > 5);
                std::cin.ignore();
                if (izbor2 == 0) {
                    std::cout << "\n\t\t\t\t  Odustali ste od izmjene paketa.";
                    system("pause");
                    break;
                } else if (izbor2 == 1) {
                    paketi[izbor - 1].setImePaketa();
                    std::cout << "\n\t\t\t\t  Ime paketa uspjesno promjenjeno.";
                } else if (izbor2 == 2) {
                    paketi[izbor - 1].setBrzinaInterneta();
                    std::cout << "\n\t\t\t\t  Brzina Interneta je uspjesno promjenjena.";
                } else if (izbor2 == 3) {
                    paketi[izbor - 1].setCijena();
                    std::cout << "\n\t\t\t\t  Cijena paketa je uspjesno promjenjena.";
                } else if (izbor2 == 4) {
                    paketi[izbor - 1].setDodatnaPonuda();
                    std::cout << "\n\t\t\t\t  Dodatna ponuda paketa je uspjesno promjenjena.";
                } else {
                    paketi[izbor - 1].setKoristenjeInterneta();
                    std::cout << "\n\t\t\t\t  Koristenje interneta je uspjesno promjenjeno.";
                }

                std::ofstream upisipaket;
                std::string imedatoteke = "Baza Podataka/Paketi/Paket_" + std::to_string(izbor) + ".txt";
                upisipaket.open(imedatoteke);

                try {
                    if (upisipaket.fail()) throw "\n\t\t\t\t  Greska - Nije moguce otvoriti datoteku.";
                    else {
                        upisipaket << paketi[izbor - 1].getImePaketa() << std::endl;
                        upisipaket << paketi[izbor - 1].getBrzinaInterneta() << std::endl;
                        upisipaket << paketi[izbor - 1].getCijena() << std::endl;
                        upisipaket << paketi[izbor - 1].getDodatnaPonuda() << std::endl;
                        upisipaket << paketi[izbor - 1].getKoristenjeInterneta() << std::endl;
                        upisipaket.close();
                    }
                } catch (const char* Greska) {
                    std::cout << Greska;
                } catch (...) {
                    std::cout << "\n\t\t\t\t  Nepoznata greska.";
                }

                std::cout << "\n\t\t\t\t  Pritisnite enter za nastavak...";
                _getch();
                break;
            }
            case 6: {

                std::ifstream brPaketa;
                brPaketa.open("Baza Podataka/Paketi/brojpaketa.txt");
                if (brPaketa.fail()) {
                    return;
                } else {
                    brPaketa >> Paket::brojPaketa;
                    brPaketa.close();
                }

                Paket* paketi = new Paket[Paket::brojPaketa];

                if (Paket::brojPaketa == 0) {
                    std::cout << "\n\t\t\t\t  Nema paketa za urediti.";
                    break;
                } else {
                    std::string temp;
                    for (int i = 0; i < Paket::brojPaketa; i++) {
                        std::string imedatoteke = "Baza Podataka/Paketi/Paket_" + std::to_string(i + 1) + ".txt";
                        std::ifstream datoteka;
                        datoteka.open(imedatoteke);
                        getline(datoteka, temp);
                        paketi[i].setImePaketa(temp);
                        std::cout << "\n\t\t\t\t  " << i + 1 << ". " << paketi[i].getImePaketa();
                        getline(datoteka, temp);
                        paketi[i].setBrzinaInterneta(temp);
                        getline(datoteka, temp);
                        paketi[i].setCijena(temp);
                        getline(datoteka, temp);
                        paketi[i].setDodatnaPonuda(temp);
                        getline(datoteka, temp);
                        if (stringtoint(temp.c_str()) == 0) paketi[i].setKoristenjeInterneta(ogranicen);
                        else paketi[i].setKoristenjeInterneta(neogranicen);
                        datoteka.close();
                    }
                }

                auto izbor = std::make_shared<int>(0);
                std::cout << "\n\t\t\t\t  0. Odustani";
                std::cout << "\n\t\t\t\t  Unesite koji paket zelite da uklonite: ";

                do {
                    std::cin >> *izbor;
                    if (*izbor < 0 || *izbor > Paket::brojPaketa) std::cout << "\n\t\t\t\t  Greska - Pogresan unos. Molimo ponovite unos: ";
                }while(*izbor < 0 || *izbor > Paket::brojPaketa);
                if (*izbor == 0) {
                    std::cout << "\n\t\t\t\t  Odustali ste od brisanja paketa.";
                    std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                    _getch();
                    break;
                }
                std::string imeDatoteke = "Baza Podataka/Paketi/Paket_" + std::to_string(*izbor) + ".txt";
                remove(imeDatoteke.c_str());
                if(*izbor == 0) 
                    for (int i = 0; i < Paket::brojPaketa; i++) {
                        std::string preimenujFajlove = "Baza Podataka/Paketi/Paket_" + std::to_string(i + 1) + ".txt";
                        rename(preimenujFajlove.c_str(), imeDatoteke.c_str());
                        imeDatoteke = preimenujFajlove;
                    }
                else 
                    for (int i = *izbor; i < Paket::brojPaketa; i++) {
                        std::string preimenujFajlove = "Baza Podataka/Paketi/Paket_" + std::to_string(i + 1) + ".txt";
                        rename(preimenujFajlove.c_str(), imeDatoteke.c_str());
                        imeDatoteke = preimenujFajlove;
                    }
                std::cout << "\n\t\t\t\t  Paket " << paketi[*izbor-1].getImePaketa() << " je uspjesno izbrisan.";
                imeDatoteke = "Baza Podataka/Paketi/brojpaketa.txt";
                std::ofstream datotekaa;
                datotekaa.open(imeDatoteke);
                try {
                    if (datotekaa.fail()) throw "\n\t\t\t\t  Greska - Nije moguce otvoriti datoteku.";
                    datotekaa << Paket::brojPaketa - 1;
                } catch (const char* Greska) {
                    std::cout << Greska;
                } catch (...) {
                    std::cout << "\n\t\t\t\t  Nepoznata greska.";
                }
                std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                _getch();
                system("cls");
                break;
            }
            case 7: {

                if ((username != "root" && sifra != "root")) {
                    std::cout << "\n\t\t\t\t  Greska - Niste ovlasteni";
                    system("pause");
                    break;
                }

                std::ifstream brRadnika;
                brRadnika.open("Baza Podataka/Radnici/brojradnika.txt");
                if (brRadnika.fail()) {
                    return;
                } else {
                    brRadnika >> Radnik::brojRadnika;
                    brRadnika.close();
                }
                try {
                    if (Radnik::brojRadnika == 4) throw "\n\t\t\t\t  Greska - Kapacitet radnika je pun.";
                    else {

                        auto noviRadnik = std::make_shared<Radnik>();
                        std::cin >> *noviRadnik;

                        std::ofstream datoteka;
                        std::string imeDatoteke = "Baza Podataka/Radnici/Radnik_";
                        imeDatoteke += std::to_string(Radnik::brojRadnika + 1);
                        imeDatoteke += ".txt";
                        datoteka.open(imeDatoteke, std::fstream::in | std::fstream::out | std::ios::trunc);
                        try {
                            if (datoteka.fail()) throw "\n\t\t\t\t  Greska - Nije moguce otvoriti datoteku.";
                            else {
                                datoteka << noviRadnik->getRadnikID() << std::endl;
                                datoteka << noviRadnik->getUsername() << std::endl;
                                datoteka << noviRadnik->getPassword() << std::endl;
                                datoteka << noviRadnik->getIme() << std::endl;
                                datoteka << noviRadnik->getPrezime() << std::endl;
                                datoteka << noviRadnik->getJMBG() << std::endl;
                                datoteka << noviRadnik->getMjestoRodjenja() << std::endl;
                                datoteka << noviRadnik->getDatumRodjenja() << std::endl;
                                datoteka << noviRadnik->getMjestoBoravka() << std::endl;
                                datoteka << noviRadnik->getAdresa() << std::endl;
                                datoteka << noviRadnik->getDrzavljanstvo() << std::endl;
                                datoteka << noviRadnik->getDatumZaposljenja() << std::endl;
                                datoteka << noviRadnik->getStrucnaSprema() << std::endl;
                                datoteka << noviRadnik->getPlata() << std::endl;
                                datoteka << noviRadnik->getPozicija() << std::endl;
                                datoteka.close();
                                datoteka.open("Baza Podataka/Radnici/brojradnika.txt");
                                datoteka << Radnik::brojRadnika + 1;
                                datoteka.close();
                            }
                        } catch (const char* Greska) {
                            std::cout << *Greska << std::endl;
                        } catch (...) {
                            std::cout << "\n\t\t\t\t  Greska - Nepoznata greska";
                        }
                    }
                } catch (const char* Greska) {
                    std::cout << *Greska;
                } catch (...) {
                    std::cout << "\n\t\t\t\t  Nepoznata greska.";
                }
                std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                _getch();
                system("cls");
                break;
            }
            case 8: {

                if ((username != "root" && sifra != "root")) {
                    std::cout << "\n\t\t\t\t  Greska - Niste ovlasteni";
                    std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                    _getch();
                    break;
                }

                std::ifstream brRadnika;
                brRadnika.open("Baza Podataka/Radnici/brojradnika.txt");
                if (brRadnika.fail()) {
                    return;
                } else {
                    brRadnika >> Radnik::brojRadnika;
                    brRadnika.close();
                }

                Radnik* Radnici = new Radnik[Radnik::brojRadnika];
                int indexi = 0;
                for (int i = 0; i < 4; i++) {
                    std::string imeDatoteke = "Baza Podataka/Radnici/Radnik_" + std::to_string(i + 1) + ".txt";
                    std::ifstream datoteka;
                    datoteka.open(imeDatoteke);
                    if (datoteka.fail()) {
                        continue;
                    }
                    std::string temp;
                    getline(datoteka, temp);
                    Radnici[indexi].setRadnikID(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setUsername(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setPassword(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setIme(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setPrezime(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setJMBG(temp.c_str());
                    getline(datoteka, temp);
                    Radnici[indexi].setMjestoRodjenja(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setDatumRodjenja(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setMjestoBoravka(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setAdresa(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setDrzavljanstvo(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setDatumZaposljenja(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setStrucnaSprema(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setPlata(stringtoint(temp.c_str()));
                    getline(datoteka, temp);
                    Radnici[indexi].setPozicija(temp);
                    std::cout << "\n\t\t\t\t  " << i + 1 << ". " << Radnici[indexi].getIme() << " " << Radnici[indexi].getPrezime();
                    indexi++;
                }
                std::cout << "\n\t\t\t\t  0. Odustani\n";
                std::cout << "\n\t\t\t\t  Unesite kojeg radnika zelite da uredite: ";
                auto izbor = std::make_shared<int>(0);
                do {
                    std::cin >> *izbor;
                    if (*izbor < 0 || *izbor > Radnik::brojRadnika) std::cout << "\n\t\t\t\t  Greska - Pogresan unos. Molimo vas da ponovite unos: ";
                } while (*izbor < 0 || *izbor > Radnik::brojRadnika);
                std::cin.ignore();
                *izbor -= 1;
                if (*izbor == -1) {
                    std::cout << "\n\t\t\t\t  Odustali ste od uredjivanja radnika.";
                    std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                    _getch();
                    break;
                } 
                std::cout << "\n\t\t\t\t  1. Promjeni username\n\t\t\t\t  2. Promjeni sifru\n\t\t\t\t  3. Promjeni ime\n\t\t\t\t  4. Promjeni prezime\n\t\t\t\t  5. Promjeni mjesto boravka\n\t\t\t\t  6. Promjeni adresu\n\t\t\t\t  7. Promjeni drzavljanstvo\n\t\t\t\t  8. Promjeni strucnu spremu\n\t\t\t\t  9. Promjeni platu\n\t\t\t\t  10. Promjeni poziciju\n\t\t\t\t  Unesite opciju: ";
                auto izbor2 = std::make_shared<int>(0);
                do {
                    std::cin >> *izbor2;
                    if (*izbor2 < 0 || *izbor2 > 10) std::cout << "\n\t\t\t\t  Greska - Pogresan unos. Molimo ponovite unos: ";
                } while (*izbor2 < 0 || *izbor2 > 10);
                std::cin.ignore();
                if (*izbor2 == 0) {
                    std::cout << "\n\t\t\t\t  Odustali ste od uredjivanja radnika.";
                    break;
                } else if (*izbor2 == 1) Radnici[*izbor].setUsername();
                else if (*izbor2 == 2) Radnici[*izbor].setPassword();
                else if (*izbor2 == 3) Radnici[*izbor].setIme();
                else if (*izbor2 == 4) Radnici[*izbor].setPrezime();
                else if (*izbor2 == 5) Radnici[*izbor].setMjestoBoravka();
                else if (*izbor2 == 6) Radnici[*izbor].setAdresa();
                else if (*izbor2 == 7) Radnici[*izbor].setDrzavljanstvo();
                else if (*izbor2 == 8) Radnici[*izbor].setStrucnaSprema();
                else if (*izbor2 == 9) Radnici[*izbor].setPlata();
                else if (*izbor2 == 10) Radnici[*izbor].setPozicija();

                std::ofstream datoteka;
                std::string imeDatoteke = "Baza Podataka/Radnici/Radnik_" + std::to_string(*izbor+1) + ".txt";
                datoteka.open(imeDatoteke);
                try {
                    if (datoteka.fail()) throw "\n\t\t\t\t  Greska - Nije moguce otvoriti datoteku.";
                    else {
                        datoteka << Radnici[*izbor].getRadnikID() << std::endl;
                        datoteka << Radnici[*izbor].getUsername() << std::endl;
                        datoteka << Radnici[*izbor].getPassword() << std::endl;
                        datoteka << Radnici[*izbor].getIme() << std::endl;
                        datoteka << Radnici[*izbor].getPrezime() << std::endl;
                        datoteka << Radnici[*izbor].getJMBG() << std::endl;
                        datoteka << Radnici[*izbor].getMjestoRodjenja() << std::endl;
                        datoteka << Radnici[*izbor].getDatumRodjenja() << std::endl;
                        datoteka << Radnici[*izbor].getMjestoBoravka() << std::endl;
                        datoteka << Radnici[*izbor].getAdresa() << std::endl;
                        datoteka << Radnici[*izbor].getDrzavljanstvo() << std::endl;
                        datoteka << Radnici[*izbor].getDatumZaposljenja() << std::endl;
                        datoteka << Radnici[*izbor].getStrucnaSprema() << std::endl;
                        datoteka << Radnici[*izbor].getPlata() << std::endl;
                        datoteka << Radnici[*izbor].getPozicija() << std::endl;
                        datoteka.close();
                    }
                } catch (const char* Greska) {
                    std::cout << *Greska << std::endl;
                } catch (...) {
                    std::cout << "\n\t\t\t\t  Greska - Nepoznata greska";
                }
                std::cout << "\n\t\t\t\t  Uspjesno ste uredili radnika " << Radnici[*izbor].getIme() << " " << Radnici[*izbor].getPrezime() << "." << std::endl;
                std::cout << "\n\t\t\t\t  Pritisnite bilo koju tipku da bi ste se vratili u Admin meni.";
                _getch();
                delete[] Radnici;
                break;
            }
            case 9: {
                try {
                    if ((username != "root" && sifra != "root")) 
                        throw "\n\t\t\t\t  Greska - Niste ovlasteni.";
                    std::ifstream brRadnika;
                    brRadnika.open("Baza Podataka/Radnici/brojradnika.txt");
                    if (brRadnika.fail()) {
                        return;
                    } else {
                        brRadnika >> Radnik::brojRadnika;
                        brRadnika.close();
                    }

                    Radnik* Radnici = new Radnik[Radnik::brojRadnika];
                    auto indexi = std::make_shared<int>(0);
                    for (int i = 0; i < 4; i++) {
                        std::string imeDatoteke = "Baza Podataka/Radnici/Radnik_" + std::to_string(i + 1) + ".txt";
                        std::ifstream datoteka;
                        datoteka.open(imeDatoteke);
                        if (datoteka.fail()) {
                            continue;
                        }
                        std::string temp;
                        getline(datoteka, temp);
                        Radnici[*indexi].setRadnikID(temp);
                        getline(datoteka, temp);
                        Radnici[*indexi].setUsername(temp);
                        getline(datoteka, temp);
                        Radnici[*indexi].setPassword(temp);
                        getline(datoteka, temp);
                        Radnici[*indexi].setIme(temp);
                        getline(datoteka, temp);
                        Radnici[*indexi].setPrezime(temp);
                        getline(datoteka, temp);
                        std::cout << "\n\t\t\t\t  " << i + 1 << ". " << Radnici[i].getIme() << " " << Radnici[i].getPrezime();
                        *indexi += 1;
                    }
                    std::cout << "\n\t\t\t\t  0. Odustani\n";
                    std::cout << "\n\t\t\t\t  Unesite kojeg radnika zelite da izbrisete: ";

                    auto izbor = std::make_shared<int>(0);
                    do {
                        std::cin >> *izbor;
                        if (*izbor < 0 || *izbor > Radnik::brojRadnika) std::cout << "\n\t\t\t\t  Greska - Pogresan unos. Molimo vas da ponovite unos: ";
                    } while (*izbor < 0 || *izbor > Radnik::brojRadnika);
                    if (*izbor == 0) throw "\n\t\t\t\t  Odustali ste od brisanja radnika.";
                    std::ofstream datotekaa;
                    datotekaa.open("Baza Podataka/Radnici/brojradnika.txt");
                    if (datotekaa.fail()) throw "\n\t\t\t\t  Greska - Nije moguce otvoriti datoteku.";
                    datotekaa << Radnik::brojRadnika - 1;
                    std::string imeDatoteke = "Baza Podataka/Radnici/Radnik_" + std::to_string(*izbor) + ".txt";
                    remove(imeDatoteke.c_str());
                    if(*izbor == 0)
                        for (int i = *izbor; i < Radnik::brojRadnika; i++) {
                            std::string preimenujFajlove = "Baza Podataka/Radnici/Radnik_" + std::to_string(i + 1) + ".txt";
                            rename(preimenujFajlove.c_str(), imeDatoteke.c_str());
                            imeDatoteke = preimenujFajlove;
                        }
                    else 
                        for (int i = *izbor; i < Radnik::brojRadnika; i++) {
                            std::string preimenujFajlove = "Baza Podataka/Radnici/Radnik_" + std::to_string(i+1) + ".txt";
                            rename(preimenujFajlove.c_str(), imeDatoteke.c_str());
                            imeDatoteke = preimenujFajlove;
                        }
                    std::cout << "\n\t\t\t\t  Uspjesno ste izbrisali radnika " << Radnici[*izbor-1].getIme() << " " << Radnici[*izbor-1].getPrezime() << "." << std::endl;
                    std::cout << "\n\t\t\t\t  Pritisnite bilo koju tipku da bi ste se vratili u Admin meni.";
                    _getch();
                    delete[] Radnici;
                } catch (const char* Greska) {
                    std::cout << Greska;
                    std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                    _getch();
                } catch (...) {
                    std::cout << "\n\t\t\t\t  Nepoznata greska.";
                    std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                    _getch();
                }
                break;
            }
            case 10: {
                if ((username != "root" && sifra != "root")) {
                    std::cout << "\n\t\t\t\t  Greska - Niste ovlasteni";
                    std::cout << "\n\t\t\t\t  Pritisnike enter za nastavak...";
                    _getch();
                    break;
                }

                std::ifstream brRadnika;
                brRadnika.open("Baza Podataka/Radnici/brojradnika.txt");
                if (brRadnika.fail()) {
                    return;
                } else {
                    brRadnika >> Radnik::brojRadnika;
                    brRadnika.close();
                }

                if (Radnik::brojRadnika == 0) {
                    std::cout << "\n\t\t\t\t  Info - Nema radnika u Bazi podataka.";
                    std::cout << "\n\t\t\t\t  Pritisnite bilo koju tipku da bi ste se vratili u Admin meni.";
                    _getch();
                    break;
                }

                Radnik* Radnici = new Radnik[Radnik::brojRadnika];
                int indexi = 0;
                for (int i = 0; i < 4; i++) {
                    std::string imeDatoteke = "Baza Podataka/Radnici/Radnik_" + std::to_string(i + 1) + ".txt";
                    std::ifstream datoteka;
                    datoteka.open(imeDatoteke);
                    if (datoteka.fail()) {
                        continue;
                    }
                    std::string temp;
                    getline(datoteka, temp);
                    Radnici[indexi].setRadnikID(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setUsername(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setPassword(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setIme(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setPrezime(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setJMBG(temp.c_str());
                    getline(datoteka, temp);
                    Radnici[indexi].setMjestoRodjenja(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setDatumRodjenja(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setMjestoBoravka(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setAdresa(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setDrzavljanstvo(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setDatumZaposljenja(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setStrucnaSprema(temp);
                    getline(datoteka, temp);
                    Radnici[indexi].setPlata(stringtoint(temp.c_str()));
                    getline(datoteka, temp);
                    Radnici[indexi].setPozicija(temp);
                    std::cout << "\n\t\t\t\t  " << i + 1 << ". " << Radnici[indexi].getIme() << " " << Radnici[indexi].getPrezime();
                    indexi++;
                }
                std::cout << "\n\t\t\t\t  0. Odustani\n";
                std::cout << "\n\t\t\t\t  Unesite kojeg radnika zelite da vidite: ";
                auto izbor = std::make_shared<int>(0);
                do {
                    std::cin >> *izbor;
                    if (*izbor < 0 || *izbor > Radnik::brojRadnika) std::cout << "\n\t\t\t\t  Greska - Pogresan unos. Molimo vas da ponovite unos: ";
                } while (*izbor < 0 || *izbor > Radnik::brojRadnika);
                std::cin.ignore();
                *izbor -= 1;

                std::cout << "\n\t\t\t\t  " << Radnici[*izbor];
                std::cout << "\n\t\t\t\t  Pritisnite bilo koju tipku da bi ste se vratili u Admin meni.";
                _getch();
                break;
            }
            default: {
                return;
                break;
            }
            }
        }
    }
}

void resetujBazu() {
    auto broj = std::make_shared<int>(0);
    std::ifstream brojevi;
    brojevi.open("Baza Podataka/Zahtjevi/brojzahtjeva.txt");
    if (brojevi.fail()) return;
    else brojevi >> *broj;
    brojevi.close();
    std::string imeDatoteke = "";
    for (int i = 0; i < *broj; i++) {
        imeDatoteke = "Baza Podataka/Zahtjevi/Zahtjev_" + std::to_string(i + 1) + ".txt";
        remove(imeDatoteke.c_str());
    }
    imeDatoteke = "Baza Podataka/Zahtjevi/brojzahtjeva.txt";
    remove(imeDatoteke.c_str());

    brojevi.open("Baza Podataka/Ugovori/brojugovora.txt");
    if (brojevi.fail()) return;
    else brojevi >> *broj;
    brojevi.close();
    for (int i = 0; i < *broj; i++) {
        imeDatoteke = "Baza Podataka/Ugovori/Ugovor_" + std::to_string(i + 1) + ".txt";
        remove(imeDatoteke.c_str());
    }
    imeDatoteke = "Baza Podataka/Ugovori/brojugovora.txt";
    remove(imeDatoteke.c_str());
    imeDatoteke = "Baza Podataka/Ugovori/zahtjevizabrisanjemugovora.txt";
    remove(imeDatoteke.c_str());

    brojevi.open("Baza Podataka/Radnici/brojradnika.txt");
    if (brojevi.fail()) return;
    else brojevi >> *broj;
    brojevi.close();
    for (int i = 0; i < *broj; i++) {
        imeDatoteke = "Baza Podataka/Radnici/Radnik_" + std::to_string(i + 1) + ".txt";
        remove(imeDatoteke.c_str());
    }
    imeDatoteke = "Baza Podataka/Radnici/brojradnika.txt";
    remove(imeDatoteke.c_str());

    brojevi.open("Baza Podataka/Paketi/brojpaketa.txt");
    if (brojevi.fail()) return;
    else brojevi >> *broj;
    brojevi.close();
    for (int i = 0; i < *broj; i++) {
        imeDatoteke = "Baza Podataka/Paketi/Paket_" + std::to_string(i + 1) + ".txt";
        remove(imeDatoteke.c_str());
    }
    imeDatoteke = "Baza Podataka/Paketi/brojpaketa.txt";
    remove(imeDatoteke.c_str());
}

bool provjera(std::string username, std::string password) {
    if (username == "root" && password == "root") return true;
    else if (username == "root" && password == "noroot") return false;
    else return false;
    return false;
}
long stringtoint(const char* s) {
    long i;
    i = 0;
    while (*s >= '0' && *s <= '9') {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}

int administratorskiIzbor() {
    system("cls");
    std::cout << "\t\t\t\t      ___       __          _                               _ \n";
    std::cout << "\t\t\t\t     /   | ____/ /___ ___  (_)___     ____ ___  ___  ____  (_)\n";
    std::cout << "\t\t\t\t    / /| |/ __  / __ `__ \\/ / __ \\   / __ `__ \\/ _ \\/ __ \\/ / \n";
    std::cout << "\t\t\t\t   / ___ / /_/ / / / / / / / / / /  / / / / / /  __/ / / / /  \n";
    std::cout << "\t\t\t\t  /_/  |_\\__,_/_/ /_/ /_/_/_/ /_/  /_/ /_/ /_/\\___/_/ /_/_/   \n";
    std::cout << "\t\t\t\t ______________________________________________________________\n\n";
    std::cout << "\t\t\t\t  1. Odobri zahtjev." << std::endl;
    std::cout << "\t\t\t\t  2. Pogledaj listu ugovora." << std::endl;
    std::cout << "\t\t\t\t  3. Izbrisi ugovor." << std::endl;
    std::cout << "\t\t\t\t  4. Dodaj paket." << std::endl;
    std::cout << "\t\t\t\t  5. Uredi paket." << std::endl;
    std::cout << "\t\t\t\t  6. Izbrisi paket." << std::endl;
    std::cout << "\t\t\t\t  7. Dodaj radnika." << std::endl;
    std::cout << "\t\t\t\t  8. Uredi radnika." << std::endl;
    std::cout << "\t\t\t\t  9. Izbrisi radnika." << std::endl;
    std::cout << "\t\t\t\t  10. Ispisi radnika." << std::endl;
    std::cout << "\t\t\t\t  11. Izadji iz Administratorskog menija." << std::endl;
    std::cout << "\t\t\t\t ______________________________________________________________\n\n";
    auto izbor = std::make_shared<int>();
    do {
        std::cout << "\t\t\t\t  Unesite opciju: ";
        std::cin >> *izbor;
        if (*izbor < 1) {
            std::cout << "\t\t\t\t  Greska - Ne mozete unijeti opciju manju od 1.";
            std::cout << "\n\t\t\t\t   Ponovo unesite opciju: ";
        } else if (*izbor > 11) {
            std::cout << "\t\t\t\t  Greska - Ne mozete unijeti opciju vecu od 11.";
            std::cout << "\n\t\t\t\t   Ponovo unesite opciju: ";
        }
    } while (*izbor < 1 || *izbor > 11);
    std::cin.ignore();
    return *izbor;
}

int klijentskiIzbor() {
    system("cls");
    std::cout << "\t\t\t\t    ______     __                __ \n";
    std::cout << "\t\t\t\t   /_  __/__  / /__  ____  ___  / /_\n";
    std::cout << "\t\t\t\t    / / / _ \\/ / _ \\/ __ \\/ _ \\/ __/\n";
    std::cout << "\t\t\t\t   / / /  __/ /  __/ / / /  __/ /_  \n";
    std::cout << "\t\t\t\t  /_/  \\___/_/\\___/_/ /_/\\___/\\__/  \n";
    std::cout << "\t\t\t\t __________________________________________________________\n\n";
    std::cout << "\t\t\t\t  1. Vidi ponude." << std::endl;
    std::cout << "\t\t\t\t  2. Podnesi zahtjev." << std::endl;
    std::cout << "\t\t\t\t  3. Ponisti ugovor." << std::endl;
    std::cout << "\t\t\t\t  4. Administratorski meni." << std::endl;
    std::cout << "\t\t\t\t  5. Izadji iz sistema." << std::endl;
    std::cout << "\t\t\t\t __________________________________________________________\n\n";
    std::cout << "\t\t\t\t  Unesite opciju: ";

    int izbor;
    do {
        std::cin >> izbor;
        if (izbor < 1) {
            std::cout << "\t\t\t\t  Greska - Ne mozete unijeti opciju manju od 1.\n";
            std::cout << "\t\t\t\t  Ponovo unesite opciju: ";
        } else if (izbor > 5) {
            std::cout << "\t\t\t\t  Greska - Ne mozete unijeti opciju vecu od 5.\n";
            std::cout << "\t\t\t\t  Ponovo unesite opciju: ";
        }
    } while (izbor < 1 || izbor > 5);
    std::cin.ignore();
    return izbor;
}