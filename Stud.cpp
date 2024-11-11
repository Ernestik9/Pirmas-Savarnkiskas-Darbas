#include "Stud.h"
#include "MyLib.h"


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

void output(const Stud &Lok, bool naudotiMediana) {
    cout << setw(15) << left << Lok.pavarde
         << setw(15) << left << Lok.vardas
         << setw(20) << left << setprecision(2) << std::fixed
         << (naudotiMediana ? skaiciuotiMediana(Lok.ND) : skaiciuotiVidurki(Lok.ND)) // Pateikiamas rezultatas pagal medianą arba vidurkį
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

void generuotiBalus(Stud &Lok, bool atsitiktiniai) {
    if (atsitiktiniai) {

        Lok.egz = rand() % 11;
        int ndCount = rand() % 6 + 1;
        Lok.ND.clear();
        for (int i = 0; i < ndCount; ++i) {
            Lok.ND.push_back(rand() % 11);
        }
    }
}

void nuskaitytiIrasusIsFailo(const std::string& failas, std::vector<Stud>& Vec1) {
    std::ifstream file(failas);
    if (!file) {
        throw std::runtime_error("Nepavyko atidaryti failo.");
    }

    Stud Temp;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> Temp.pavarde >> Temp.vardas >> Temp.egz;

        double pazymys;
        while (ss >> pazymys) {
            Temp.ND.push_back(pazymys);
        }

        Vec1.push_back(Temp);
    }
}
