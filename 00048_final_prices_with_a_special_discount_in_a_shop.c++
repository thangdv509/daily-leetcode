#include<bits/stdc++.h>
#include<stack>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> prices;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) prices.push_back(num);
}

vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    int stack[500];
    int top = 0;
    stack[top] = n-1;
    vector<int> res = prices;

    for(int i = n - 2; i >= 0; --i) {
        while(top >= 0 && prices[i] < prices[stack[top]]) top--;
        if(top >= 0) res[i] -= prices[stack[top]];
        stack[++top] = i;
    }
    return res;
}

int main() {
    init();

    vector<int> res = finalPrices(prices);

    for(int num : res) cout << num << " " << endl;

    return 0;
}

// 1475. Final Prices With a Special Discount in a Shop
// Daily question: 18/12/2024 - Medium 