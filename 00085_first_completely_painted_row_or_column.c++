#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std; 

vector<vector<int>> mat;
vector<int> arr;

void init() {
    string line;
    while(getline(cin, line)) {
        if(line.empty()) break;
        stringstream ss(line);
        vector<int> row;
        int value;
        while (ss >> value) {
            row.push_back(value); 
        }
        mat.push_back(row); 
    }

    getline(cin, line);
    stringstream ss(line);
    int num;
    while(ss >> num) arr.push_back(num);
}

int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<pair<int, int>> num_to_coordinates(m*n);
        
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++)
            num_to_coordinates[mat[r][c]-1] = make_pair(r, c);

    vector<int> row_tally(m, 0);
    vector<int> col_tally(n, 0);

    for (int i = 0; i < arr.size(); i ++) {
        auto& [r, c] = num_to_coordinates[arr[i]-1];
        if (++row_tally[r] == n || ++col_tally[c] == m)
            return i;
        }

    return arr.size();
}

int main() {
    init();

    cout << firstCompleteIndex(arr, mat) << endl;

    return 0;
}

// 2661. First Completely Painted Row or Column
// Daily question: 20/01/2025 - Medium