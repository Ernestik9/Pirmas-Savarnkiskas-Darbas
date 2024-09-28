#include "Stud.h"
#include <iomanip>

void ived(Stud &Lok) {
    cout << "Iveskite Varda, Pavarde ir Egzamino ivertinima: ";
    cin >> Lok.vardas >> Lok.pavarde >> Lok.egz;

    cout << "Iveskite namu darbu pazymius (iveskite -1 norint uzbaigti): ";
    double pazymys;
    while (true) {
        cin >> pazymys;
        if (pazymys == -1) break;
        Lok.ND.push_back(pazymys);
    }
}

void output(Stud &Lok) {
    cout << setw(15) << left << Lok.pavarde
         << setw(15) << left << Lok.vardas
         << setw(20) << left << setprecision(2) << std::fixed << Lok.rez << endl;
}

void val(Stud &Lok) {
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.ND.clear();
}

double skaiciuotiMediana(const vector<double>& ND) {
    vector<double> temp = ND;
    sort(temp.begin(), temp.end());
    if (temp.size() % 2 == 0) {
        return (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2.0;
    } else {
        return temp[temp.size() / 2];
    }
}

double skaiciuotiVidurki(const vector<double>& ND) {
    double suma = accumulate(ND.begin(), ND.end(), 0.0);
    return suma / ND.size();
}

void skaiciuotiGalutini(Stud &Lok, bool naudotiMediana) {
    if (naudotiMediana) {
        Lok.rez = 0.4 * skaiciuotiMediana(Lok.ND) + 0.6 * Lok.egz;
    } else {
        Lok.rez = 0.4 * skaiciuotiVidurki(Lok.ND) + 0.6 * Lok.egz;
    }
}
