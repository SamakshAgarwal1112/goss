#ifndef KMP_H
#define KMP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KMP {
private:
    int m;
    string pattern;
    vector<int> piTable;
public:
    KMP(string patternText) {
        pattern = patternText;
        m = pattern.size();
        piTable.resize(m, 0);
    }
    void fillPiTable(){
        for(int i = 1, j = 0 ; i < m ; i++) {
            while(j > 0 && pattern[j] != pattern[i]) j = piTable[j-1];

            if(pattern[i] == pattern[j]) j++;

            piTable[i] = j;
        }
    }
    int getIndex(string text) {
        int n = text.size();
        for(int i = 0, j = 0; i < n; i++){
            while(j > 0 && text[i] != pattern[j]) j = piTable[j-1];

            if(text[i] == pattern[j]) j++;

            if(j == m) return i - m + 1;
        }
        return -1;
    }
};

#endif