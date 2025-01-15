#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

int num1, num2;

void init() {
    cin >> num1 >> num2;
}

int countSetBits(int n) {
    int count = 0;
    while(n) {
        count += n & 1;
        n >>= 1;
    }
    return count; 
}

int minimizeXor(int num1, int num2) {
    int bits = countSetBits(num2);
    int res = 0;

    for (int i = 31; i >= 0 && bits > 0; i--) {
        if (num1 & (1 << i)) {
            res |= (1 << i);
            bits--;
        }
    }
    
    for (int i = 0; i < 32 && bits > 0; i++) {
        if (!(res & (1 << i))) {
            res |= (1 << i);
            bits--; 
        }
    }
    return res;
}

int main() {
    init();

    cout << minimizeXor(num1, num2) << endl;

    return 0;
}

// 2429. Minimize XOR
// Daily question: 15/01/2025 - Medium