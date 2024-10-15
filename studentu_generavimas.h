#include "myLib.h"
#include <fstream>
#include <random>

void generuotiStudentus(int kiekis, const string& failoPavadinimas) {
    ofstream fout(failoPavadinimas);
    if (!fout) {
        cout << "Nepavyko sukurti failo!" << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> pazymiai(1, 10);
    uniform_int_distribution<> egzaminas(1, 10);

    for (int i = 1; i <= kiekis; ++i) {
        fout << "Vardas" << i << " Pavarde" << i << " ";
        for (int j = 0; j < 5; ++j) {
            fout << pazymiai(gen) << " ";
        }
        fout << egzaminas(gen) << endl;
    }
    fout.close();
}
