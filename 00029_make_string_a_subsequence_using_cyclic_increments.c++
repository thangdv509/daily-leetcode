#include<iostream>
#include<string>
using namespace std;

string str1, str2;

void init() {
    cin >> str1 >> str2; 
}

bool canMakeSubsequence(string str1, string str2) {
    int n1 = str1.size();
    int n2 = str2.size();
    if(n1 < n2) return false;
    int targetIdx = 0;
    for(int i = 0; i < n1; ++i) {
        if(targetIdx < n2 && (str2[targetIdx] - str1[i] + 26) % 26 <= 1) targetIdx += 1;
    }

    return targetIdx == n2;
}

int main() {
    init();
    cout << canMakeSubsequence(str1, str2) << endl; 

    return 0;
}

// 2825. Make String a Subsequence Using Cyclic Increments
// Daily question: 04/12/2024 - Medium