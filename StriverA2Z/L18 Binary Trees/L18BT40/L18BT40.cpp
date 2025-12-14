#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
    // For minimum

    // Iterative approach:
    // public:
    // int minValue(Node* root) {
    //     if(!root) return -1;
    //     Node* node = root;
    //     while(node->left) {
    //         node = node->left;
    //     }
    //     return node->data;

    // TC -> O(log2N)
    // SC -> O(1)
    // }

    // Recursive Approach
    // public:
    // int minValue(Node* root) {
    //     if(!root) return -1;
    //     if(!root->left) return root->data;
    //     return minValue(root->left);

    //     // TC -> O(log2N)
    //     // SC -> O(log2N)
    // }

    // For maximum

    // Iterative Approch:
    // public:
    // int findMax(Node* root) {
    //     if(!root) return -1;
    //     Node* node = root;
    //     while(node->right) {
    //         node = node->right;
    //     }
    //     return node->data;

    //     // TC -> O(log2N)
    //     // SC -> O(1)
    // }

    // Recursive Approach:
    public:
    int findMax(Node* root) {
        if(!root) return -1;
        if(!root->right) return root->data;
        return findMax(root->right);

        // TC -> O(log2N)
        // SC -> O(log2N)
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

    // Here we learn how to find the min/max in a BST!!

    // Since BST follows a simple rule : L<N<R

    // So we know that the min will always be the left most element of the tree. Thus go as left as possible
    // Similarly to find min we go as right as possible.

    return 0;
}
