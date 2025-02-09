#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

string s;

void init() {
    cin >> s;
}

long long computeContribution(int index, int digit, const string &s, 
    const vector<long long> &prefixMod3, 
    const vector<long long> &prefixMod9, 
    const vector<long long> &prefixMod7, 
    vector<long long> &freqMod3, 
    vector<long long> &freqMod9, 
    vector<long long> &freqMod7) {
    if (digit == 0) return 0LL;
    if (digit == 1 || digit == 2 || digit == 5) return 1LL + index;
    if (digit == 3 || digit == 6) return 1LL + freqMod3[prefixMod3[index + 1]];
    if (digit == 9) return 1LL + freqMod9[prefixMod9[index + 1]];
    if (digit == 4) return 1LL + (index >= 1 && (s[index] - '0') % 2 == 0) * (index + 1);
    if (digit == 7) return 1LL + freqMod7[prefixMod7[index + 1]];
    if (digit == 8) {
        long long count = 0;
        if (index >= 1 && ((s[index - 1] - '0') * 10 + digit) % 4 == 0) count += index;
        if (digit % 4 == 0) count++;
        return 1LL + count;
    }
    return 1LL;
}

long long countSubstrings(string s) {
    int strLen = s.size();
    vector<long long> prefixMod3(strLen + 1, 0), prefixMod9(strLen + 1, 0), prefixMod7(strLen + 1, 0);
    vector<long long> powerMod7(strLen + 1, 0);
    vector<long long> freqMod3(3, 0), freqMod9(9, 0), freqMod7(7, 0);
    
    powerMod7[0] = 1;

    for (int i = 0; i < strLen; i++) {
        int digit = s[i] - '0';
        prefixMod3[i + 1] = (prefixMod3[i] + digit) % 3;
        prefixMod9[i + 1] = (prefixMod9[i] + digit) % 9;
        prefixMod7[i + 1] = (prefixMod7[i] * 10 + digit) % 7;
        powerMod7[i + 1] = (powerMod7[i] * 10) % 7;
    }

    long long totalCount = 0;

    for (int index = 0; index < strLen; index++) {
        int digit = s[index] - '0';
        totalCount += computeContribution(index, digit, s, prefixMod3, prefixMod9, prefixMod7, freqMod3, freqMod9, freqMod7);
        freqMod3[prefixMod3[index + 1]]++;
        freqMod9[prefixMod9[index + 1]]++;
        freqMod7[prefixMod7[index + 1]]++;
    }

    return totalCount;
}


int main() {
    init();

    cout << countSubstrings(s) << endl;

    return 0;
}

// 3448. Count Substrings Divisible By Last Digit
// Weekly Contest 436: 09/02/2025 - Hard