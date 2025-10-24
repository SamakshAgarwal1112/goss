#ifndef BM_H
#define BM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BM {
private:
    int m;
    string pattern;
    vector<int> badchar;
public:
    BM(string patternText) {
        pattern = patternText;
        m = patternText.size();
        badchar.resize(256, -1);
    }

    void precompute() {
        if(m == 0) return;

        for(int i = 0; i < m; i++) badchar[(int)pattern[i]] = i;
    }

    int getIndex(string text) {
        int n = text.size();
        if(n == 0) return -1;

        int k = 0;
        while(k <= (n - m)){
            int j = m - 1;

            while(j >= 0 && pattern[j] == text[j + k]) j--;

            if(j < 0) return k;
            // k += (k + m < n) ? m - badchar[text[k + m]] : 1;
            else {
                k += max(1, j - badchar[(unsigned char)text[k + j]]);
            }
        }

        return -1;
    }
};

#endif