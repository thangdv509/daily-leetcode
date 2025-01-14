#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> A, B;

void init() {
    string a;
    getline(cin, a);
    istringstream ssA (a);
    int numA;
    while(ssA >> numA) A.push_back(numA);

    string b;
    getline(cin, b);
    istringstream ssB (b);
    int numB;
    while(ssB >> numB) B.push_back(numB);
}

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<bool> seen(51, false);
    vector<int> res;
    int common = 0;

    for(int i = 0; i < n; ++i) {
        if(seen[A[i]]) ++common;
        else seen[A[i]] = true;

        if(seen[B[i]]) ++common;
        else seen[B[i]] = true;

        res.push_back(common);
    }

    return res;
}

int main() {
    init();

    vector<int> res = findThePrefixCommonArray(A, B);

    return 0;
}

// 2657. Find the Prefix Common Array of Two Arrays
// Daily question: 14/01/2025 - Medium