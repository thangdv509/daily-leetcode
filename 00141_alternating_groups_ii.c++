#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> colors;
int k;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) colors.push_back(num);
}

int numberOfAlternatingGroups(vector<int>& colors, int k) {
    colors.insert(colors.end(), colors.begin(), colors.begin() + (k - 1));
    int count = 0;
    int left = 0;
    
    for (int right = 0; right < colors.size(); ++right) {
        if (right > 0 && colors[right] == colors[right - 1]) {
            left = right;  
        }
        
        if (right - left + 1 >= k) {
            count++;  
        }
    }
    
    return count;
}

int main() {
    init();

    cout << numberOfAlternatingGroups(colors, k) << endl;

    return 0;
}

// 3208. Alternating Groups II
// Daily question: 09/03/2025 - Medium