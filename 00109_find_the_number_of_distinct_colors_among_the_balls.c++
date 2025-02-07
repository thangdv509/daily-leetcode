#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

int limit;
vector<vector<int>> queries;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    int pos = 0;
    vector<int> temp;
    while(ss >> num) {
        temp[pos % 2] = num;
        queries.push_back(temp);
    }

    cin >> limit;
}

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int,int> ball, color;
    vector<int> ans;
        
    ans.reserve(queries.size());
    int distinct = 0;
    
    for(auto &q : queries) {
        int pos = q[0], c = q[1];
        if(ball.count(pos))
            if(--color[ball[pos]] == 0) distinct--;
        ball[pos] = c;
        if(++color[c] == 1) distinct++;
        ans.push_back(distinct);
    }
    return ans;
}

int main() {
    init();

    vector<int> res = queryResults(limit, queries);

    return 0;
}

// 3160. Find the Number of Distinct Colors Among the Balls
// Daily question: 07/02/2025 - Medium