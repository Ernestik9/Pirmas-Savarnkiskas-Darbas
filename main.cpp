#include "mylib.h"
#include "studentu_generavimas.h"
#include "studentu_rusiavimas.h"

int main() {
    int kiekiai[] = {100000, 1000000, 10000000};
    std::string failuPavadinimai[] = {

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


        std::cout << "Testavimas su std::vector:\n";
        rusiuotiStudentus<std::vector<studentas>>(failuPavadinimai[i], "vargsiukai_vector.txt", "kietiakiai_vector.txt");


        std::cout << "Testavimas su std::list:\n";
        rusiuotiStudentus<std::list<studentas>>(failuPavadinimai[i], "vargsiukai_list.txt", "kietiakiai_list.txt");


        std::cout << "Testavimas su std::deque:\n";
        rusiuotiStudentus<std::deque<studentas>>(failuPavadinimai[i], "vargsiukai_deque.txt", "kietiakiai_deque.txt");
    }

    return 0;
}
