#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Class representing a Node in the Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class containing the logic for Binary Tree creation
class Solution {
public:
    Node* createBinaryTree() {
        // Creates the root node with val = 1
        Node* root = new Node(1);

        // Creates a left child node for the root with val = 2
        root->left = new Node(2);

        // Creates a right child node for the root with val = 3
        root-> right = new Node(3);

        // Create a right child node for the left child of the root with val = 5
        root-> left -> right  = new Node(5);

        return root; // This function reaturns the root node
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    Solution solution;
    Node* root = solution.createBinaryTree();
    cout << root->left->right->data << endl; // 5
    // Tree created, can be used for further operations

    return 0;
}
