#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<vector<int>> nums1, nums2;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    int pos = 0;
    while(ss >> num) {
        vector<int> temp(2, 0);
        temp[pos%2] = num;
        if(pos%2) nums1.push_back(temp);
        pos++;
    }

    getline(cin, line);
    istringstream ss (line);
    while(ss >> num) {
        vector<int> temp(2, 0);
        temp[pos%2] = num;
        if(pos%2) nums2.push_back(temp);
        pos++;
    }
}

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    int i = 0, j = 0;
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> res;

    while(i < n && j < m) {
        if(nums1[i][0] == nums2[j][0]) {
            res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
            i++;
            j++;
        } else if(nums1[i][0] < nums2[j][0]) {
            res.push_back({nums1[i][0], nums1[i][1]});
            i++;
        } else {
            res.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }
    } 

    while(i < n) {
        res.push_back({nums1[i][0], nums1[i][1]});
        i++;
    } 

    while(j < m) {
        res.push_back({nums2[j][0], nums2[j][1]});
        j++;
    } 

    return res;
}

int main() {
    init();

    vector<vector<int>> res = mergeArrays(nums1, nums2);

    for(int i = 0; i < res.size(); ++i) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    return 0;
}

// 2570. Merge Two 2D Arrays by Summing Values
// Daily question: 02/03/2025 - Easy