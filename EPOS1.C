#include <iostream>
#include <fstream>
#include "TFile.h"
#include "TTree.h"
#include "TLeaf.h"
#include "TRandom.h"

using namespace std;
void EPOS1()
{
    TFile *Tf = TFile::Open("EPOS.root"); 
    TTree *Tree = (TTree*)Tf->Get("teposevent0");
   
    Long64_t NEntries = Tree->GetEntries();
   
    TLeaf *phirLeaf = Tree->GetLeaf("phir");

    // Create the output file
    ofstream outfile("phi_random.dat");

    Long64_t selected = 0;
    cout << "Total events: " << NEntries << endl;

    
    for (Long64_t i = 0; i < NEntries; ++i)
    {
        
        Tree->GetEntry(i);

        
        float phir = (float)phirLeaf->GetValue();

        if (gRandom->Rndm() < 0.5)
        {           
            outfile <<phir << "\n";
            selected++;
        }
    }
    outfile.close();
    Tf->Close();

    cout << "Selected events: " << selected << endl;
    cout << "Data saved to phi_random.dat" << endl;
}
