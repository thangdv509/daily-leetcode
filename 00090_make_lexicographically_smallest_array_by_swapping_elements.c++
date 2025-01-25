#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> arr;
int threshold;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) arr.push_back(num);

    cin >> threshold;
}

vector<int> lexicographicallySmallestArray(vector<int>& arr, int threshold) {
    vector<pair<int, int>> valueIndexPairs;
    int size = arr.size();

    for(int i = 0; i < size; ++i) valueIndexPairs.push_back({arr[i], i});

    sort(valueIndexPairs.begin(), valueIndexPairs.end());

    vector<vector<pair<int, int>>> groupedPairs;
    groupedPairs.push_back({valueIndexPairs[0]});

    for(int i = 1; i < size; ++i) {
        if(valueIndexPairs[i].first - valueIndexPairs[i-1].first <= threshold) groupedPairs.back().push_back(valueIndexPairs[i]);
        else groupedPairs.push_back({valueIndexPairs[i]});
    }

    for(const auto& group : groupedPairs) {
        vector<int> indices;

        for(const auto& [value, index] : group) indices.push_back(index);

        sort(indices.begin(), indices.end());

        for(size_t i = 0; i < indices.size(); ++i) arr[indices[i]] = group[i].first; 
    }

    return arr;
}

int main() {
    init();

    vector<int> res = lexicographicallySmallestArray(arr, threshold);

    for(int num : res) cout << num << " ";
    cout << endl;

    return 0;
}

// 2948. Make Lexicographically Smallest Array by Swapping Elements
// Daily question: 25/01/2025 - Medium
