#include "studentu_rusiavimas.h"

double studentas::galutinisBalas() const {
    double pazymiuVidurkis = std::accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
    return 0.4 * pazymiuVidurkis + 0.6 * egz;
}

std::string studentas::vard_() const { return vardas; }
std::string studentas::pav_() const { return pavarde; }
