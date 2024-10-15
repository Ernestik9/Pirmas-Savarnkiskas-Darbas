#include "mylib.h"
struct studentas {
    std::string vardas, pavarde;
    std::vector<int> paz;
    int egz;

    double galutinisBalas() const;
    std::string vard_() const { return vardas; }
    std::string pav_() const { return pavarde; }
};

void rusiuotiStudentus(const std::string& inputFailas, const std::string& vargsiukaiFailas, const std::string& kietiakiaiFailas);
