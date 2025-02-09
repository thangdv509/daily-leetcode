#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> groups;
vector<int> elements;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) groups.push_back(num);

    getline(cin, line);
    istringstream ss (line);
    while(ss >> num) elements.push_back(num);
}

vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
    int MAX_VAL = 100000;  
    vector<int> minIndex(MAX_VAL + 1, -1);  
            
    for (int j = 0; j < elements.size(); ++j) {
        if (minIndex[elements[j]] == -1) {
            minIndex[elements[j]] = j; 
        }
    }
    
    vector<int> res(groups.size(), -1);
    
    for (int i = 0; i < groups.size(); ++i) {
        int bestIndex = INT_MAX;
        for (int d = 1; d * d <= groups[i]; ++d) {
            if (groups[i] % d == 0) {
                if (minIndex[d] != -1) bestIndex = min(bestIndex, minIndex[d]);
                if (minIndex[groups[i] / d] != -1) bestIndex = min(bestIndex, minIndex[groups[i] / d]);
            }
        }
        res[i] = (bestIndex == INT_MAX ? -1 : bestIndex);
    }
    
    return res;
}

int main() {
    init();

    vector<int> res = assignElements(groups, elements);

    for(auto num : res) {
        cout << num << " ";
    }

    return 0;
}

// 3447. Assign Elements to Groups with Constraints
// Weekly Contest 436: 09/02/2025 - Medium