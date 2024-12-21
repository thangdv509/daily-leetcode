#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<unordered_map>
using namespace std;

vector<vector<int>> grid;
int k;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    int pos = 0;
    vector<int> temp (4, 0);

    while (ss >> num) {
        temp[pos]; 
        if(pos %= 4) grid.push_back(temp); 
    }
}


int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<unordered_map<int, int>>> dp(rows, vector<unordered_map<int, int>>(cols));
    return dfs(grid, 0, 0, grid[0][0], k, dp);
}

int dfs(vector<vector<int>>& grid, int x, int y, int curXor, int k, vector<vector<unordered_map<int, int>>>& dp) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (x == rows - 1 && y == cols - 1) {
        return curXor == k ? 1 : 0;
    }

    if (dp[x][y].count(curXor)) {
        return dp[x][y][curXor]; 
    }

    int result = 0;
    if (x + 1 < rows) {
        result += dfs(grid, x + 1, y, curXor ^ grid[x + 1][y], k, dp);
        result %= 1000000007;
    }
    
    if (y + 1 < cols) {
        result += dfs(grid, x, y + 1, curXor ^ grid[x][y + 1], k, dp);
        result %= 1000000007;
    }

    return dp[x][y][curXor] = result;
}

int main() {
    init();

    cout << countPathsWithXorValue(grid, k) << endl;

    return 0;
}

// Q2. Count Paths With the Given XOR Value
// Biweekly Contest 146: 08/12/2024 - Medium