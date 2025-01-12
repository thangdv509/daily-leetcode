#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

string parentheses;
string lockedStatus;

void init() {
    cin >> parentheses >> lockedStatus;
}

bool canBeValid(string parentheses, string lockedStatus) {
    int stringLength = parentheses.size();
    if(stringLength % 2 == 1) return false;

    stack<int> openIndices;
    stack<int> unlockedIndices;

    for (int i = 0; i < stringLength; i++) {
        if (lockedStatus[i] == '0') {
            unlockedIndices.push(i);
        } else if (parentheses[i] == '(') {
            openIndices.push(i);
        } else if (parentheses[i] == ')') {
            if (!openIndices.empty()) {
                openIndices.pop();
            } else if (!unlockedIndices.empty()) {
                unlockedIndices.pop();
            } else {
                return false;
            }
        }
    }

    while (!openIndices.empty() && !unlockedIndices.empty() &&
            openIndices.top() < unlockedIndices.top()) {
        openIndices.pop();
        unlockedIndices.pop();
    }

    if (openIndices.empty() && !unlockedIndices.empty()) {
        return unlockedIndices.size() % 2 == 0;
    }
    
    return openIndices.empty();
}

int main() {
    init();

    bool res = canBeValid(parentheses, lockedStatus);

    return 0;
}

// 2116. Check if a Parentheses String Can Be Valid
// Daily question: 12/01/2025 - Medium