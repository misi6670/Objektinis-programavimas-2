#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;
using std::sort;
using std::count;

class Studentas
{
private:
    string Vardas_;
    string Pavarde_;
    vector <int> nd_;
    int n_;
    int egz_;
    float galutinis_;
    float vid_;
    float med_;
    int vidarmed_;
public:
    Studentas() {
        Vardas_ = "";
        Pavarde_ = "";
        n_ = 0;
        egz_ = 0;
        galutinis_ = 0;
        vid_ = 0;
        med_ = 0;
        vidarmed_ = 0;
    }
    Studentas(int vidmed, string vardas, string pavarde, int ndsk, vector<int> nd, int egzaminas) {
        vidarmed_ = vidmed;
        Vardas_ = vardas;
        Pavarde_ = pavarde;
        n_ = ndsk;
        nd_ = nd;
        nd_.reserve(n_);
        egz_ = egzaminas;
        vid_ = countVidurkis(); 
        med_ = countMediana();
        setGalutinis();
    }
    Studentas(string vardas, string pavarde, int ndsk, vector<int> nd, int egzaminas) {
        vidarmed_ = 0;
        Vardas_ = vardas;
        Pavarde_ = pavarde;
        n_ = ndsk;
        nd_ = nd;
        nd_.reserve(n_);
        egz_ = egzaminas;
        vid_ = 0;
        med_ = 0;
        galutinis_ = 0;
    }
    ~Studentas() { nd_.clear(); }
    Studentas(const Studentas& stud);
    Studentas& operator=(const Studentas& stud);
    void setVidarmed(int vam) { vidarmed_ = vam; }
    int getVidarmed() const { return vidarmed_; }
    void setVardas(string vardas) { Vardas_ = vardas; }
    string getVardas() const { return Vardas_; }
    void setPavarde(string pavarde) { Pavarde_ = pavarde; }
    string getPavarde() const { return Pavarde_; }
    void setND(vector <int> nd) { nd_ = nd; nd_.reserve(n_); vid_ = countVidurkis(); med_ = countMediana(); }
    vector<int> getND() const { return nd_; }
    void setNDskaicius(int ndsk) { n_ = ndsk; }
    int getNDskaicius() const { return n_; }
    void setEgzaminas(int egzaminas) { egz_ = egzaminas; }
    int getEgzaminas() const { return egz_; }
    void setGalutinis() { if (vidarmed_ == 1) galutinis_ = countGalutinis(med_); else galutinis_ = countGalutinis(vid_); }
    float getGalutinis() const { return galutinis_; }
    float countVidurkis();
    float countMediana();
    float countGalutinis(float vam);
    bool operator <(const Studentas& a) const;
    void isvedimas(char separator, int VardSimb, int PavSimb, int GalutSimb);
};
