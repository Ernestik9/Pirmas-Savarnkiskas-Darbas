#include "mylib.h"
#include <iostream>
#include "studentu_generavimas.h"
#include "studentu_rusiavimas.h"

int main() {
    int kiekiai[] = {1000, 10000, 100000, 1000000, 10000000};
    std::string failuPavadinimai[] = {
        "studentai1000.txt",
        "studentai10000.txt",
        "studentai100000.txt",
        "studentai1000000.txt",
        "studentai10000000.txt"
    };

    for (int i = 0; i < 5; ++i) {
        std::cout << "Rusiuoti studentus std::vector:\n";
        rusiuotiStudentus1<std::vector<studentas>>(failuPavadinimai[i], "vargsiukai_vector.txt", "kietiakiai_vector.txt");

    }

    return 0;
}
