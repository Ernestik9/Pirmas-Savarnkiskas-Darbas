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
        std::cout << "Apdorojama failą: " << failuPavadinimai[i] << " (" << kiekiai[i] << " studentų)" << std::endl;


        std::cout << "Strategija 1 su std::vector:\n";
        rusiuotiStudentusStrategija1<std::vector<studentas>>(failuPavadinimai[i], "vargsiukai_vector1.txt", "kietiakiai_vector1.txt");


        std::cout << "Strategija 1 su std::list:\n";
        rusiuotiStudentusStrategija1<std::list<studentas>>(failuPavadinimai[i], "vargsiukai_list1.txt", "kietiakiai_list1.txt");

        std::cout << "Strategija 1 su std::deque:\n";
        rusiuotiStudentusStrategija1<std::deque<studentas>>(failuPavadinimai[i], "vargsiukai_deque1.txt", "kietiakiai_deque1.txt");

        std::cout << "Strategija 2 su std::vector:\n";
        rusiuotiStudentusStrategija2<std::vector<studentas>>(failuPavadinimai[i], "vargsiukai_vector2.txt");

 
        std::cout << "Strategija 2 su std::list:\n";
        rusiuotiStudentusStrategija2<std::list<studentas>>(failuPavadinimai[i], "vargsiukai_list2.txt");


        std::cout << "Strategija 2 su std::deque:\n";
        rusiuotiStudentusStrategija2<std::deque<studentas>>(failuPavadinimai[i], "vargsiukai_deque2.txt");

        std::cout << "-------------------------------------------------------\n";
    }

    return 0;
}
