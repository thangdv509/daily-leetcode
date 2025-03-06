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
        vector<int> temp;
        int num;
        while(ss >> num) temp.push_back(num);
        grid.push_back(temp);
    }
}

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    int total = n * n;
    vector<int> count(total + 1,0);
    int repeated = -1, missing = -1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            count[grid[i][j]]++;
        }
    }

    for(int num = 1; num <= total; num++) {
        if (count[num] == 2) repeated = num;
        if (count[num] == 0) missing = num;
        if (repeated != -1 && missing != -1) break;
    }

    return {repeated,missing};
}

int main() {
    init();

    vector<int> res = findMissingAndRepeatedValues(grid);

    cout << res[0] << " " << res[1] << endl;

    return 0;
}

// 2965. Find Missing and Repeated Values
// Daily question: 06/03/2025 - Easy