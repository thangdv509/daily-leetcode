#include<bits/stdc++.h>
#include<unordered_map>
#include<iostream>
using namespace std;

unordered_map<int, int> mp;
int a, b, M;

void init() {
    cin >> a >> b >> M;
    mp[0] = 0;
    mp[1] = 1;
}

int _fib(int x) {
    if(mp.count(x)) {
        return mp[x];
    } else {
        int temp = _fib(x-1) + _fib(x-2);
        mp[x] = temp;
        return temp;
    }
}


int gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;
    if(a == b) return a;
    if(a > b) return gcd(a - b, b);
    else return gcd(a, b - a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int fiba = _fib(a);
    int fibb = _fib(b);
    int maxGcd = gcd(fiba, fibb);
    cout << maxGcd % M << endl;
    return 0;
}