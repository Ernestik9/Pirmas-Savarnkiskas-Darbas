#include "Stud.h"
#include "MyLib.h"


int main() {
    srand(time(0));

    vector<Stud> Vec1;
    Stud Temp;


    cout << "Ar norite ivesti studentu duomenis (I) ar nuskaityti is failo (F)? ";
    char pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 'I' || pasirinkimas == 'i') {
        cout << "Kiek studentu yra? ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Iveskite studento duomenis: " << endl;
            ived(Temp);
            Vec1.push_back(Temp);
            val(Temp);
        }
    } else if (pasirinkimas == 'F' || pasirinkimas == 'f') {
        try {
            nuskaitytiIrasusIsFailo("kursiokai.txt", Vec1);
        } catch (std::exception& e) {
            cout << "Klaida: " << e.what() << endl;
            return 1;
        }
    }

    char pasirinkimasGalutinio;
    cout << "Skaiciuoti pagal mediana (m) ar vidurki (v)? ";
    cin >> pasirinkimasGalutinio;

    bool naudotiMediana = (pasirinkimasGalutinio == 'm');
    cout << setw(15) << left << "Pavarde"
         << setw(15) << left << "Vardas"
         << setw(20) << left << (naudotiMediana ? "Galutinis (Med.)" : "Galutinis (Vid.)")
         << setw(20) << left << "Galutinis (Vid.)" << endl;
    cout << "----------------------------------------------------------" << endl;


    sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
        return a.pavarde < b.pavarde;
    });

    for (int i = 0; i < Vec1.size(); i++) {
    skaiciuotiGalutini(Vec1.at(i), naudotiMediana);
    output(Vec1.at(i), naudotiMediana);
}

    return 0;
}
