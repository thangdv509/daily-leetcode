#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int n;

void init() {
    cin >> n;
}

bool checkPowersOfThree(int n) {
    while (n > 0) {
        if (n % 3 == 2) {
            return false;
        }
        n /= 3;
    }
    return true;
}

int main() {
    init();

    cout << checkPowersOfThree(n) << endl;

    return 0;
}

// 1780. Check if Number is a Sum of Powers of Three
// Daily question: 04/03/2025 - Medium