#include <fstream>
#include <iostream>
#include <string>
#include <TH2F.h>

using namespace std;

void EPOS2() {
    ifstream file("particle_data.dat");

    if (!file.is_open()) {
        cout << "Cannot open particle_data.dat\n";
        return;
    }

    TH2F *hist = new TH2F(
        "hist",
        "Particles vs Event;phi;Number of particles",
        100, 0.5, 100.5,
        400, 100, 500
    );

    string eventWord, particlesWord, etaWord, phiWord;
    int event, particle no.;
    float eta, phi;

    for (int i = 0; i < 100; i++) {
        file >> eventWord >> event
             >> particlesWord >> particles no.
             >> etaWord >> eta
             >> phiWord >> phi;
if (phi > 1.8 && phi < 4.4) {
            hist->Fill(phi, particle no.);
        }
    }

    cout << "Histogram entries: " << hist->GetEntries() << endl;

    hist->SetMarkerStyle(2);
    hist->SetMarkerColor(kBlue);
    hist->Fit("gaus");
    hist->Draw("COLZ");
}
