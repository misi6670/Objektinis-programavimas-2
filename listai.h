#pragma once

#include "klaidos.h"
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <random>
#include <map>

using std::cout;
using std::cin;
using std::string;
using std::list;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;
using std::sort;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::ios;
using std::count;
using std::to_string;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::map;

struct lstudentas {
    string Vardas = "";
    string Pavarde = "";
    list <int> nd;
    int n = 0;
    int egz = 0;
    float galutinis = 0;
    float vid = 0;
    bool operator <(const lstudentas & a) const
    {
        if (Vardas != a.Vardas)
            return Vardas.compare(a.Vardas) < 0;

        if (Pavarde != a.Pavarde)
            return Pavarde.compare(a.Pavarde) < 0;

        return (galutinis > a.galutinis);
    }
};

void lnuskaitymas(string txtname, list<lstudentas>& grupe, int& StudSkai, int VidArMed);
void lmediana(lstudentas& stud);
void livedimas(list<lstudentas>& grupe, int StudSkai, int VidArMed, int AutoGen);
void lautogen(lstudentas& stud, int i);
int lautosk(int nuo, int iki);
void lpazymiai(lstudentas& stud, int i);
void lisvedimas(list<lstudentas> grupe, int VidArMed);
void lirasymas(string name, list<lstudentas> grupe, int VidArMed);
void lpadalinimas(list<lstudentas> grupe, list<lstudentas>& grupe1);
void lgeneravimas(string txt, int sk, int& ndsk);
void lzmogausVP(string& vardas, string& pavarde);
