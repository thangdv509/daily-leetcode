#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string s1, s2;

void init() {
    cin >> s1 >> s2;
}


bool areAlmostEqual(string s1, string s2) {
    int n = s1.size();
    vector<int> count(26, 0);
    int countDif = 0;

    for(int i = 0; i < n; ++i) {
        if(s1[i] != s2[i]) {
            count[s1[i] - 'a'] ++;
            count[s2[i] - 'a'] --;
            countDif++;
        }
    }

    if(countDif > 2) return false;
        
    for(int num : count) {
        if(num != 0) return false;
    }

    return true;
}


int main() {
    init();

    cout << areAlmostEqual(s1, s2) << endl;

    return 0;
}

// 1790. Check if One String Swap Can Make Strings Equal
// Daily question: 05/02/2025 - Easy