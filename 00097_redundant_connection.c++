#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<vector<int>> edges;

void init() {
    string line;
    while(getline(cin, line)) {
        if(line.empty()) break;
        istringstream ss (line);
        int vertice;
        vector<int> edge;
        while(ss >> vertice) edge.push_back(vertice);
        edges.push_back(edge);
    }
}

int findPar(int p, vector<int>par){
    if(p==par[p]){
        return p;
    }
    return findPar(par[p],par);
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> p(2000, 0);

    for(int i = 0; i < p.size(); i++) p[i] = i;
        
    vector<int> res;

    for(auto v : edges) {
        int n1 = v[0], n2 = v[1];
        while(n1 != p[n1]) n1 = p[n1];
        while(n2 != p[n2]) n2 = p[n2];
        if(n1 == n2)
            res = v;
        else
            p[n1] = n2;
    }
    return res;
}

int main() {
    init();

    vector<int> res = findRedundantConnection(edges);

    for(int num : res) cout << num << " ";
    cout << endl;

    return 0;
}

// 684. Redundant Connection
// Daily question: 29/01/2025 - Medium