#pragma once

#include "Klijent.h"
#include "Paket.h"
#include "Radnik.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <vector>
#include <filesystem>

// Univerzalne funkcije

void provjeravanje(int, int, int, int, int, int);
void loading(const char*);
void klijentskiMeni();
void administratorskiMeni();
void resetujBazu();

int pretvaranjeUDane(int, int, int);
int vratiSpoj(int, int, int, int);
int administratorskiIzbor();
int klijentskiIzbor();

bool provjeriDatum(const char*);
bool provjeriMail(const char*);
bool provjera(int);
bool provjera(std::string, std::string);
bool provjeriJMBG(const char*, char*);

long stringtoint(const char*);