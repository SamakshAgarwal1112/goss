#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    std::cout << "Enter file name\n";
    string filename;
    std::cin >> filename;
    ifstream myfile(filename);
    if(myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            cout << line << "\n";
        }
        myfile.close();
    } else {
        cout << "Unable to open file " << filename << ". Invalid file.\n";
    }
    return 0;
}