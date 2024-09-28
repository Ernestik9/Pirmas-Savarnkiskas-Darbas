#include "MyLib.h"
#include "Stud.h"

int main() {
    vector<Stud> Vec1;
    Stud Temp;
    cout << "Kiek studentu yra? ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Iveskite studento duomenis: " << endl;
        ived(Temp);
        Vec1.push_back(Temp);
        val(Temp);
    }

    char pasirinkimas;
    cout << "Skaičiuoti pagal medianą (m) ar vidurkį (v)? ";
    cin >> pasirinkimas;

    bool naudotiMediana = (pasirinkimas == 'm');

    cout << setw(15) << left << "Pavarde"
         << setw(15) << left << "Vardas"
         << setw(20) << left << (naudotiMediana ? "Galutinis (Med.)" : "Galutinis (Vid.)") << endl;
    cout << "----------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        skaiciuotiGalutini(Vec1.at(i), naudotiMediana);
        output(Vec1.at(i));
    }

    system("pause");
    return 0;
}
