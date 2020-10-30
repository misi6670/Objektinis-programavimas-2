#include "listai.h"

void lnuskaitymas(string txtname, list<lstudentas>& grupe, int& StudSkai, int VidArMed)
{
    int NamuDarbuSk;
    int pirmas = 0;
    list<string> eilute;
    string eil;
    ifstream f(txtname + ".txt");

    while (f) {
        if (!f.eof()) {
            std::getline(f, eil);
            eilute.push_back(eil);
        }
        else break;
    }
    f.close();

    for (auto str : eilute) {
        if (pirmas == 0) {
            NamuDarbuSk = count(str.begin(), str.end(), 'N');
            pirmas = 1;
        }
        else {
            lstudentas stud;
            stud.n = NamuDarbuSk;
            for (int i = 0; i < str.length(); i++)
            {
                if (str.at(i) >= 'A' && str.at(i) <= 'Z') {
                    if (stud.Vardas == "")
                        while (str.at(i) != ' ') {
                            stud.Vardas += str.at(i);
                            i++;
                        }
                    else
                        while (str.at(i) != ' ') {
                            stud.Pavarde += str.at(i);
                            i++;
                        }
                }
                else if (isdigit(str.at(i))) {
                    int a = i + 1;
                    if (i == str.length() - 2) {
                        stud.egz = (str.at(i) - '0') * 10 + (str.at(a) - '0');
                        i++;
                    }
                    else if (i == str.length() - 1) {
                        stud.egz = str.at(i) - '0';
                    }
                    else {
                        int paz = 0;
                        if (str.at(a) == ' ') paz = str.at(i) - '0';
                        else {
                            paz = (str.at(i) - '0') * 10 + (str.at(a) - '0');
                            i++;
                        }
                        stud.vid = stud.vid + (float)paz;
                        stud.nd.push_back(paz);
                    }
                }
            }
            if (VidArMed == 1) lmediana(stud);
            else stud.galutinis = stud.vid / (float)stud.n;
            stud.galutinis = stud.galutinis * 0.4 + (float)stud.egz * 0.6;
            grupe.push_back(stud);
            stud.nd.clear();
        }
    }
}

void lmediana(lstudentas& stud)
{
    stud.nd.sort();
    auto itr = stud.nd.begin();
    if (stud.nd.size() % 2 == 0) {
        for (int i = 0; i < stud.nd.size() / 2; i++) itr++;
        stud.galutinis = ((double)*itr + *--itr) / 2;
    }
    else {
        for (int i = 0; i < stud.nd.size() / 2; i++) itr++;
        stud.galutinis = *itr;
    }
}

void livedimas(list<lstudentas>& grupe, int StudSkai, int VidArMed, int AutoGen)
{
    for (int i = 0; i < StudSkai; i++) {
        lstudentas stud;

        cout << "\n Iveskite " << i + 1 << " studento varda ir pavarde \n";
        cin >> stud.Vardas >> stud.Pavarde;

        if (AutoGen == 1) lautogen(stud, i);
        else lpazymiai(stud, i);
        if (VidArMed == 1) lmediana(stud);
        else stud.galutinis = stud.vid / (float)stud.n;
        stud.galutinis = stud.galutinis * 0.4 + (float)stud.egz * 0.6;
        grupe.push_back(stud);
        stud.nd.clear();
    }
}

void lautogen(lstudentas& stud, int i)
{
    cout << "\n" << i + 1 << " studento atsitiktinai sugeneruoti pazymiai: \n";
    stud.n = lautosk(1, 15);
    for (int j = 0; j < stud.n; j++) {
        int random;
        random = lautosk(1, 10);
        cout << random << " ";
        stud.vid = stud.vid + (float)random;
        stud.nd.push_back(random);
    }
    cout << endl;
    stud.egz = lautosk(1, 10);
    cout << "\n" << i + 1 << " studento atsitiktinai sugeneruotas egzamino balas: " << stud.egz << endl;
}

int lautosk(int nuo, int iki)
{
    using hrClock = high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(nuo, iki);
    int sk = dist(mt);
    return sk;
}

void lpazymiai(lstudentas& stud, int i)
{
    cout << "\n Iveskite " << i + 1 << " studento pazymius, suvedus visus pazymius irasykite 0\n";
    int nulis = 1;
    while (nulis != 0) {
        int paz;
        cin >> paz;
        skaitymoKlaidosPaz(paz, stud.n);
        stud.vid = stud.vid + (float)paz;
        if (paz == 0) nulis = 0;
        else {
            stud.nd.push_back(paz);
            stud.n++;
            cout << "Ivedete " << stud.n << " pazymi(-ius)" << endl;
        }
    }
    cout << "\n Iveskite " << i + 1 << " studento egzamino rezultata \n";
    cin >> stud.egz;
    skaitymoKlaidosPaz(stud.egz, -1);
}

void lisvedimas(list<lstudentas> grupe, int VidArMed)
{
    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int GalutSimb = 16;

    grupe.sort();
    cout << endl;
    cout << left << setw(VardSimb) << setfill(separator) << "Vardas";
    cout << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    if (VidArMed == 1) cout << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Med.)" << endl;
    else cout << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Vid.)" << endl;
    cout << string(VardSimb + PavSimb + GalutSimb, '-') << endl;
    for (auto& tt : grupe) {
        cout << left << setw(VardSimb) << setfill(separator) << tt.Vardas;
        cout << left << setw(PavSimb) << setfill(separator) << tt.Pavarde;
        cout << left << setw(GalutSimb) << setfill(separator) << fixed << setprecision(2) << tt.galutinis << endl;
    }
}

void lirasymas(string name, list<lstudentas> grupe, int VidArMed)
{
    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int GalutSimb = 16;
    ofstream f(name);

    grupe.sort();
    f << left << setw(VardSimb) << setfill(separator) << "Vardas";
    f << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    if (VidArMed == 1) f << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Med.)" << endl;
    else f << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Vid.)" << endl;
    f << string(VardSimb + PavSimb + GalutSimb, '-') << endl;
    for (auto& tt : grupe) {
        f << left << setw(VardSimb) << setfill(separator) << tt.Vardas;
        f << left << setw(PavSimb) << setfill(separator) << tt.Pavarde;
        f << left << setw(GalutSimb) << setfill(separator) << fixed << setprecision(2) << tt.galutinis << endl;
    }
    f.close();
}

void lpadalinimas(list<lstudentas> grupe, list<lstudentas>& grupe1)
{
    auto it = grupe.begin();
    for (auto& tt : grupe) {
        if (tt.galutinis < 5) break;
        else it++;
    }
    grupe1.splice(grupe1.begin(), grupe, it, grupe.end());
}

void lgeneravimas(string txt, int sk, int& ndsk)
{
    list<lstudentas> grupe;

    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int NdSimb = 5;

    ofstream f(txt);

    if (sk <= 1000) ndsk = lautosk(1, 15);
    else if (sk <= 100000) ndsk = lautosk(1, 10);
    else ndsk = lautosk(1, 5);

    for (int i = 0; i < sk; i++) {
        lstudentas stud;
        stud.n = ndsk;
        lzmogausVP(stud.Vardas, stud.Pavarde);
        for (int j = 0; j < stud.n; j++) {
            int random;
            random = lautosk(1, 10);
            stud.vid = stud.vid + (float)random;
            stud.nd.push_back(random);
        }
        stud.egz = lautosk(1, 10);
        grupe.push_back(stud);
        stud.nd.clear();
    }

    f << left << setw(VardSimb) << setfill(separator) << "Vardas";
    f << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    for (int i = 0; i < ndsk; i++) f << left << setw(NdSimb) << setfill(separator) << "ND" + to_string(i + 1);
    f << "Egz." << endl;

    for (auto& tt : grupe) {
        f << left << setw(VardSimb) << setfill(separator) << tt.Vardas;
        f << left << setw(PavSimb) << setfill(separator) << tt.Pavarde;
        for (auto& ss : tt.nd) f << left << setw(NdSimb) << ss;
        f << tt.egz;
        if (&tt != &grupe.back()) f << endl;
    }

    f.close();
    grupe.clear();
}

void lzmogausVP(string& vardas, string& pavarde) {

    map<int, string> vardai, pavardes_m, pavardes_v;

    vardai[100] = "Irma";
    vardai[101] = "Alma";
    vardai[102] = "Irena";
    vardai[103] = "Egle";
    vardai[104] = "Jolanta";
    vardai[105] = "Julija";
    vardai[106] = "Goda";
    vardai[107] = "Kotryna";
    vardai[108] = "Ugne";
    vardai[109] = "Saule";
    vardai[110] = "Auguste";
    vardai[111] = "Milda";
    vardai[112] = "Gabija";
    vardai[113] = "Teja";
    vardai[114] = "Orinta";
    vardai[115] = "Emilija";
    vardai[116] = "Ilona";
    vardai[117] = "Sigita";
    vardai[118] = "Evelina";
    vardai[119] = "Aurelija";

    vardai[120] = "Petras";
    vardai[121] = "Jonas";
    vardai[122] = "Ignas";
    vardai[123] = "Darius";
    vardai[124] = "Simas";
    vardai[125] = "Paulius";
    vardai[126] = "Donatas";
    vardai[127] = "Rytis";
    vardai[128] = "Saulius";
    vardai[129] = "Valdas";
    vardai[130] = "Saulius";
    vardai[131] = "Gytis";
    vardai[132] = "Jokubas";
    vardai[133] = "Aurimas";
    vardai[134] = "Gvidas";
    vardai[135] = "Tomas";
    vardai[136] = "Rimas";
    vardai[137] = "Aidas";
    vardai[138] = "Dominykas";
    vardai[139] = "Kipras";

    vardas = vardai[lautosk(100, 139)];

    switch (*vardas.rbegin()) {
    case 's':
        pavarde = "Pavardenis" + to_string(lautosk(1, 500));
        break;
    default:
        pavarde = "Pavardaite" + to_string(lautosk(1, 500));
        break;
    };
}
