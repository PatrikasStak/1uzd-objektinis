- "padarytas base modelis" - parašyta paprasta programa su masyvais ir statine atmintimi, visi duomenys suvedami, rezultatas skaičiuojamas tik su vidurkiu
- "prideta medianos funkcija" - rezultatas gali buti skaiciuojamas su mediana
- "skaitymas nezinant skaiciu, be vektoriu ir atskiru failu" - pakeista skaitymo funkcija kad skaitytu duomenis nezinant kiek ju bus, viskas dar vyksta viename faile ir tik su masyvais
- "padaryta dinamine atmintis masyvams" - pakeiciau koda kad masyvai butu dinaminiai o ne statiniai
- "bug fixai + pagrazinimas" - masyvu failo rezultate pridetas suskirstymas(Vardas, pavarde, galutinis) islygintas su setw. Padariau kad butu negalima irasyti nesakiciu, kai vedami namu darbu pazymiai ir egzaminu rezultatai.
- "pridetas main_vector.cpp" - pridetas failas veikiantis su vektoriais vietoj masyvu
- "išskaidytas kodas į .h ir .cpp failus" - main.cpp ir main_vector.cpp isskaidziau i lib.h func(m/v).cpp ir func(m/v).h (m- masyvai v- vektoriai), dar pridejau sort funkcija medianos funkcijose
- "prideta random funkcija" - pridetas pasirinkimas generuoti nd ir egz pazymius studentui ivedus "r" vietoj pazymio
- "bug fix: zsh: trace trap  ./main" - sutaisytas bugas kur main.cpp ivedus trecio studento varda gaunamas erroras zsh: trace trap  ./main
- "bug fixai" - padariau kad random galima generauoti tik kai rasomas pirmas pazymys. Buvo bug'as kai yra pasirinkimas mediana ar vidurkis paspaudus enter nieko nevyko, dabar defaultina i vidurki. 
- "padarytas menu + bug fixai" - padaryta menu kur pasirenkamas duomenu ivedimas ir darbo baigimas, pataisytas kodas kad butu butina ivesti nors 1 pazymi. Dar prideta galimybe generuoti ir vardus.
-- v0.2
- "prideta fill_n funkcija" - vietoj to, kad bruksnius rezultate printintu per loopa, panaudota fill_n funkcija
- "studentu generavimo fix" - parinktis generuoti visus studentu duomenis (3) pakeista, kad butu galima pasirinkti kiek studentu norima sugeneruoti
- "preliminari failo skaitymo funkcija" - galimas skaitymas is kursiokai.txt
- "dinaminis nd kiekis" - dabar skaitoma ne butinai 15 nd failai, programa issiaiskina kiek nd tures studentai is pagal pirma eilute
- "pridetos rikiavimo funkcijos" - galima rikiuoti pagal varda, pavarde, galutinius rezultatus, dar prideta funkcija kuri i struct sudeda galutinius rezultatus
------------
Laikai - 10000 - 0.0724s; 100000 - 0.5376s; 1000000 - 2.88213s
------------
- "pridetas rasymas i faila" - galima pasirinkti rezultatus rasyti i rez.txt, terminala arba abu
- "pataisyta system isvestis renkantis failus" - neberodoma rez.txt
- "panaikinti masyvu failai" - panaikinau failus kurie dirba su masyvais kadangi dabar naudojami tik failai su vektoriais
- "pervardinti failai" - failai pervardinti i trumpesnius pavadinimus
- "failo pasirinkimo error pataisymas" - anksčiau kai būdavo įvestas neteisingas failas, programa sustodavo, dabar leidžia įvesti vėl
- "catch pataisymai" - dabar catch gaudo specifinius errorus vietoj ... ir išveda žinute kai sugauna errora
- "egzamino pazymio tikrinimas" - tikrinama ar egzamino pazymis yra 0-10
- "namu darbu pazymio tikrinimas" - tikrinama ar namu darbu pazymis yra 0-10
- "try catch atidarant faila" - errorai gaunami atidarant faila dabar dorojami su catch
- "rasymo lambdos" - padarytos headerio ir likusio failo rasymo lambdos
- "veikiantis failu generavimas" - padaryta failu generavimo funkcija
- "pridetas vatch prie ND ivedimo" - renkantis ND skaiciu failu generavime nebegalima padaryti neteisingos ivesties
- "padaryta GeneruotuRusiavimas funkcija" - funkcija gali perkirsti faila i 2 failus
- "rusiavimas galimas is terminalo" - GeneruotuRusivimas callinamas main
- "surusioti failai rodo gal. rezultatus" - maladiec.txt ir vargsai.txt rodo galutinius rezultatus
- "final versija pries testavima" - yra rusiavimas
- "1 testavimas" - matuojamas laikas 1 testavimui
- "testavimai prideti" - abu testavimai yra
- "pridetas rusiavimo pasirinkimas" - is generuotu failu galima rusiuoti irasus pagal varda, pavarde ir galutinius rezultatus
v0.4 laikai su 5 ND: 1000 - 0.0083      10000 - 0.0418      100000 - 0.2258     1000000 - 2.1877       10000000 - 21.4033   visi 23.867
1k  - nuskaitytas(0.00260862s) isrikiuotas(0.00305742s) isskirstytas(0.00118667s) maladiec isvesti(0.00508504s) vargsai isvesti(0.00288596s) visi rikiavimai(0.0174237s)
10k - nuskaitytas(0.0122946s)  isrikiuotas(0.027299s)   isskirstytas(0.00503313s) maladiec isvesti(0.0214935s) vargsai isvesti(0.0132335s) visi rikiavimai(0.0685688s)
100k- nuskaitytas(0.0674996s)  isrikiuotas(0.144965s)   isskirstytas(0.0221816s) maladiec isvesti(0.14138s)  vargsai isvesti(0.0945567s) visi rikiavimai(0.41721s)
1m  - nuskaitytas(0.480759s)   isrikiuotas(1.31925s)    isskirstytas(0.234185s) maladiec isvesti(1.4084s)   vargsai isvesti(1.0077s)  visi rikiavimai(3.98002s)
10m - nuskaitytas(4.58091s)    isrikiuotas(15.3626s)    isskirstytas(3.53852s) maladiec isvesti(15.0625s)  vargsai isvesti(10.1604s) visi rikiavimai(44.1762s)
  <img width="624" height="119" alt="image" src="https://github.com/user-attachments/assets/ba2c4947-be74-4a2d-a7f7-18b27c404106" />
<img width="1068" height="720" alt="image" src="https://github.com/user-attachments/assets/22719650-be0b-4c0e-bdac-9ad62378d845" />


