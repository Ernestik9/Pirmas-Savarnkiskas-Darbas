#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "MyLib.h"

struct Stud {
    std::string vardas, pavarde;
    std::vector<double> ND;
    double egz, rez;
};

void ived(Stud &Lok);
void output(const Stud &Lok, bool naudotiMediana);
void val(Stud &Lok);
void skaiciuotiGalutini(Stud &Lok, bool naudotiMediana);
double skaiciuotiVidurki(const std::vector<double>& ND);
double skaiciuotiMediana(const std::vector<double>& ND);
void generuotiBalus(Stud &Lok, bool atsitiktiniai = false);
void nuskaitytiIrasusIsFailo(const std::string& failas, std::vector<Stud>& Vec1);


#endif // STUD_H_INCLUDED

