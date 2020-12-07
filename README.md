# Programos versija V1.1
Ši programa nuskaito vartotojų įvedamus duomenis (studento vardą ir pavardę, namų darbų ir egzamino rezultatą). Baigus duomenų įvedimą, suskaičiuoja galutinį balą ir juos pateikia į ekraną. Galutinis balas skaičiuojamas pagal vartotojo pasirinkimą - naudojant vidurkį arba medianą ir yra pateikiamas dviejų skaičių po kablelio tikslumu. Studentai padalinami į dvi kategorijas - "išlaikiusieji" (studentai, kurių galutinis balas >= 5.0) ir "neišlaikiusieji" (studentai, kurių galutinis balas < 5.0) - ir atitinkamai išvedami į du naujus failus - "islaike.txt" ir "neislaike.txt". Studentai išvedami surūšiuoti pagal vardus, pavardes ir galutinį pažymį. Vartotojui pasirinkus, studento pažymius galima generuoti atsitiktinai, duomenis taip pat galima nuskaityti iš failo.

Šioje realizacijoje vietoje struktūros "studentas" naudojama sukurta klasė "Studentas". Vartotojui pasirinkus, galima atlikti programos veikimo greičio (spartos) analizę. Testas atliekamas su 2 failais iš 100000, 1000000 įrašų, testo metu jie yra sugeneruojami ir pasibaigus testavimui ištrinami. Matavimai atliekami su kiekvienu failu. Matuojamas: studentų rūšiavimas į dvi grupes/kategorijas greičiausia strategija, naudojant vektorio tipo konteinerį.

1. Naudojamos bibliotekos aprašytos ***klaidos.h***, ***listai.h***, ***lstudentai.h***, ***studentai.h***, ***testavimas.h*** ir ***vektoriai.h*** failuose
2. Naudojamos funkcijos surašytos ***klaidos.cpp***, ***listai.cpp***, ***lstudentai.cpp***, ***studentai.cpp***, ***testavimas.cpp*** ir ***vektoriai.cpp*** failuose
3. **testavimas.h** ir **vektoriai.h** bibliotekos naudojamos **V1.1.cpp** faile
4. **klaidos.h** biblioteka naudojama **listai.h** ir **vektoriai.h** failuose
5. **listai.h** ir **vektoriai.h** bibliotekos naudojamos **testavimas.h** faile
6. **lstudentas.h** biblioteka naudojama **listai.h** faile
7. **studentas.h** biblioteka naudojama **vektoriai.h** faile

* [V1.0 versija](https://github.com/misi6670/Objektinis-programavimas/releases/tag/V1.0) 
Programa parašyta naudojant struktūrą "studentas".

# Programos veikimo greičio (spartos) analizė
## Pagal studentų dalijimo į dvi kategorijas strategijas
* Greičiausia strategija: Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "neišlaikę". Tokiu būdu, jei studentas yra neišlaikęs, jį turime įkelti į naująjį "neišlaikiusiųjų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik išlaikę.

Testas 1 (Release), galutinis balas skaičiuojamas pagal vidurkį:

| Programos versija | Flag | 100000 įrašų (namų darbų skaičius: 7) | 1000000 įrašų (namų darbų skaičius: 4) |
| ---------- | ---- | ---------------- | ------------- |
| V1.0 | none | 0.0071902 | 0.06781 |
| V1.1 | none | 0.024098 | 0.202245 |
| V1.1 | /O1 | 0.024781 | 0.201625 |
| V1.1 | /O2 | 0.0281015 | 0.20524 |
| V1.1 | /Ox | 0.0239226 | 0.203597 |


Testas 2 (Release), galutinis balas skaičiuojamas pagal medianą:

| Programos versija | Flag | 100000 įrašų (namų darbų skaičius: 7) | 1000000 įrašų (namų darbų skaičius: 4) |
| ---------- | -----| --------------- | ------------- |
| V1.0 | none | 0.0071773 | 0.0684974 |
| V1.1 | none | 0.0175735 | 0.198012 |
| V1.1 | /O1 | 0.0181742 | 0.2048 |
| V1.1 | /O2 | 0.018943 | 0.196963 |
| V1.1 | /Ox | 0.0175677 | 0.201092 |

## Testavimo sistemos parametrai

* CPU -	AMD Ryzen 5 3500 6-Core Processor;
* RAM - 16,0 GB DDR4;
* SSD (480GB).

# Programos naudojimosi instrukcija
Paleidus programą, reikia pasirinkti, ar norite atlikti testavimą.
Norėdami atlikti testavimą, reikia įvesti '1', kitu atveju įrašyti '0' ar bet kokį kitą skaičių, išskyrus '1'.
<ol>
<li> Pasirinkus vykdyti testavimą, t.y. įvedus '1', reikės pasirinkti pagal ką norite, kad būtų skaičiuojamas galutinis balas.
Norėdami, kad galutinis balas būtų skaičiuojamas pagal medianą, įveskite '1', jeigu pagal vidurkį, įveskite bet kokį kitą skaičių, pavyzdžiui, '0'. 
Tuomet yra atliekamas testas ir išvedami rezultatai į ekraną tokiu pavidalu:

```
Failo is 100000 irasu (namu darbu skaicius: 8) testas:
100000 studentu rusiavimas i dvi grupes/kategorijas naudojant vektoriu ir greiciausia strategija uztruko: 0.024373 s


Failo is 1000000 irasu (namu darbu skaicius: 3) testas:
1000000 studentu rusiavimas i dvi grupes/kategorijas naudojant vektoriu ir greiciausia strategija uztruko: 0.201436 s
```

Testas atliekamas su failais iš 1000, 10000, 100000, 1000000 ir 10000000 įrašų, namų darbų skaičius generuojamas atsitiktinai ir kiekvienam failui skiriasi.
Programa baigia darbą, procesas sustabdomas. </li>

<li> Pasirinkus testavimo nevykdyti, t.y. įvedus, pavyzdžiui, '0', reikės pasirinkti pagal ką norite, kad būtų skaičiuojamas galutinis balas.
Norėdami, kad galutinis balas būtų skaičiuojamas pagal medianą, įveskite '1', jeigu pagal vidurkį, įveskite bet kokį kitą skaičių, pavyzdžiui, '0'. 
Tuomet reikia pasirinkti, ar norite nuskaityti duomenis iš failo. Norėdami duomenis nuskaityti iš failo įveskite '1', kitu atveju įveskite '0' ar bet kokį kitą skaičių.
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
