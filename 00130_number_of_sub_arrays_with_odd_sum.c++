#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> arr;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) arr.push_back(num);
}

int numOfSubarrays(vector<int>& arr) {
    long long oddCount = 0, prefixSum = 0;
    for(int a : arr) {
        prefixSum += a;
        oddCount += prefixSum % 2;
    }
    oddCount += (arr.size() - oddCount) * oddCount;
    return oddCount % 1'000'000'007;
}

int main() {
    init();

    cout << numOfSubarrays(arr) << endl;

    return 0;
}

// 1524. Number of Sub-arrays With Odd Sum
// Daily question: 25/02/2025 - Medium