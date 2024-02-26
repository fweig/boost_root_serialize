#include "Digi.h"

#include <TFile.h>
#include <TTree.h>
#include <iostream>

// Write Digi to file with ROOT
void WriteDigi() {
    TFile file("digi.root", "RECREATE");
    TTree tree("digi", "Test TTree that stores a single Digi");

    Digi digi{.time = 123, .channel = 456, .charge = 789};
    tree.Branch<Digi>("Digi", &digi);

    tree.Fill();
    file.Print();

    file.Write();
}

// Read Digi from file with ROOT
void ReadDigi() {
    TFile file("digi.root", "READ");

    TTree *tree = nullptr;
    file.GetObject("digi", tree);

    Digi *digi = nullptr;
    tree->SetBranchAddress("Digi", &digi);

    tree->GetEntry(0);

    std::cout << "Digi: time=" << digi->time << ", channel=" << digi->channel << ", charge=" << digi->charge << std::endl;
}

int main() {

    // WriteDigi();
    ReadDigi();

    return 0;
}
