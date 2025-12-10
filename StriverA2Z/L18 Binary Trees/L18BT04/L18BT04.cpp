#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// class representing the node of the Binary Tree
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

class Solution {
public:
    // Function to perform preorder traversal of the tree and store values in 'arr'

    void preorder(Node* node, vector<int>& arr) {
        if(node==nullptr) {
            return;
        }
        arr.push_back(node->data);
        preorder(node->left,arr);
        preorder(node->right,arr);
    }

    vector<int> preOrder(Node* root) {
        vector<int> arr; // This arr will contain the order of preOrder traversal.
        preorder(root,arr);
        return arr;
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

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> ans = sol.preOrder(root);

    for(auto x: ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
