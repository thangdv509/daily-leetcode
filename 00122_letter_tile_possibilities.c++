#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string tiles;

void init() {
    cin >> tiles;
}

void solve(int* mpp, int& cnt) {

    for(int i = 0; i < 26; i++) {
        if (mpp[i] > 0) {
            mpp[i]--;
            cnt++;
            solve(mpp, cnt);
            mpp[i]++;
        }
    }
}

int numTilePossibilities(string tiles) {
    int mpp[26] = {0};
    for(char c : tiles) mpp[c - 'A']++;

    int cnt = 0;
    solve(mpp, cnt);
    return cnt;
}

int main() {
    init();

    cout << numTilePossibilities(tiles) << endl;

    return 0;
}

// 1079. Letter Tile Possibilities
// Daily question: 17/02/2025 - Medium

