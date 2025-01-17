#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> derived;

void init(){
    string line;
    getline(cin, line);
    istringstream ss (line);    
    int num;
    while(ss >> num) derived.push_back(num);
}

bool doesValidArrayExist(vector<int>& derived) {
    int n = derived.size();
    int res = 0;

    for(int i = 0; i < n; ++i) res ^= derived[i];

    return res == 0;
}

int main() {
    init();

    cout << doesValidArrayExist(derived) << endl;

    return 0;
}

// 2683. Neighboring Bitwise XOR
// Daily question: 17/01/2025 - Medium