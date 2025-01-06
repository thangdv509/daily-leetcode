#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

string boxes;

void init() {
    cin >> boxes;
}

vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> left(n, 0), right(n, 0), res(n, 0);
    int count = (boxes[0] == '1' ? 1 : 0);

    for(int i = 1; i < n; ++i) {
        left[i] = left[i-1] + count;
        count += boxes[i] == '1' ? 1 : 0;
    }

    count = boxes[n-1] == '1' ? 1 : 0;

    for(int i = n-2; i >= 0; --i) {
        right[i] = right[i+1] + count;
        count += boxes[i] == '1' ? 1 : 0;
    }

    for(int i = 0; i < n; ++i) res[i] = left[i] + right[i];

    return res;
}


int main() {
    init();

    vector<int> res = minOperations(boxes);

    for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";

    return 0;
}

// 1769. Minimum Number of Operations to Move All Balls to Each Box
// Daily question: 06/01/2025 - Medium

