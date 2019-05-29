## Įdiegimo instrukcija
1. Clone'inam repositoriją ```$ git clone https://github.com/gitguuddd/Obj_Duomenu_apdorojimas.git```
2. Compile'inam programą paleisdami CMakeLists.txt failą
3. Norint nuskaityti informaciją nuo failo reikia sukurti kursiokai.txt failą su tokia struktūra 
```shell
Pavarde     Vardas      ND1  ND2  ND3  ND4  ND5  ND6  ND7  ND8  Egzaminas
Pavarde1    Vardas1     10   9    4    6    4    5    0    4    7
Pavarde2    Vardas2     10   0    6    7    9    4    2    5    3
Pavarde3    Vardas3     10   0    3    b    5    2    1    4    5
```
- Paleidžiame programą
---
## Naudojimosi instrukcija
- Paleidųs programą programa paklaus vartotojo kokiu režimu jis nori vykdyti programą: išsamiu ar konkrečiu
- Išsamus režimas pasižymi labai didele pasirinkimo galimybe - kiekvienam generuojamam  studentu failui galima priskirti skirtingą skaičių namų darbų, galutinio pažymio skaičiavimo būdą. Šis režimas yra apkrautas vartotojo įvestimi
- Konkretus režimas kiek galima labiau sumažina vartotojo įvesčių kiekį - generuojant failus reikia tik vieną kartą įvesti namų darbų skaičių ir galutinio pažymio skaičiavimo būdą
- Paleidųs programą ir pasirinkųs režimą bus matomas toks vaizdas
```shell
Saugomi 0 studentu(o) duomenys, pasirinkite ka daryti toliau:
1. Ivesti studenta paciam
2. Generuoti studenta
3. Skaityti is failo
4. Atspausdinti (galutinis pagal nd mediana)
5. Atspausdinti (galutinis pagal nd vidurki)
6. Generuoti studentu faila (v1.0)
7. Skelti studentus i maladec ir L-laivo sarasus, atspausdinti
```
- Pasirinkite norimą funkciją ivesdami jos numerį. Input'ai apsaugoti tai galima ir pasiaust :D
- Po 1, 2 arba 3 funkcijos įvykdomo programa grįžta į meniu, atnaujinamas saugomų studentų rodiklio skaičius
- 4, 5, 7 funkcijos neveiks, jei nebus saugomi bent vieno studento duomenys
- Po 4, 5, 6 arba 7 funkcijos įvykdymo programa baigia darbą
---

## Programa pritaikyta mano sukurto vektoriaus testavimui (grow(), push_back int benchmarkams), dėl nesuderinamumo padaryti šie pakeitimai:
- Sudubliuotos template'inės funkcijos ,nes mano allocator nėra template argumentas
- užkomentuotos išspaudinimo į ekraną funkcijos
- užkomentuota papildomos užduoties algoritmų realizacija naudojant vector

---
## Programos struktūra
- ```Input.h``` ir ```Input.cpp``` funkcijos/kintamieji/include'ai susyję su duomenų įvedimu
- ```Output.h```ir ```Output.cpp``` funkcijos/kintamieji/include'ai susyję su duomenų išvedimu
- ```Mutual.h```ir ```Mutual.cpp``` funkcijos/kintamieji/include'ai bendri visai programai (```#include iostream```,```handleinput()``` )
- ```main.cpp``` pagrindinis failas - meniu
