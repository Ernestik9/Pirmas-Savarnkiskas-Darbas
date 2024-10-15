#include "studentu_generavimas.h"
#include "mylib.h"

void generuotiStudentus(int kiekis, const std::string& failoPavadinimas) {
    std::ofstream fout(failoPavadinimas);
    if (!fout) {
        std::cout << "Nepavyko sukurti failo!" << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> pazymiai(1, 10);
    std::uniform_int_distribution<> egzaminas(1, 10);

    for (int i = 1; i <= kiekis; ++i) {
        fout << "Vardas" << i << " Pavarde" << i << " ";
        for (int j = 0; j < 5; ++j) {
            fout << pazymiai(gen) << " ";
        }
        fout << egzaminas(gen) << std::endl;
    }
    fout.close();
}

