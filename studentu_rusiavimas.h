#ifndef STUDENTU_RUSIAVIMAS_H_INCLUDED
#define STUDENTU_RUSIAVIMAS_H_INCLUDED

#include "mylib.h"


struct studentas {
    std::string vardas, pavarde;
    std::vector<int> paz;
    int egz;

    double galutinisBalas() const;
    std::string vard_() const;
    std::string pav_() const;
};

template <typename Container>
void rusiuotiStudentus(const std::string& inputFailas, const std::string& vargsiukaiFailas, const std::string& kietiakiaiFailas) {
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
    std::cout << "Duomenu nuskaitymas uztruko: " << duration.count() << " ms" << std::endl;


    start = std::chrono::high_resolution_clock::now();


    auto partitionPoint = std::partition(grupe.begin(), grupe.end(), [](const studentas& s) {
        return s.galutinisBalas() < 5.0;
    });

    std::ofstream fout_vargsiukai(vargsiukaiFailas);
    std::ofstream fout_kietiakiai(kietiakiaiFailas);
    if (!fout_vargsiukai || !fout_kietiakiai) {
        std::cout << "Nepavyko atidaryti failu!" << std::endl;
        return;
    }


    for (auto it = grupe.begin(); it != partitionPoint; ++it) {
        fout_vargsiukai << it->vard_() << " " << it->pav_() << " " << it->galutinisBalas() << std::endl;
    }


    for (auto it = partitionPoint; it != grupe.end(); ++it) {
        fout_kietiakiai << it->vard_() << " " << it->pav_() << " " << it->galutinisBalas() << std::endl;
    }

    fout_vargsiukai.close();
    fout_kietiakiai.close();

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Rusiavimas ir isvedimas uztruko: " << duration.count() << " ms" << std::endl;
}

#endif // STUDENTU_RUSIAVIMAS_H_INCLUDED
