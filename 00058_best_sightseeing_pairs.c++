#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> values;

void init() {
    string line;
    getline(cin, line);
    istringstream ss(line);
    int num;
    while(ss >> num) values.push_back(num);
}

int maxScoreSightseeingPair(vector<int>& values) {
    const int n = values.size();

    if(n < 2) return values[0] + values[1] + 0 - 1;

    vector<int> suffixMax(n);

    suffixMax[n-1] = values[n-1] - (n-1);

    for(int i = n - 2; i >= 0; --i) suffixMax[i] = max(suffixMax[i+1], values[i] - i);

    int maxScore = INT_MIN;

    for(int i = 0; i < n - 1; ++i) maxScore = max(maxScore, values[i] + i + suffixMax[i+1]);

    return maxScore;
}

int main() {
    init();

    cout << maxScoreSightseeingPair(values) << endl;

    return 0;
}

// 1014. Best Sightseeing Pair
// Daily question: 27/12/2024 - Medium 