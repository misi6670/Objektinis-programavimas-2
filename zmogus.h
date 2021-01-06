#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::string;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;

class Zmogus
{
protected:
    string Vardas_;
    string Pavarde_;
    Zmogus() {
        Vardas_ = "";
        Pavarde_ = "";
    }
    Zmogus(string vardas, string pavarde) {
        Vardas_ = vardas;
        Pavarde_ = pavarde;
    }
    Zmogus(const Zmogus& zmg)
        : Vardas_{ zmg.Vardas_ },
        Pavarde_{ zmg.Pavarde_ } {
        Vardas_ = zmg.Vardas_;
        Pavarde_ = zmg.Pavarde_;
    }
    Zmogus& operator=(const Zmogus& zmg) {
        if (&zmg == this) return *this;
        Vardas_ = zmg.Vardas_;
        Pavarde_ = zmg.Pavarde_;
        return *this;
    }
    void setVardas(string vardas) { Vardas_ = vardas; }
    void setPavarde(string pavarde) { Pavarde_ = pavarde; }
public:
    virtual ~Zmogus() { }
    virtual string getVardas() const { return Vardas_; }
    virtual string getPavarde() const { return Pavarde_; }
    virtual bool operator <(const Zmogus& a) const {
        if (getVardas() != a.getVardas())
            return getVardas().compare(a.getVardas()) < 0;

        return getPavarde().compare(a.getPavarde()) < 0;
    }
    virtual void isvedimas(char separator, int VardSimb, int PavSimb) {
        const char separator_ = separator;
        const int VardSimb_ = VardSimb;
        const int PavSimb_ = PavSimb;
        cout << left << setw(VardSimb_) << setfill(separator_) << getVardas();
        cout << left << setw(PavSimb_) << setfill(separator_) << getPavarde();
    }
};
