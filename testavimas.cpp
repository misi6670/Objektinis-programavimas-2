#include "testavimas.h"

void test(string txt, int duomsk, int StudSkai, int VidArMed)
{
    vector <studentas> nuskaitytas;
    vector <studentas> grupe;
    vector <studentas> grupe1;
    vector <studentas> grupe2;
    list <lstudentas> lnuskaitytas;
    list <lstudentas> lgrupe;
    list <lstudentas> lgrupe1;
    list <lstudentas> lgrupe2;
    int ndsk = 0;

    cout << endl;
    generavimas(txt + ".txt", duomsk, ndsk);
    cout << "Failo is " << duomsk << " irasu (namu darbu skaicius: " << ndsk << ") testas: " << endl;
    cout << endl;

    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant vektorius: \n";

    nuskaitymas(txt, nuskaitytas, StudSkai, VidArMed);
    
    grupe = nuskaitytas;
    auto start = high_resolution_clock::now();
    padalinimas(grupe, grupe1);
    duration<double> diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant mano strategija uztruko: " << diff.count() << " s\n";
    
    grupe1.clear();
    grupe.clear();

    grupe = nuskaitytas;
    start = high_resolution_clock::now();
    padalinimas1(grupe, grupe1, grupe2);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant 1 strategija uztruko: " << diff.count() << " s\n";

    grupe1.clear();
    grupe2.clear();
    grupe.clear();
    
    grupe = nuskaitytas;
    start = high_resolution_clock::now();
    padalinimas2(grupe, grupe1);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant 2 strategija uztruko: " << diff.count() << " s\n";
    
    cout << endl;
    grupe1.clear();
    grupe.clear();
    nuskaitytas.clear();

    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant sarasa: \n";

    lnuskaitymas(txt, lnuskaitytas, StudSkai, VidArMed);

    lgrupe = lnuskaitytas;
    start = high_resolution_clock::now();
    lpadalinimas(lgrupe, lgrupe1);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant mano strategija uztruko: " << diff.count() << " s\n";
    
    lgrupe.clear();
    lgrupe1.clear();

    lgrupe = lnuskaitytas;
    start = high_resolution_clock::now();
    lpadalinimas1(lgrupe, lgrupe1, lgrupe2);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant 1 strategija uztruko: " << diff.count() << " s\n";

    lgrupe.clear();
    lgrupe1.clear();
    lgrupe2.clear();
    
    lgrupe = lnuskaitytas;
    start = high_resolution_clock::now();
    lpadalinimas2(lgrupe, lgrupe1);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant 2 strategija uztruko: " << diff.count() << " s\n";
    
    cout << endl;
    lgrupe.clear();
    lgrupe1.clear();
    lnuskaitytas.clear();
}
