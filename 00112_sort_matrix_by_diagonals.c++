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
        vector<int> row;
        int num;
        while(ss >> num) row.push_back(num);
        grid.push_back(row);
    }
}

vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> res (n, vector<int> (n, 0));
            
    for(int i = 1; i < n; ++i) {
        int curCol = 0; 
        int curRow = i;
        int idx = 0;
        vector<int> temp(n - i, 0); 
                
        while(curCol < n && curRow < n) {
            temp[idx] = grid[curCol][curRow];
            curCol += 1;
            curRow += 1;
            idx += 1;
        }
    
        sort(temp.begin(), temp.end());
    
        curCol = 0; 
        curRow = i;
        idx = 0; 
    
        while(curCol < n && curRow < n) {
            res[curCol][curRow] = temp[idx];
            curCol += 1;
            curRow += 1;
            idx += 1;
        }
    }
    
    for(int i = 0; i < n; ++i) {
        int curCol = i; 
        int curRow = 0;
        int idx = 0;
        vector<int> temp(n - i, 0); 
                
        while(curCol < n && curRow < n) {
            temp[idx] = grid[curCol][curRow];
            curCol += 1;
            curRow += 1;
            idx += 1;
        }
    
        sort(temp.begin(), temp.end(), greater<int>());
    
        curCol = i; 
        curRow = 0;
        idx = 0; 
    
        while(curCol < n && curRow < n) {
            res[curCol][curRow] = temp[idx];
            curCol += 1;
            curRow += 1;
            idx += 1;
        }
    }    
    return res;
}

int main() {
    init();

    vector<vector<int>> res = sortMatrix(grid);

    for(auto row : res) {
        for(auto num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

// 3446. Sort Matrix by Diagonals
// Weekly Contest 436: 09/02/2025 - Medium