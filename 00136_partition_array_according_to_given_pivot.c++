#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;
int pivot;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) nums.push_back(num);
    cin >> pivot;
}

vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    vector<int> res(len);
    int c=0;
    int pt=0;

    for(int i = 0; i < n; i++) {
        if(nums[i]<pivot) {
            res[pt++]=nums[i];
        }
        else if(nums[i]==pivot) {
            c++;
        }
    }

    while(c--) {
        res[pt++]=pivot;
    }

    for(int i = 0; i < len; i++) {
        if(nums[i]>pivot) {
            res[pt]=nums[i];
            pt++;
        }
    }

    return res;
}

int main() {
    init();

    vector<int> res = pivotArray(nums, pivot);

    for(int num : res) cout << num << " " << endl;

    return 0;
}

// 2161. Partition Array According to Given Pivot
// Daily question: 03/03/2025 - Medium