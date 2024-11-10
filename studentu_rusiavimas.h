#ifndef STUDENTU_RUSIAVIMAS_H_INCLUDED
#define STUDENTU_RUSIAVIMAS_H_INCLUDED
#include "mylib.h"

template <typename Container>
void rusiuotiStudentus1(const std::string& inputFailas, const std::string& vargsiukaiFailas, const std::string& kietiakiaiFailas) {
    auto start = std::chrono::high_resolution_clock::now();

    // Nuskaitymas
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

    // Rūšiavimas į du konteinerius
    start = std::chrono::high_resolution_clock::now();
    Container vargsiukai, kietiakiai;

    std::partition_copy(grupe.begin(), grupe.end(), std::back_inserter(vargsiukai), std::back_inserter(kietiakiai),
                        [](const studentas& stud) { return stud.galutinisBalas() < 5.0; });

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Rūsiavimas uztruko: " << duration.count() << " ms" << std::endl;

    // Įrašymas į failus
    std::ofstream fout_vargsiukai(vargsiukaiFailas);
    std::ofstream fout_kietiakiai(kietiakiaiFailas);

    for (const auto& stud : vargsiukai) {
        fout_vargsiukai << stud.vard_() << " " << stud.pav_() << " " << stud.galutinisBalas() << std::endl;
    }
    for (const auto& stud : kietiakiai) {
        fout_kietiakiai << stud.vard_() << " " << stud.pav_() << " " << stud.galutinisBalas() << std::endl;
    }

    fout_vargsiukai.close();
    fout_kietiakiai.close();
}


#endif // STUDENTU_RUSIAVIMAS_H_INCLUDED
