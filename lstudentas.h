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

class lstudentas
{
private:
    string Vardas;
    string Pavarde;
    list <int> nd;
    int n = 0;
    int egz;
    float galutinis;
    float vid;
    float med;
    int vidarmed;
public:
    lstudentas() {
        Vardas = "";
        Pavarde = "";
        n = 0;
        egz = 0;
        galutinis = 0;
        vid = 0;
        med = 0;
        vidarmed = 0;
    }
    lstudentas(int vidmed, string vard, string pav, int sk, list<int> ndl, int egzam) {
        vidarmed = vidmed;
        Vardas = vard;
        Pavarde = pav;
        n = sk;
        nd = ndl;
        egz = egzam;
        setGalutinis();
    }
    ~lstudentas() { nd.clear(); }
    void setVidarmed(int vam) { vidarmed = vam; }
    int getVidarmed() const { return vidarmed; }
    void setVardas(string vard) { Vardas = vard; }
    string getVardas() const { return Vardas; }
    void setPavarde(string pavard) { Pavarde = pavard; }
    string getPavarde() const { return Pavarde; }
    void setND(list <int> paz) { nd = paz; vid = countVidurkis(); med = countMediana(); }
    list<int> getND() const { return nd; }
    void setNDskaicius(int paz) { n = paz; }
    int getNDskaicius() const { return n; }
    void setEgzaminas(int paz) { egz = paz; }
    int getEgzaminas() const { return egz; }
    void setGalutinis() { if (vidarmed == 1) galutinis = countGalutinis(med); else galutinis = countGalutinis(vid); }
    float getGalutinis() const { return galutinis; }
    float countVidurkis() { float suma = 0; for (float a : nd) suma = suma + a; return vid = suma / n; }
    float countMediana() {
        nd.sort();
        auto itr = nd.begin();
        if (nd.size() % 2 == 0) {
            for (int i = 0; i < nd.size() / 2; i++) itr++;
            return med = ((double)*itr + *--itr) / 2;
        }
        else {
            for (int i = 0; i < nd.size() / 2; i++) itr++;
            return med = *itr;
        }
    }
    float countGalutinis(float vam) { galutinis = vam * 0.4 + (float)egz * 0.6; return galutinis; }
    bool operator <(const lstudentas& a) const {
        if (getVardas() != a.getVardas())
            return getVardas().compare(a.getVardas()) < 0;

        if (getPavarde() != a.getPavarde())
            return getPavarde().compare(a.getPavarde()) < 0;

        return (getGalutinis() > a.getGalutinis());
    }
};

void lnuskaitymas(string txtname, list<lstudentas>& grupe, int& StudSkai, int VidArMed);
void livedimas(list<lstudentas>& grupe, int StudSkai, int VidArMed, int AutoGen);
int lautosk(int nuo, int iki);
void lisvedimas(list<lstudentas> grupe, int VidArMed);
void lirasymas(string name, list<lstudentas> grupe, int VidArMed);
void lpadalinimas(list<lstudentas>& grupe, list<lstudentas>& grupe1);
void lpadalinimas1(list<lstudentas> grupe, list<lstudentas>& grupe1, list<lstudentas>& grupe2);
void lpadalinimas2(list<lstudentas>& grupe, list<lstudentas>& grupe1);
void lgeneravimas(string txt, int sk, int& ndsk);
void lzmogausVP(string& vardas, string& pavarde);
