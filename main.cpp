#include <iostream>
#include <chrono>
#include "studentu_generavimas.h"
#include "studentu_rusiavimas.h"

int main() {
   
    auto start = chrono::high_resolution_clock::now();
    
    generuotiStudentus(1000, "studentai1000.txt");
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Failų generavimo laikas: " << duration.count() << " ms" << endl;


    start = chrono::high_resolution_clock::now();

    rusiuotiStudentus("studentai1000.txt", "vargsiukai.txt", "kietiakiai.txt");

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Rūšiavimo ir įrašymo į failus laikas: " << duration.count() << " ms" << endl;

    return 0;
}
