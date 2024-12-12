#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> gifts;
int k;

void init() {
    string line;
    getline(cin, line);
    istringstream ss(line);
    int num;
    while (ss >> num) gifts.push_back(num);

    cin >> k;
}

long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<int> q;
    long long ans = 0;

    for (int i : gifts) {
        q.push(i);
        ans += i;
    }

    while (k--) {
        int v = q.top();
        ans -= (v - sqrt(v));
        q.pop();
        q.push(sqrt(v));
    }

    return ans; 
}

int main () {
    init();

    cout << pickGifts(gifts, k) << endl;

    return 0;
}

// 2558. Take Gifts From the Richest Pile
// Daily question: 12/12/2024 - Easy