#include <iostream>
#include <string>
#include <fstream>
#include "kmp.h"
#include <chrono>
#include <ctime>

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
    auto pi_fill_start = std::chrono::system_clock::now();
    kmp.fillPiTable();
    auto pi_fill_end = std::chrono::system_clock::now();

    std::chrono::duration<double> pi_fill_time = pi_fill_end - pi_fill_start;
    auto pi_fill_time_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(pi_fill_time);
    std::cout << "Pi Table filled in " << pi_fill_time_in_ms.count() << " milliseconds" << endl;

    ifstream myfile(filename);
    int i = 1;
    if(myfile.is_open()) {
        string line;
        auto text_search_start = std::chrono::system_clock::now();
        while (getline(myfile, line)) {
            // std::cout << line << "\n";
            int index = kmp.getIndex(line);
            if(index!=-1) std::cout << "Pattern found at " << index << " at line " << i++ << ".\n";
        }
        auto text_search_end = std::chrono::system_clock::now();

        std::chrono::duration<double> text_search_time = text_search_end - text_search_start;
        auto text_search_time_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(text_search_time);
        std::cout << "Text search filled in " << text_search_time_in_ms.count() << " milliseconds" << endl;

        myfile.close();
    } else {
        std::cout << "Unable to open file " << filename << ".\n";
    }
    return 0;
}