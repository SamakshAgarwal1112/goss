#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string filename;

int main(int argc, char* argv[]){

    if(argc > 2) {
        cout << "Expected 1 argument, got " << argc - 1 << " arguments.\n";
        return 0;
    }
    else if(argc == 2) {
        filename = argv[1];
    }
    else {
        std::cout << "Enter file name\n";
        getline(std::cin, filename);
    }

    ifstream myfile(filename);
    if(myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            std::cout << line << "\n";
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file " << filename << ".\n";
    }
    return 0;
}