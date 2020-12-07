#include "testavimas.h"

void test(string txt, int duomsk, int StudSkai, int VidArMed)
{
    vector <Studentas> nuskaitytas;
    vector <Studentas> grupe;
    vector <Studentas> grupe1;
    list <Lstudentas> lnuskaitytas;
    list <Lstudentas> lgrupe;
    list <Lstudentas> lgrupe1;
    int ndsk = 0;

    cout << endl;
    generavimas(txt + ".txt", duomsk, ndsk);
    cout << "Failo is " << duomsk << " irasu (namu darbu skaicius: " << ndsk << ") testas: " << endl;
    cout << endl;

    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant vektorius: \n";

    nuskaitymas(txt, grupe, StudSkai, VidArMed);
    
    auto start = high_resolution_clock::now();
    padalinimas2(grupe, grupe1);
    duration<double> diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant 2 strategija uztruko: " << diff.count() << " s\n";
    
    cout << endl;
    grupe1.clear();
    grupe.clear();
    nuskaitytas.clear();

    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant sarasa: \n";

    lnuskaitymas(txt, lgrupe, StudSkai, VidArMed);
    start = high_resolution_clock::now();
    lpadalinimas2(lgrupe, lgrupe1);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant 2 strategija uztruko: " << diff.count() << " s\n";
    
    cout << endl;
    lgrupe.clear();
    lgrupe1.clear();
}
