#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> days;
vector<int> costs;

void init() {  
    string line;
    getline(cin, line);
    istringstream ss (line);
    int day;
    while(ss >> day) days.push_back(day);

    getline(cin, line);
    istringstream ss (line);
    int cost;
    while (ss >> cost) costs.push_back(cost);
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    int totalCost = 0;
    int left7 = 0, left30 = 0;

    vector<int> dp(n, 0);

    for(int i = 0; i < n; ++i) {
        while(days[i] - days[left7] >= 7) left7 ++;
        while(days[i] - days[left30] >= 30) left30 ++;

        int cost1 = (i > 0 ? dp[i-1] : 0) + costs[0];
        int cost7 = (left7 > 0 ? dp[left7-1] : 0) + costs[1];
        int cost30 = (left30 > 0 ? dp[left30-1] : 0) + costs[2];

        dp[i] = min({cost1, cost7, cost30});
    }

    return dp[n-1];
}

int main () {
    init();

    cout << mincostTickets(days, costs) << endl;

    return 0;
}

// 983. Minimum Cost For Tickets
// Daily question: 31/12/2024 - Medium

