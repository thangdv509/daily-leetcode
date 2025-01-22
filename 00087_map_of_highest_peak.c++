#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<vector<int>> isWater;

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
        isWater.push_back(row); 
    }
}

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size();
    int n = isWater[0].size();

    vector<vector<int>> height(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(isWater[i][j]) {
                height[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(auto [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;

            if(nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1) {
                height[nx][ny] = height[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return height;
}
        
int main() {
    init();

    vector<vector<int>> res = highestPeak(isWater);

    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[0].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// 1765. Map of Highest Peak
// Daily question: 22/01/2025 - Medium