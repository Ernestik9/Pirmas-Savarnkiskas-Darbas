#include "Stud.h"
#include <fstream>

double studentas::galutinisBalas() {
    double pazymiuVidurkis = accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
    return 0.4 * pazymiuVidurkis + 0.6 * egz;
}

void rusiuotiStudentus(const vector<studentas>& grupe, const string& vargsiukaiFailas, const string& kietiakiaiFailas) {
    ofstream fout_vargsiukai(vargsiukaiFailas);
    ofstream fout_kietiakiai(kietiakiaiFailas);

    for (const auto& s : grupe) {
        double galutinis = s.galutinisBalas();
        if (galutinis < 5.0) {
            fout_vargsiukai << s.vard_() << " " << s.pav_() << " " << galutinis << endl;
        } else {
            fout_kietiakiai << s.vard_() << " " << s.pav_() << " " << galutinis << endl;
        }
    }
    fout_vargsiukai.close();
    fout_kietiakiai.close();
}
