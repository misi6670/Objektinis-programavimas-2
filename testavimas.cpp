#include "testavimas.h"

void test(string txt, int duomsk, int StudSkai, int VidArMed)
{
    vector <studentas> grupe;
    vector <studentas> grupe1;
    list <lstudentas> lgrupe;
    list <lstudentas> lgrupe1;
    int ndsk = 0;

    cout << endl;
    generavimas(txt + ".txt", duomsk, ndsk);
    cout << "Failo is " << duomsk << " irasu (namu darbu skaicius: " << ndsk << ") testas: " << endl;
    cout << endl;

    auto start = high_resolution_clock::now(); auto st = start;
    nuskaitymas(txt, grupe, StudSkai, VidArMed);
    duration<double> diff = high_resolution_clock::now() - start;
    cout << duomsk << " irasu nuskaitymas is failo naudojant vektorius uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    padalinimas(grupe, grupe1);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant vektorius uztruko: " << diff.count() << " s\n";

    diff = high_resolution_clock::now() - st;
    cout << endl << duomsk << " vektor'iaus irasu testo laikas: " << diff.count() << " s\n";
    cout << endl;

    grupe1.clear();
    grupe.clear();

    start = high_resolution_clock::now(); st = start;
    lnuskaitymas(txt, lgrupe, StudSkai, VidArMed);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " irasu nuskaitymas is failo naudojant sarasa uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    lpadalinimas(lgrupe, lgrupe1);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas naudojant sarasa uztruko: " << diff.count() << " s\n";

    diff = high_resolution_clock::now() - st;
    cout << endl << duomsk << " list'o irasu testo laikas: " << diff.count() << " s\n";
    cout << endl;

    lgrupe.clear();
    lgrupe1.clear();
}
