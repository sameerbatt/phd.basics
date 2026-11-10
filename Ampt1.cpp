//Studying the pt and pz of AMPT data.
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void Ampt1(){
  ifstream infile("ampt_file.dat");
  if (!infile.is_open()) {
    cout << "Error opening file: ampt_file.dat" << endl;
    return;
  }
ofstream outfile("Ampt_output1");
if (!outfile.is_open()) {
    cout << "Error opening output file: Ampt_output1" << endl;
  }

int event, test, np, id;
int npart1, npart2, npart1_el, npart1_inel;
int npart2_el, npart2_inel;
float b, px, py, pz, m, x, y, z, t, pt;
while  (infile >> event >> test >> np >> b >> npart1 >> npart2 >> npart1_el >> npart1_inel >> npart2_el >> npart2_inel)
{ int i = 1;
    while (i <= np)
    {
        infile >> id >> px >> py >> pz >> m >> x >> y >> z >> t;
        if (id!=22)
        {
            pt = sqrt(px*px + py*py);
        outfile << left << setw(10) <<event <<setw(10) << id <<  right << setw(10) << pt << setw(10) << pz <<endl;
        }
        i++;
    }
}
infile.close();
outfile.close();
cout << "DAT file created successfully." << endl;
}


