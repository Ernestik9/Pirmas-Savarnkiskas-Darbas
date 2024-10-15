#include "mylib.h"

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

        auto start = std::chrono::high_resolution_clock::now();


        generuotiStudentus(kiekiai[i], failuPavadinimai[i]);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Failas " << failuPavadinimai[i] << " sugeneruotas per: " << duration.count() << " ms" << std::endl;


        start = std::chrono::high_resolution_clock::now();
        rusiuotiStudentus(failuPavadinimai[i], "vargsiukai.txt", "kietiakiai.txt");
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Rūšiavimas ir išvedimas į failus užtruko: " << duration.count() << " ms" << std::endl;
    }

    return 0;
}
