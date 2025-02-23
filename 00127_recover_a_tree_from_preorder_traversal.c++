#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int i = 0;
TreeNode* makeTree(queue<vector<int>> &tree, int &n) {
    // Base case: If queue is empty we exhaust the input and fill the 
    // rest of the tree with NULL
    if(tree.empty()) {
        return NULL;
    }

    // Extract current node values and assign them
    int currDepth = tree.front()[0], currVal = tree.front()[1];
    tree.pop();
    TreeNode *node = new TreeNode(currVal);

    // If next node depth is greater we assign it as the left child
    if(!tree.empty() && (tree.front()[0] > currDepth)) {
        node -> left = makeTree(tree, n);
    } else {
        return node;
    }

    // If next node depth is greater we assign it as the right child
    if(!tree.empty() && (tree.front()[0] > currDepth)) {
        node -> right = makeTree(tree, n);
    } else {
        return node;
    }

    // Returning the created node at end 
    return node;
}

TreeNode* recoverFromPreorder(string traversal) {
    int n = traversal.size();
    queue<vector<int>> tree;

    // Modifying input for easier recursion 
    int depth = 0, i = 0;
    while(i < n) {
        // Computing the depth of the next node by counting -'s
        int depth = 0;
        while(i < n && traversal[i] == '-') {
            depth++;
            i++;
        }

        // Computing the value
        int val = 0;
        while(i < n && isdigit(traversal[i])) {
            val = val * 10 + (traversal[i] - '0');
            i++;
        }

        tree.push({depth, val});
    }

    int m = tree.size();
    return makeTree(tree, m);
}

// 1028. Recover a Tree From Preorder Traversal
// Daily question: 22/02/2025 - Medium