#include "MyLib.h"
#include "Stud.h"
#include "studentu_generavimas.cpp"
#include "studentu_rusiavimas.cpp"

int main() {


    generuotiStudentus(1000, "studentai1000.txt");
    generuotiStudentus(10000, "studentai10000.txt");

    vector<studentas> grupe;

    rusiuotiStudentus(grupe, "vargsiukai.txt", "kietiakiai.txt");

 
    
    return 0;
}
