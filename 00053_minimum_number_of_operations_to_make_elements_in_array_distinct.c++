#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while (ss >> num) nums.push_back(num);
}

int minimumOperations(vector<int>& nums) {
    int res = 0;
    int mistake = 0;
    int n = nums.size();
        
    vector<int> count(101, 0);
    
    for(int i = 0; i < n; ++i) {
        count[nums[i]] ++;
        if(count[nums[i]] == 2) mistake ++;
    }

            
    if(mistake == 0) return res;

    int curIdx = 3;

    while(curIdx <= n - 2) {
        res ++;
        for(int i = curIdx - 3; i < curIdx; ++i) {
            count[nums[i]] --;
            if(count[nums[i]] == 1) mistake -=1;
        }

        if(mistake == 0) return res;

        curIdx += 3;
    } 

    if(mistake == 0) return res;
    else return res+1;
}

int main () {
    init();

    cout << minimumOperations(nums) << endl;

    return 0;
}

// 3396. Minimum Number of Operations to Make Elements in Array Distinct
// Weekly Contest 429: 22/12/2024 - Easy