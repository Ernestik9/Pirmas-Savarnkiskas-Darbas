#ifndef STUDENTU_RUSIAVIMAS_H_INCLUDED
#define STUDENTU_RUSIAVIMAS_H_INCLUDED
#include "mylib.h"


struct studentas {
    std::string vardas, pavarde;
    std::vector<int> paz;
    int egz;

    double galutinisBalas() const {
        double pazymiuVidurkis = std::accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
        return 0.4 * pazymiuVidurkis + 0.6 * egz;
    }

    std::string vard_() const { return vardas; }
    std::string pav_() const { return pavarde; }
};

template <typename Container>
void rusiuotiStudentusStrategija1(const std::string& inputFailas, const std::string& vargsiukaiFailas, const std::string& kietiakiaiFailas) {
    auto start = std::chrono::high_resolution_clock::now();


    std::ifstream fin(inputFailas);
    if (!fin) {
        std::cout << "Nepavyko atidaryti failo!" << std::endl;
        return;
    }

    Container grupe;
    studentas s;
    while (fin >> s.vardas >> s.pavarde) {
        s.paz.resize(5);
        for (int& paz : s.paz) fin >> paz;
        fin >> s.egz;
        grupe.push_back(s);
    }
    fin.close();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Duomenų nuskaitymas užtruko: " << duration.count() << " ms" << std::endl;


    start = std::chrono::high_resolution_clock::now();
    Container vargsiukai, kietiakiai;
    for (const auto& stud : grupe) {
        double galutinis = stud.galutinisBalas();
        if (galutinis < 5.0) {
            vargsiukai.push_back(stud);
        } else {
            kietiakiai.push_back(stud);
        }
    }

    std::ofstream fout_vargsiukai(vargsiukaiFailas);
    std::ofstream fout_kietiakiai(kietiakiaiFailas);
    if (!fout_vargsiukai || !fout_kietiakiai) {
        std::cout << "Nepavyko atidaryti failų!" << std::endl;
        return;
    }

    for (const auto& stud : vargsiukai) {
        fout_vargsiukai << stud.vard_() << " " << stud.pav_() << " " << stud.galutinisBalas() << std::endl;
    }

    for (const auto& stud : kietiakiai) {
        fout_kietiakiai << stud.vard_() << " " << stud.pav_() << " " << stud.galutinisBalas() << std::endl;
    }

    fout_vargsiukai.close();
    fout_kietiakiai.close();

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Rūšiavimas ir išvedimas užtruko: " << duration.count() << " ms" << std::endl;
}


template <typename Container>
void rusiuotiStudentusStrategija2(const std::string& inputFailas, const std::string& vargsiukaiFailas) {
    auto start = std::chrono::high_resolution_clock::now();

 
    std::ifstream fin(inputFailas);
    if (!fin) {
        std::cout << "Nepavyko atidaryti failo!" << std::endl;
        return;
    }

    Container grupe;
    studentas s;
    while (fin >> s.vardas >> s.pavarde) {
        s.paz.resize(5);
        for (int& paz : s.paz) fin >> paz;
        fin >> s.egz;
        grupe.push_back(s);
    }
    fin.close();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Duomenų nuskaitymas užtruko: " << duration.count() << " ms" << std::endl;


    start = std::chrono::high_resolution_clock::now();
    Container vargsiukai;
    grupe.erase(std::remove_if(grupe.begin(), grupe.end(), [&vargsiukai](const studentas& stud) {
        if (stud.galutinisBalas() < 5.0) {
            vargsiukai.push_back(stud);
            return true;
        }
        return false;
    }), grupe.end());

    std::ofstream fout_vargsiukai(vargsiukaiFailas);
    if (!fout_vargsiukai) {
        std::cout << "Nepavyko atidaryti failo!" << std::endl;
        return;
    }

    for (const auto& stud : vargsiukai) {
        fout_vargsiukai << stud.vard_() << " " << stud.pav_() << " " << stud.galutinisBalas() << std::endl;
    }

    fout_vargsiukai.close();

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Rūšiavimas ir išvedimas užtruko: " << duration.count() << " ms" << std::endl;
}

#endif // STUDENTU_RUSIAVIMAS_H_INCLUDED
