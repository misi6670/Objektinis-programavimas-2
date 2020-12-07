#include "lstudentas.h"

float Lstudentas::countVidurkis() { 
    float suma = 0; 
    for (float a : nd_) suma = suma + a; 
    return vid_ = suma / n_;
}

float Lstudentas::countMediana() {
    nd_.sort();
    auto itr = nd_.begin();
    if (nd_.size() % 2 == 0) {
        for (int i = 0; i < nd_.size() / 2; i++) itr++;
        return med_ = ((double)*itr + *--itr) / 2;
    }
    else {
        for (int i = 0; i < nd_.size() / 2; i++) itr++;
        return med_ = *itr;
    }
}

float Lstudentas::countGalutinis(float vam) { 
    return galutinis_ = vam * 0.4 + (float)egz_ * 0.6; 
}

bool Lstudentas::operator <(const Lstudentas& a) const {
    if (getVardas() != a.getVardas())
        return getVardas().compare(a.getVardas()) < 0;

    if (getPavarde() != a.getPavarde())
        return getPavarde().compare(a.getPavarde()) < 0;

    return (getGalutinis() > a.getGalutinis());
}

void Lstudentas::isvedimas(char separator, int VardSimb, int PavSimb, int GalutSimb) {
    const char separator_ = separator;
    const int VardSimb_ = VardSimb;
    const int PavSimb_ = PavSimb;
    const int GalutSimb_ = GalutSimb;
    cout << left << setw(VardSimb_) << setfill(separator_) << getVardas();
    cout << left << setw(PavSimb_) << setfill(separator_) << getPavarde();
    cout << left << setw(GalutSimb_) << setfill(separator_) << fixed << setprecision(2) << getGalutinis() << endl;
}
