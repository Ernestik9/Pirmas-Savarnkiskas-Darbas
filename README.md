V0.2 Programa

Ši programa skirta studentų balams skaičiuoti pagal namų darbų ir egzamino rezultatus. Programos metu galima pasirinkti, ar naudoti vidurkį, ar medianą galutiniam balui apskaičiuoti. Šioje versijoje pridedame spartos analizę ir optimizaciją naudojant įvairius konteinerius.

1.Generuojami atsitiktiniai studentų duomenys.Sugeneruojama penkių studentų sąrašų failai su skirtingais įrašų kiekiais: 
     1000 įrašų
     10000 įrašų
     100000 įrašų
     1000000 įrašų
     10000000 įrašų
2.Studentai yra rūšiuojami į dvi grupes:
     Vargšiukai: studentai, kurių galutinis balas < 5.0
     Kietiakiai: studentai, kurių galutinis balas >= 5.0
     Surūšiuoti studentai išvedami į du naujus failus, atitinkančius kiekvieną grupę.
     
     3.Programos veikimo greičio analizė.Atlikta programos spartumo analizė, matuojant laiką, užtrukusį atliekant šiuos žingsnius:
     Failų kūrimą (jei failai nebuvo sukurti).
     Duomenų nuskaitymą iš failų.
     Studentų rūšiavimą į dvi grupes.
     Surūšiuotų studentų išvedimą į du naujus failus.
4.Testavimas su skirtingais failų dydžiais
Programos veikimas buvo išmatuotas su penkiais skirtingais failais, turinčiais 1 000, 10 000, 100 000, 1 000 000 ir 10 000 000 įrašų.
   
### 5. **Konteinerių palyginimas
     std::vector
     std::list
     std::deque
     

Naudojimo instrukcija:

1.Programos paleidimas:
   Programos paleidimas: Atsisiųskite arba kopijokite šį projektą iš GitHub. Pasirinkite failą main.cpp ir sukompiliuokite jį naudodami savo pasirinktas C++ kompiiliatorius.

2. Atsitiktinių studentų duomenų generavimas: Programa automatiškai sugeneruos penkis failus su studentų duomenimis, kuriuose bus nurodyta studentų vardai, pavardės, namų darbų rezultatai ir egzamino balai.
   

3.Duomenų nuskaitymas ir rūšiavimas:
Po failų sugeneravimo, programa nuskaito šiuos failus ir rūšiuoja studentus į dvi grupes pagal galutinį balą.
Surūšiuoti studentai bus išvedami į du naujus failus: `kietiakiai.txt` ir `vargsiukai.txt`.

4. Greitųjų testų vykdymas:
   - Programos veikimo greitis bus išmatuotas ir pateiktas konsolėje, kad matytumėte laiką, praleistą skirtinguose etapuose:
     Failų kūrimas
     Duomenų nuskaitymas
     Studentų rūšiavimas
     Surūšiuotų studentų išvedimas į failus

5. Konteinerių palyginimas:
   Išbandysime programą su trimis skirtingais konteineriais: `std::vector`, `std::list` ir `std::deque`. Norėdami išbandyti kitą konteinerį, tiesiog pakeiskite konteinerio tipą faile `main.cpp`.
