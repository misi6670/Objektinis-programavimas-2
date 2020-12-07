#include "studentas.h"

float Studentas::countVidurkis() { 
    float suma = 0; 
    for (float a : nd_) suma = suma + a; 
    return vid_ = suma / n_; 
}

float Studentas::countMediana() {
    sort(nd_.begin(), nd_.end());
    if (n_ % 2 != 0) return med_ = (float)nd_.at(n_ / 2);
    else {
        int m;
        m = nd_.at((n_ - 1) / 2) + nd_.at(n_ / 2);
        return med_ = (float)m / 2.0;
    }
}

float Studentas::countGalutinis(float vam) { 
    return galutinis_ = vam * 0.4 + (float)egz_ * 0.6;
}

bool Studentas::operator <(const Studentas& a) const {
    if (getVardas() != a.getVardas())
        return getVardas().compare(a.getVardas()) < 0;

    if (getPavarde() != a.getPavarde())
        return getPavarde().compare(a.getPavarde()) < 0;

    return (getGalutinis() > a.getGalutinis());
}

void Studentas::isvedimas(char separator, int VardSimb, int PavSimb, int GalutSimb) {
    const char separator_ = separator;
    const int VardSimb_ = VardSimb;
    const int PavSimb_ = PavSimb;
    const int GalutSimb_ = GalutSimb;
    cout << left << setw(VardSimb_) << setfill(separator_) << getVardas();
    cout << left << setw(PavSimb_) << setfill(separator_) << getPavarde();
    cout << left << setw(GalutSimb_) << setfill(separator_) << fixed << setprecision(2) << getGalutinis() << endl;
}
