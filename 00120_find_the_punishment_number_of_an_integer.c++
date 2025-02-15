#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int n;

void init() {
    cin >> n;
}

bool canPartition(string stringNum, int target) {
    if(stringNum == "" && target == 0) return true;

    if(target < 0) return false;

    for(int idx = 0; idx < stringNum.size(); ++idx) {
        string left = stringNum.substr(0, idx+1);
        string right = stringNum.substr(idx+1);
        int leftNum = stoi(left);

        if(canPartition(right, target - leftNum)) return true;
    }

    return false;
}
    
int punishmentNumber(int n) {
    int res = 0;
    
    for (int i = 1; i <= n; i++) {
        int square = i*i;
    
        if (canPartition(to_string(square), i)) {
                res += square;
            }
        }
    return res;
}

int main() {
    init();

    cout << punishmentNumber(n) << endl;

    return 0;
}

// 2698. Find the Punishment Number of an Integer
// Daily question: 15/02/2025 - Medium
