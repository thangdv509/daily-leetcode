#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<vector<int>> graph;

void init() {
    string line;
    while(getline(cin, line)) {
        if(line.empty()) break;
        istringstream ss (line);
        int num;
        vector<int> adjacent;
        while(ss >> num) adjacent.push_back(num);
    }
}

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visit, vector<bool>& inStack) {
    if(inStack[node]) return true;

    if(visit[node]) return false;

    visit[node] = true;
    inStack[node] = true;

    for(auto neighbor : adj[node]) {
        if(dfs(neighbor, adj, visit, inStack)) return true;
    }

    inStack[node] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visit(n), inStack(n);

    for(int i = 0; i < n; ++i) dfs(i, graph, visit, inStack);

    vector<int> safeNodes;

    for(int i = 0; i < n; ++i) {
        if(!inStack[i]) {
            safeNodes.push_back(i);
        }
    }

    return safeNodes;
}

int main() {
    init();

    vector<int> res = eventualSafeNodes(graph);

    for(int node : res) cout << node << " ";
    cout << endl;

    return 0;
}

// 802. Find Eventual Safe States
// Daily question: 24/01/2025 - Medium