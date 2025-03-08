#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string blocks;
int k;

void init() {
    cin >> blocks >> k;
}

int minimumRecolors(string blocks, int k) {
    int black_count = 0, ans = INT_MAX;
    
    for (int i = 0; i < blocks.size(); i++) {
        if (i - k >= 0 && blocks[i - k] == 'B') black_count--;
        if (blocks[i] == 'B') black_count++;
        ans = min(ans, k - black_count);
    }
    
    return ans;
}

int main() {
    init();

    cout << minimumRecolors(blocks, k) << endl;

    return 0;
}

// 2379. Minimum Recolors to Get K Consecutive Black Blocks
// Daily question: 08/03/2025 - Easy