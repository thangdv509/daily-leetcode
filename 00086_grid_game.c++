#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std; 

vector<vector<int>> grid;

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
        grid.push_back(row); 
    }
}

long long gridGame(vector<vector<int>>& grid) {
    long long top = 0;

    for (int i = 0; i < grid[0].size(); i++) {
        top += grid[0][i];
    }

    long long bottom = 0, res = LLONG_MAX;

    for (int i = 0; i < grid[0].size(); i++) {
        top -= grid[0][i]; 
        res = min(res, max(top, bottom)); 
        bottom += grid[1][i]; 
    }
    return res; 
}

int main() {
    init();

    cout << gridGame(grid) << endl;

    return 0;
}

// 2017. Grid Game
// Daily question: 21/01/2025 - Medium