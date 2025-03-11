#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void init() {
    cin >> s;
}

int numberOfSubstrings(string s) {
    int n=s.size();
    int i=0;
    int hash[3]={-1,-1,-1};
    int count=0;
    while(i<n)
    {
        hash[s[i]-'a']=i;
        if(hash[0]!=-1&&hash[1]!=-1&&hash[2]!=-1)
        {
            count+=(1+min(hash[0],min(hash[1],hash[2])));
        }
        i++;
    }
    return count;
}

int main() {
    init();

    cout << numberOfSubstrings(s) << endl;

    return 0;
}

// 1358. Number of Substrings Containing All Three Characters
// Daily question: 11/03/2025 - Medium