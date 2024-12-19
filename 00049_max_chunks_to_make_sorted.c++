#include<bits/stdc++.h>
#include<sstream>
#include<iostream>
using namespace std;

vector<int> arr;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while (ss >> num) arr.push_back(num);
}

int maxChunksToSorted(vector<int> arr) {
    int n = arr.size();
    int cnt = 0, diff = 0;
    for (int i = 0; i < n; ++i) {
        diff += arr[i] - i;
        cnt += (diff == 0);
    }

    return cnt;
}

int main() {
    init();

    cout << maxChunksToSorted(arr) << endl;

    return 0;
}

// 769. Max Chunks To Make Sorted
// Daily question: 19/12/2024 - Medium 