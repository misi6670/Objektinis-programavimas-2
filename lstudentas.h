#pragma once

#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::string;
using std::list;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;
using std::sort;
using std::count;

class Lstudentas
{
private:
    string Vardas_;
    string Pavarde_;
    list <int> nd_;
    int n_;
    int egz_;
    float galutinis_;
    float vid_;
    float med_;
    int vidarmed_;
public:
    Lstudentas() {
        Vardas_ = "";
        Pavarde_ = "";
        n_ = 0;
        egz_ = 0;
        galutinis_ = 0;
        vid_ = 0;
        med_ = 0;
        vidarmed_ = 0;
    }
    Lstudentas(int vidmed, string vardas, string pavarde, int ndsk, list<int> nd, int egzaminas) {
        vidarmed_ = vidmed;
        Vardas_ = vardas;
        Pavarde_ = pavarde;
        n_ = ndsk;
        nd_ = nd;
        egz_ = egzaminas;
        setGalutinis();
    }
    Lstudentas(string vardas, string pavarde, int ndsk, list<int> nd, int egzaminas) {
        vidarmed_ = 0;
        Vardas_ = vardas;
        Pavarde_ = pavarde;
        n_ = ndsk;
        nd_ = nd;
        egz_ = egzaminas;
        vid_ = 0;
        med_ = 0;
        galutinis_ = 0;
    }
    ~Lstudentas() { nd_.clear(); }
    Lstudentas(const Lstudentas& stud);
    Lstudentas& operator=(const Lstudentas& stud);
    void setVidarmed(int vam) { vidarmed_ = vam; }
    int getVidarmed() const { return vidarmed_; }
    void setVardas(string vardas) { Vardas_ = vardas; }
    string getVardas() const { return Vardas_; }
    void setPavarde(string pavarde) { Pavarde_ = pavarde; }
    string getPavarde() const { return Pavarde_; }
    void setND(list <int> nd) { nd_ = nd; vid_ = countVidurkis(); med_ = countMediana(); }
    list<int> getND() const { return nd_; }
    void setNDskaicius(int ndsk) { n_ = ndsk; }
    int getNDskaicius() const { return n_; }
    void setEgzaminas(int egzaminas) { egz_ = egzaminas; }
    int getEgzaminas() const { return egz_; }
    void setGalutinis() { if (vidarmed_ == 1) galutinis_ = countGalutinis(med_); else galutinis_ = countGalutinis(vid_); }
    float getGalutinis() const { return galutinis_; }
    float countVidurkis();
    float countMediana();
    float countGalutinis(float vam);
    bool operator <(const Lstudentas& a) const;
    void isvedimas(char separator, int VardSimb, int PavSimb, int GalutSimb);
};

void lnuskaitymas(string txtname, list<Lstudentas>& grupe, int& StudSkai, int VidArMed);
void livedimas(list<Lstudentas>& grupe, int StudSkai, int VidArMed, int AutoGen);
int lautosk(int nuo, int iki);
void lisvedimas(list<Lstudentas> grupe, int VidArMed);
void lirasymas(string name, list<Lstudentas> grupe, int VidArMed);
void lpadalinimas(list<Lstudentas>& grupe, list<Lstudentas>& grupe1);
void lpadalinimas1(list<Lstudentas> grupe, list<Lstudentas>& grupe1, list<Lstudentas>& grupe2);
void lpadalinimas2(list<Lstudentas>& grupe, list<Lstudentas>& grupe1);
void lgeneravimas(string txt, int sk, int& ndsk);
void lzmogausVP(string& vardas, string& pavarde);
