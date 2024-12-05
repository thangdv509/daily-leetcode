#include<iostream>
#include<string>
using namespace std;

string start, target;

void init() {
    cin >> start >> target;
}

bool canChange(string start, string target) {
    int n = start.size();
    for(int i = 0, j = 0; i < n || j < n; ++i, ++j) {
        while(i < n && start[i] == '_') i++;
        while(j < n && target[j] == '_') j++;

        char c = start[i];

        if(c != target[j]) return 0;
        if(c == 'L' && i < j) return 0;
        if(c == 'R' && i > j) return 0;
    }
}

int main() {
    init();
    cout << canChange(start, target);

    return 0;
}

// 337. Move Pieces to Obtain a String
// Daily question: 05/12/2024 - Medium
