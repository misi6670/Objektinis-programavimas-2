#pragma once

#include "klaidos.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <random>
#include <map>

using std::cout;
using std::cin;
using std::string;
using std::vector;
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

class studentas
{
private:
    string Vardas;
    string Pavarde;
    vector <int> nd;
    int n = 0;
    int egz;
    float galutinis = 0;
    float vid = 0;
    float med = 0;
    float suma = 0;
    int vidarmed = 0;
public:
    studentas() {
        Vardas = "";
        Pavarde = "";
        n = 0;
        egz = 0;
        galutinis = 0;
        vid = 0;
        med = 0;
    }
    studentas(string vard, string pav, vector<int> ndg, int egzam) {
        Vardas = vard;
        Pavarde = pav;
        n = 0;
        nd = ndg;
        nd.reserve(n);
        egz = egzam;
        setGalutinis();
    }

    void setVidarmed(int vam) { vidarmed = vam; }
    int getVidarmed() const { return vidarmed; }
    void setVardas(string vard) { Vardas = vard; }
    string getVardas() const { return Vardas; }
    void setPavarde(string pavard) { Pavarde = pavard; }
    string getPavarde() const { return Pavarde; }
    void setND(vector <int> paz) { nd = paz; nd.reserve(n); vid = countVidurkis(); med = countMediana(); }
    vector<int> getND() const { return nd; }
    void setNDskaicius(int paz) { n = paz; }
    int getNDskaicius() const { return n; }
    void setEgzaminas(int paz) { egz = paz; }
    int getEgzaminas() const { return egz; }
    void setGalutinis() { if (vidarmed == 1) galutinis = countGalutinis(med); else galutinis = countGalutinis(vid); }
    float getGalutinis() const { return galutinis; }
    float countVidurkis() { for (float a : nd) suma = suma + a; vid = suma / n; return vid; }
    float countMediana() {
        sort(nd.begin(), nd.end());
        if (n % 2 != 0) galutinis = (float)nd.at(n / 2);
        else {
            int med;
            med = nd.at((n - 1) / 2) + nd.at(n / 2);
            galutinis = (float)med / 2.0;
        }
        return med;
    }
    float countGalutinis(float vam) { galutinis = vam * 0.4 + (float)egz * 0.6; return galutinis; }
    bool compare(const studentas& a, const studentas& b) {
        if (a.getVardas() != b.getVardas())
            return a.getVardas().compare(b.getVardas()) < 0;

        if (a.getPavarde() != b.getPavarde())
            return a.getPavarde().compare(b.getPavarde()) < 0;

        return (a.getGalutinis() > b.getGalutinis());
    }
};

void nuskaitymas(string txtname, vector<studentas>& grupe, int& StudSkai, int VidArMed);
void ivedimas(vector<studentas>& grupe, int StudSkai, int VidArMed, int AutoGen);
int autosk(int nuo, int iki);
void isvedimas(vector<studentas> grupe, int VidArMed);
void irasymas(string name, vector<studentas> grupe, int VidArMed);
void padalinimas(vector<studentas>& grupe, vector<studentas>& grupe1);
void padalinimas1(vector<studentas> grupe, vector<studentas>& grupe1, vector<studentas>& grupe2);
void padalinimas2(vector<studentas>& grupe, vector<studentas>& grupe1);
void generavimas(string txt, int sk, int& ndsk);
void zmogausVP(string& vardas, string& pavarde);
