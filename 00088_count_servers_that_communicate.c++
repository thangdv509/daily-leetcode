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

int countServers(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<int> rows(n, 0);
    vector<int> cols(m, 0);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            rows[i] += grid[i][j];
            cols[j] += grid[i][j];
        }
    }

    int res = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) res++;
        }
    }

    return res;
}

int main() {
    init();

    cout << countServers(grid) << endl;

    return 0;
}

// 1267. Count Servers that Communicate
// Daily question: 23/01/2025 - Medium