#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int n, k;

void init() {
    cin >> n >> k;
}

string getHappyString(int n, int k) {
    if (k > (3 << (n - 1))) return ""; 
    
    queue<string> q;
    q.push(""); 
    
    while(k) {
        string curr = q.front();
        q.pop();
        
        for(char c = 'a'; c <= 'c'; c++) {
            if(curr.empty() || curr.back() != c) {
                q.push(curr + c);
                if(curr.size() + 1 == n) k--;
            }
            if(k == 0) break;
        }
    }

    return q.back();
}

int main() {
    init();

    cout << getHappyString(n, k) << endl;

    return 0;
}

// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// Daily question: 19/02/2025 - Medium