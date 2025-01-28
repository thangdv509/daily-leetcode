#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<vector<int>> grid;

void init() {
    string line;
    while(getline(cin, line)) {
        if(line.empty()) break;
        istringstream ss (line);
        int num;
        vector<int> temp;
        while(ss >> num) temp.push_back(num);
        grid.push_back(temp);
    }
}

int findMaxFish(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;

    vector<vector<bool>> visited(n, vector<bool> (m, false));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] != 0 && visited[i][j] == false) {
                queue<pair<int, int>> q;
                q.push({i, j});
                int temp = 0;
                visited[i][j] = true;

                while(!q.empty()) {
                    auto curLand = q.front();
                    q.pop();

                    temp += grid[curLand.first][curLand.second];

                    int x[4] = {0, 0, 1, -1};
                    int y[4] = {1, -1, 0, 0};

                    for(int k = 0; k < 4; ++k) {
                        int newX = curLand.first + x[k];
                        int newY = curLand.second + y[k];

                        if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && grid[newX][newY] != 0) {
                            visited[newX][newY] = true;
                            q.push({newX, newY});
                        }
                    }
                }

                res = max(res, temp);
            }
        }
    }
        
    return res;
}

int main() {
    init();

    cout << findMaxFish(grid) << endl;

    return 0;
}

// 1462. Course Schedule IV
// Daily question: 27/01/2025 - Medium