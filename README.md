* [V0.1 versija](https://github.com/misi6670/Objektinis-programavimas/releases/tag/v0.1)
* [V0.2 versija](https://github.com/misi6670/Objektinis-programavimas/releases/tag/V0.2)
* [V0.3 versija](https://github.com/misi6670/Objektinis-programavimas/releases/tag/v0%2C3)
* [V0.4 versija](https://github.com/misi6670/Objektinis-programavimas/releases/tag/V0.4)
* [V0.5 versija](https://github.com/misi6670/Objektinis-programavimas/releases/tag/V0.5)

# Programos veikimo greičio (spartos) analizė
## Pagal studentų dalijimo į dvi kategorijas strategijas
* Mano strategija: Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "neišlaikiusių" ir "išlaikiusių". Tada "išlaikiusiųjų" konteinerį priskiriam bendram studentų konteineriui, o "išlaikiusiųjų" konteinerį ištriname. Tokiu būdu sukuriame 2 naujus konteinerius ir po skaidymo vieną iš jų ištriname. Studentai lieka tik viename iš dviejų konteinerių: bendrame studentų arba "neišlaikiusiųjų".
* 1 strategija: Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "neišlaikiusių" ir "išlaikiusių". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (neišlaikę arba išlaikę).
* 2 strategija: Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "neišlaikę". Tokiu būdu, jei studentas yra neišlaikęs, jį turime įkelti į naująjį "neišlaikiusiųjų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik išlaikę.

Testas 1 (Release), galutinis balas skaičiuojamas pagal vidurkį:

| Strategija | *vector*/*list* konteineris | 1000 įrašų (namų darbų skaičius: 10) | 10000 įrašų (namų darbų skaičius: 9) | 100000 įrašų (namų darbų skaičius: 5) | 1000000 įrašų (namų darbų skaičius: 2) | 10000000 įrašų (namų darbų skaičius: 5) |
| ---------- | -------------------- | ------------- | -------- | ------- | --------- | --------|
| Mano | *vector* | 0.0002985 | 0.0034475 | 0.0395566 | 0.372931 | 4.81561 |
| Mano | *list* | 0.0011241 | 0.0196356 | 0.100894 | 0.688984 | 59.5936 |
| 1 | *vector* | 0.0003918 | 0.0036504 | 0.038899 | 0.41747 | 4.91621 |
| 1 | *list* | 0.0019724 | 0.0354478 | 0.139332 | 0.924297 | 97.8132 |
| 2 | *vector* | 6.89e-05 | 0.0007037 | 0.0102181 | 0.0777053 | 1.10297 |
| 2 | *list* | 0.0004887 | 0.0081591 | 0.0494522 | 0.347034 | 6.97383 |

Testas 2 (Release), galutinis balas skaičiuojamas pagal medianą:

| Strategija | *vector*/*list* konteineris | 1000 įrašų (namų darbų skaičius: 3) | 10000 įrašų (namų darbų skaičius: 10) | 100000 įrašų (namų darbų skaičius: 5) | 1000000 įrašų (namų darbų skaičius: 3) | 10000000 įrašų (namų darbų skaičius: 5) |
| ---------- | -------------------- | ------------- | -------- | ------- | --------- | --------|
| Mano | *vector* | 0.000288 | 0.0042814 | 0.0366799 | 0.40431 | 4.5509 |
| Mano | *list* | 0.000649 | 0.0162968 | 0.0966317 | 0.767944 | 26.1436 |
| 1 | *vector* | 0.0003367 | 0.004328 | 0.0382126 | 0.404099 | 9.31737 |
| 1 | *list* | 0.0008952 | 0.0252198 | 0.141386 | 1.19202 | 47.7655 |
| 2 | *vector* | 5.61e-05 | 0.0006266 | 0.0088301 | 0.0934583 | 0.970382 |
| 2 | *list* | 0.0002275 | 0.0064777 | 0.0456874 | 0.395467 | 8.32207 |

# Programos naudojimosi instrukcija
Paleidus programą, jums reikės pasirinkti, ar norite atlikti testavimą.
Norėdami atlikti testavimą, reikia įvesti '1', kitu atveju įrašyti '0' ar bet kokį kitą skaičių, išskyrus '1'.
<ol>
<li> Pasirinkus vykdyti testavimą, t.y. įvedus '1', reikės pasirinkti pagal ką norite, kad būtų skaičiuojamas galutinis balas.
Norėdami, kad galutinis balas būtų skaičiuojamas pagal medianą, įveskite '1', jeigu pagal vidurkį, įveskite bet kokį kitą skaičių, pavyzdžiui, '0'. 
<ol>
<li> Tuomet yra atliekamas testas ir išvedami rezultatai, rezultatai išvedami į ekraną tokiu pavidalu:

```
Failo is 1000 irasu (namu darbu skaicius: 3) testas:

1000 studentu rusiavimas i dvi grupes/kategorijas naudojant vektorius:
1000 studentu rusiavimas i dvi grupes/kategorijas naudojant mano strategija uztruko: 0.0003393 s
1000 studentu rusiavimas i dvi grupes/kategorijas naudojant 1 strategija uztruko: 0.0003538 s
1000 studentu rusiavimas i dvi grupes/kategorijas naudojant 2 strategija uztruko: 5.85e-05 s

1000 studentu rusiavimas i dvi grupes/kategorijas naudojant sarasa:
1000 studentu rusiavimas i dvi grupes/kategorijas naudojant mano strategija uztruko: 0.0005333 s
1000 studentu rusiavimas i dvi grupes/kategorijas naudojant 1 strategija uztruko: 0.0008412 s
1000 studentu rusiavimas i dvi grupes/kategorijas naudojant 2 strategija uztruko: 0.0002125 s
```

Testas atliekamas su failais iš 1000, 10000, 100000, 1000000 ir 10000000 įrašų, namų darbų skaičius generuojamas atsitiktinai ir kiekvienam failui skiriasi.
Programa baigia darbą, procesas sustabdomas. </li>
</ol></li>
<li> Pasirinkus testavimo nevykdyti, t.y. įvedus, pavyzdžiui, '0', reikės pasirinkti pagal ką norite, kad būtų skaičiuojamas galutinis balas.
Norėdami, kad galutinis balas būtų skaičiuojamas pagal medianą, įveskite '1', jeigu pagal vidurkį, įveskite bet kokį kitą skaičių, pavyzdžiui, '0'.
<ol>
<li> Tuomet reikia pasirinkti, ar norite nuskaityti duomenis iš failo. Norėdami duomenis nuskaityti iš failo įveskite '1';
Kitu atveju įveskite '0' ar bet kokį kitą skaičių.
<ol>
<li> Pasirinkus nuskaityti duomenis iš failo, t.y. įvedus '1', programa jūsų paprašys įvesti norimo nuskaityti tekstinio failo pavadinimą, tačiau '.txt' rašyti nereikia. Pavyzdžiui, jei norite, kad programa nuskaitytų failą 'studentai.txt', tai reikia įvesti tik patį pavadinimą, t.y. tik 'studentai'.
Tuomet rezultatai bus išvedami į ekraną tokiu šablonu:

```
Vardas         Pavarde        Galutinis (Vid./Med.)
---------------------------------------------------
Vardas1        Pavarde1       7.80
Vardas2        Pavarde2       6.40
Vardas3        Pavarde3       3.00
Vardas4        Pavarde4       9.00
```

Taip pat bus sukurti du failai 'islaike' ir 'neislaike', kuriuose studentai bus padalinti atitinkamai į tuos, kurių galutinis pažymys didesnis arba lygus 5, ir tuos, kurių galutinis pažymys mažesnis negu 5. Studentai surūšiuoti pagal vardą, pavardę ir galutinį balą. Programa baigia darbą, procesas sustabdomas.
</li>
</ol>
</li>
<li> Pasirinkus nenuskaityti duomenis iš failo, pavyzdžiui, įvedus '0', jums reikės pasirinkti, ar norite, kad studento namų darbų ir egzamino balus programa sugeneruotų automatiškai. Norėdami, kad programa sugeneruotų balus automatiškai, reikia įvesti '1', kitu atveju - '0' arba bet kokį kitą skaičių. 
<ol>
<li> Pasirinkus generuoti pažymius automatiškai, t.y. įvedus '1', jūsų programa paprašys įvesti studentų skaičių. Įvedus studentų skaičių, jums reikės suvesti studento vardą ir pavardę. Suvedus studento vardą ir pavardę, programa sugeneruoja pažymius ir juos išveda į ekraną tokiu pavidalu:

```
1 studento atsitiktinai sugeneruoti pazymiai:
3 10 10 3 3 4 7 1 7 6 10 6 2 10

1 studento atsitiktinai sugeneruotas egzamino balas: 7
```
Suvedus visų studentų vardus ir pavardes, į ekraną išvedami studentai, surūšiuoti pagal vardą, pavardę ir galutinį balą, tokiu pavidalu:

```
Vardas         Pavarde        Galutinis (Vid./Med.)
---------------------------------------------------
Vardas1        Pavarde1       7.80
Vardas2        Pavarde2       6.40
Vardas3        Pavarde3       3.00
Vardas4        Pavarde4       9.00
```

Taip pat bus sukurti du failai 'islaike' ir 'neislaike', kuriuose studentai bus padalinti atitinkamai į tuos, kurių galutinis pažymys didesnis arba lygus 5, ir tuos, kurių galutinis pažymys mažesnis negu 5. Studentai surūšiuoti pagal vardą, pavardę ir galutinį balą. Programa baigia darbą, procesas sustabdomas.
</li>
<li> Pasirinkus negeneruoti pažymių automatiškai, pavyzdžiui, įvedus '0', jūsų programa paprašys įvesti studentų skaičių. Įvedus studentų skaičių, jums reikės suvesti studento vardą ir pavardę. Suvedus studento vardą ir pavardę, programa jūsų paprašys suvesti studento pažymius, kai įvesite bent vieną pažymį, programa jums parašys kiek pažymių jau įvedėte, pavyzdžiui:

```
 Iveskite 1 studento pazymius, suvedus visus pazymius irasykite 0
5
Ivedete 1 pazymi(-ius)
6
Ivedete 2 pazymi(-ius)
7
Ivedete 3 pazymi(-ius)
10
Ivedete 4 pazymi(-ius)
0
```

Suvedus visus pažymius įveskite '0', kad programa suprastų, jog baigėte vesti visus pažymius. Tuomet programa paprašys jūsų įvesti studento egzamino pažymį. Suvedus visų studentų vardus ir pavardes, namų darbų pažymius ir egzamino rezultatus, į ekraną išvedami studentai, surūšiuoti pagal vardą, pavardę ir galutinį balą, tokiu pavidalu:

```
Vardas         Pavarde        Galutinis (Vid./Med.)
---------------------------------------------------
Vardas1        Pavarde1       7.80
Vardas2        Pavarde2       6.40
Vardas3        Pavarde3       3.00
Vardas4        Pavarde4       9.00
```

Taip pat bus sukurti du failai 'islaike' ir 'neislaike', kuriuose studentai bus padalinti atitinkamai į tuos, kurių galutinis pažymys didesnis arba lygus 5, ir tuos, kurių galutinis pažymys mažesnis negu 5. Studentai surūšiuoti pagal vardą, pavardę ir galutinį balą. Programa baigia darbą, procesas sustabdomas. </li>
</ol>
</li>
</ol>
</li>
</ol>
