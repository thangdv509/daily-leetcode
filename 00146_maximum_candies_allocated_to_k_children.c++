#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> candies;
long long k;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int candy;
    while(ss >> candy) candies.push_back(candy);

    cin >> k;
}


int maximumCandies(vector<int>& candies, long long k) {
    long long left = 1, right = *max_element(candies.begin(), candies.end());
    int result = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long children_count = 0;

        for (int pile : candies) {
            children_count += pile / mid;
        }

        if (children_count >= k) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    init();

    cout << maximumCandies(candies, k) << endl;

    return 0;
}

// 2226. Maximum Candies Allocated to K Children
// Daily question: 14/03/2025 - Medium