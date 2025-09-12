#include <iostream>
#include <string>
#include <fstream>
#include "kmp.h"

using namespace std;

string filename;
string pattern;

int main(int argc, char* argv[]){

    if(argc > 3 || argc < 2) {
        cout << "Expected 2 arguments, got " << argc - 1 << " arguments.\n";
        return 0;
    }
    else if(argc == 3) {
        filename = argv[2];
    }
    else {
        std::cout << "Enter file name\n";
        getline(std::cin, filename);
    }

    pattern = argv[1];
    KMP kmp(pattern);
    kmp.fillPiTable();

    ifstream myfile(filename);
    int i = 1;
    if(myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            std::cout << line << "\n";
            int index = kmp.getIndex(line);
            if(index!=-1) std::cout << "Pattern found at " << index << " at line " << i++ << ".\n";
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file " << filename << ".\n";
    }
    return 0;
}