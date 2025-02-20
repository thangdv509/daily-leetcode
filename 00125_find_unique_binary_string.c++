#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<string> nums;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    string s;
    while(ss >> s) nums.push_back(s);
}

string findDifferentBinaryString(vector<string>& nums) {
    string result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i][i] == '0') {
            result += '1';
        } else {
            result += '0';
        }
    }
    return result;
}

int main() {
    init();

    cout << findDifferentBinaryString(nums) << endl;

    return 0;
}

// 1980. Find Unique Binary String
// Daily question: 20/02/2025 - Medium