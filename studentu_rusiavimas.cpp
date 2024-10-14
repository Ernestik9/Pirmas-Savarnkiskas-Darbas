#include "Stud.h"
#include <fstream>

double studentas::galutinisBalas() {
    double pazymiuVidurkis = std::accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
    return 0.4 * pazymiuVidurkis + 0.6 * egz;
}

void rusiuotiStudentus(const vector<studentas>& grupe, const std::string& vargsiukaiFailas, const std::string& kietiakiaiFailas) {
    std::ofstream fout_vargsiukai(vargsiukaiFailas);
    std::ofstream fout_kietiakiai(kietiakiaiFailas);

    for (const auto& s : grupe) {
        double galutinis = s.galutinisBalas();
        if (galutinis < 5.0) {
            fout_vargsiukai << s.vard_() << " " << s.pav_() << " " << galutinis << std::endl;
        } else {
            fout_kietiakiai << s.vard_() << " " << s.pav_() << " " << galutinis << std::endl;
        }
    }
    fout_vargsiukai.close();
    fout_kietiakiai.close();
}
