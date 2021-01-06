#pragma once

#include"zmogus.h"
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::count;

class Studentas : public Zmogus
{
private:
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
    Studentas(const Studentas& stud)
        : Zmogus(stud.Vardas_, stud.Pavarde_),
        nd_{ stud.nd_ },
        n_{ stud.n_ },
        egz_{ stud.egz_ },
        galutinis_{ stud.galutinis_ },
        vid_{ stud.vid_ },
        med_{ stud.med_ },
        vidarmed_{ stud.vidarmed_ } {
        Vardas_ = stud.Vardas_;
        Pavarde_ = stud.Pavarde_;
        nd_ = stud.nd_;
        n_ = stud.n_;
        egz_ = stud.egz_;
        galutinis_ = stud.galutinis_;
        vid_ = stud.vid_;
        med_ = stud.med_;
        vidarmed_ = stud.vidarmed_;
    }
    Studentas& operator=(const Studentas& stud) {
        if (&stud == this) return *this;
        nd_.clear();
        Vardas_ = stud.Vardas_;
        Pavarde_ = stud.Pavarde_;
        nd_ = stud.nd_;
        n_ = stud.n_;
        egz_ = stud.egz_;
        galutinis_ = stud.galutinis_;
        vid_ = stud.vid_;
        med_ = stud.med_;
        vidarmed_ = stud.vidarmed_;
        return *this;
    }
    void setVidarmed(int vam) { vidarmed_ = vam; }
    int getVidarmed() const { return vidarmed_; }
    void setND(vector <int> nd) { nd_ = nd; nd_.reserve(n_); vid_ = countVidurkis(); med_ = countMediana(); }
    vector<int> getND() const { return nd_; }
    void setNDskaicius(int ndsk) { n_ = ndsk; }
    int getNDskaicius() const { return n_; }
    void setEgzaminas(int egzaminas) { egz_ = egzaminas; }
    int getEgzaminas() const { return egz_; }
    void setGalutinis() { if (vidarmed_ == 1) galutinis_ = countGalutinis(med_); else galutinis_ = countGalutinis(vid_); }
    float getGalutinis() const { return galutinis_; }
    float countVidurkis() {
        float suma = 0;
        for (float a : nd_) suma = suma + a;
        return vid_ = suma / n_;
    }
    float countMediana() {
        sort(nd_.begin(), nd_.end());
        if (n_ % 2 != 0) return med_ = (float)nd_.at(n_ / 2);
        else {
            int m;
            m = nd_.at((n_ - 1) / 2) + nd_.at(n_ / 2);
            return med_ = (float)m / 2.0;
        }
    }
    float countGalutinis(float vam) {
        return galutinis_ = vam * 0.4 + (float)egz_ * 0.6;
    }
    bool operator <(const Studentas& a) const {
        if (getVardas() != a.getVardas())
            return getVardas().compare(a.getVardas()) < 0;

        if (getPavarde() != a.getPavarde())
            return getPavarde().compare(a.getPavarde()) < 0;

        return (getGalutinis() > a.getGalutinis());
    }
    bool operator ==(const Studentas& a) const {
        if (getVardas() != a.getVardas())
            return 0;

        if (getPavarde() != a.getPavarde())
            return 0;

        if (getND() != a.getND())
            return 0;

        if (getNDskaicius() != a.getNDskaicius())
            return 0;

        if (getEgzaminas() != a.getEgzaminas())
            return 0;

        if (getGalutinis() != a.getGalutinis())
            return 0;

        if (getVidarmed() != a.getVidarmed())
            return 0;

        return 1;
    }
    void isvedimas(char separator, int VardSimb, int PavSimb, int GalutSimb) {
        const char separator_ = separator;
        const int VardSimb_ = VardSimb;
        const int PavSimb_ = PavSimb;
        const int GalutSimb_ = GalutSimb;
        Zmogus::isvedimas(separator_, VardSimb_, PavSimb_);
        cout << left << setw(GalutSimb_) << setfill(separator_) << fixed << setprecision(2) << getGalutinis() << endl;
    }
};
