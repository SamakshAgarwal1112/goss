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
        piTable.resize(m+1, 0);
    }
    void fillPiTable(){
        pattern = ' ' + pattern;
        int j = 0;
        for(int i = 2 ; i <=m ; i++) {
            while(j<=m && pattern[j+1] == pattern[i]) piTable[i++] = ++j;
            j = 0;
        }
    }
    int getIndex(string text) {
        int j = 0, n = text.size();
        for(int i=0; i<n; i++){
            if(pattern[j+1] != text[i]) {
                while (j!=0 && pattern[j+1] != text[i]) {
                    j = piTable[j];
                }
            }
            j++;
            if(j==m) return i - m + 1;
        }
        return -1;
    }
};

#endif