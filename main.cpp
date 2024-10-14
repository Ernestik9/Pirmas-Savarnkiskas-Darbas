#include <iostream>
#include <chrono>
#include "studentu_generavimas.h"
#include "studentu_rusiavimas.h"

int main() {
   
    auto start = std::chrono::high_resolution_clock::now();
    
    generuotiStudentus(1000, "studentai1000.txt");
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "Failų generavimo laikas: " << duration.count() << " ms" << endl;


    start = std::chrono::high_resolution_clock::now();

    rusiuotiStudentus("studentai1000.txt", "vargsiukai.txt", "kietiakiai.txt");

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "Rūšiavimo ir įrašymo į failus laikas: " << duration.count() << " ms" << endl;

    return 0;
}
