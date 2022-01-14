# sisteminis 

Sisteminis - taikomoji programa, kuri apskaičiuoja studentų galutinius pažymius bei padalina juos į dvi grupes pagal gautą pažymį.

## Naudojimas
Pasirinkite norimą konteinerio tipą bei jam pritaikytą rušiavimo algoritmą.
```cpp
// vector/deque
    std::vector<Student> students, students_good, students_bad;
    // std::deque<Student> students, students_good, students_bad;
    /* code... */
    std::sort(students_good.begin(), students_good.end()); 
    std::sort(students_bad.begin(), students_bad.end()); 
// list
    // std::list<Student> students, students_good, students_bad;
    /* code... */
    // students_good.sort(); 
    // students_bad.sort();
```
Jeigu neturite duomenų failo galite jį sukurti naudodamiesi pateikta funkcija.
```cpp
    // bus sukurtas 1000 įrašų dydžio failas. Jeigu failas egzistuoja jis bus pakeistas į naujai sugeneruotą.
    hf::generateSampleFile(1000, "./input.txt");
```
Pasirinkite failą iš kurio bus nuskaitomi duomenys į duotą masyvą
```cpp
    hf::populateFromFile(students, "./input.txt");
    //jeigu planuojate naudotis studentų dalinimą hf::deletionPartition metodu
    //hf::populateFromFile(students_good, "./input.txt"); 
```
Pasirinkite dalinimo algoritmą
```cpp
    hf::memoryPartition(students, students_good, students_bad);
    //hf::optimizedPartition(students, students_good, students_bad);
    //hf::deletionPartition(students_good, students_bad);
```
Nurodykite kur įrašyti gautus rezultatus
```cpp
    std::ofstream os_good("./good_students.txt");
    std::ofstream os_bad("./bad_students.txt");
```

## Programos paleidimas Windows10 aplinkoje

Jeigu neturite atsisiųskite naujausia versiją Mingw-w64 naudodami [MSYS2](https://www.msys2.org/)
. Tada "Windows" aplinkos kintamuosiuose pridėkite kelią ("PATH") iki šios programos.

```bash
# Pasitikrinkite ar viską atlikote teisingai
g++ --version
gdb --version
```
Programos paleidimas
```bash
# sukompiliuokite programą naudodami g++ būdami 'root' direktorijoje
g++ *.cpp -o Sisteminis
# paleiskite programą
./Sisteminis
```
