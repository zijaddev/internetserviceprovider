#include <iostream>
#include "Radnik.h"
#include "Klijent.h"
#include "Paket.h"
#include <string>
#include <Windows.h>
#include <conio.h>

// Projekat ima par bugova, koje zbog nedostatka vremena nisam u mogucnosti raditi. 
// Na projektu su radili: Sarajcic Samed, Kalabuzic Mujo, Haseljic Muhamed i Doglod Zijad.
// Sve potrebne informacije imate fajlu koji se zove:
// PTF_OOP_2021_22_Dokumentacija_Projekat_InternetServiceProvider.docx (ili .pdf format)

int main() {

	std::fstream kreirajFajlove;
	kreirajFajlove.open("Baza Podataka/Paketi/brojpaketa.txt", std::ios::out);
	kreirajFajlove << 0;
	kreirajFajlove.close();
	kreirajFajlove.open("Baza Podataka/Zahtjevi/brojzahtjeva.txt", std::ios::out);
	kreirajFajlove << 0;
	kreirajFajlove.close();
	kreirajFajlove.open("Baza Podataka/Ugovori/brojugovora.txt", std::ios::out);
	kreirajFajlove << 0;
	kreirajFajlove.close();
	kreirajFajlove.open("Baza Podataka/Ugovori/zahtjevizabrisanjemugovora.txt", std::ios::out);
	kreirajFajlove.close();
	kreirajFajlove.open("Baza Podataka/Radnici/brojradnika.txt", std::ios::out);
	kreirajFajlove << 0;
	kreirajFajlove.close();

	std::string letters[9]{
		"\t\t\t\t\t____________________________________________\n",
		"\t\t\t\t\t   ______     __                __ \n",
		"\t\t\t\t\t  /_  __/__  / /__  ____  ___  / /_\n",
		"\t\t\t\t\t   / / / _ \\/ / _ \\/ __ \\/ _ \\/ __/\n",
		"\t\t\t\t\t  / / /  __/ /  __/ / / /  __/ /_  \n",
		"\t\t\t\t\t /_/  \\___/_/\\___/_/ /_/\\___/\\__/  \n",
		"\t\t\t\t\t____________________________________________\n"
	};

	std::cout << "\n\n\n\n\n\n\n\n";

	for (int i = 0; i < 7; i++) {
		std::cout << letters[i];
		Sleep(500);
	}
	std::cout << "\t\t\t\t\t";
	char dobrodoslica[] = " Dobro dosli u Telenet!";
	for (int i = 0; i < strlen(dobrodoslica); i++) {
		std::cout << dobrodoslica[i];
		Sleep(300);
	}
	std::cout << "\n\t\t\t\t\t Pritisnite bilo koju tipku da nastavite...";
	_getch();
	system("cls");
	klijentskiMeni();
	resetujBazu();
	return 0;
}
