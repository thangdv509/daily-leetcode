#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string s;
int k;

void init() {
    cin >> s;
    cin >> k;
}

int maxDistance(string s, int k) {
    int res = 0;
    vector<pair<char, char>> cases = {{'N', 'E'}, {'S', 'E'}, {'N', 'W'}, {'S', 'W'}};
        
    for(int i = 0; i < 4; ++i) {
        char x_dir = cases[i].first;
        char y_dir = cases[i].second;
        int hor = 0;
        int ver = 0;
        int max_move = k;
            
        for(char move : s) {
            if(move == 'N' || move == 'S') {
                if(move == x_dir) hor += 1;
                else {
                    hor = max_move > 0 ? hor + 1 : hor - 1;
                    max_move --;
                }
            }
    
            else if(move == 'E' || move == 'W') {
                if(move == y_dir) ver += 1;
                else {
                    ver = max_move > 0 ? ver + 1 : ver - 1;
                    max_move --;
                }
            }
    
            res = max(res, abs(hor) + abs(ver));
        }
    }
        
    return res;
}

int main() {
    init();

    cout << maxDistance(s, k) << endl;

    return 0;
}

// 3443. Maximum Manhattan Distance After K Changes
// Weekly Contest 435: 01/02/2025 - Medium