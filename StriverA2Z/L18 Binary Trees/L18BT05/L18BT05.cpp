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
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
private:
    void inorder(Node* node, vector<int>& arr) { // {left,root,right}
        if(node==nullptr) return;
        inorder(node->left,arr);
        arr.push_back(node->data);
        inorder(node->right,arr);
    }
public:

    vector<int> inOrder(Node* root) {
        vector<int> arr;
        inorder(root,arr);
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
    vector<int> ans = sol.inOrder(root);

    for(auto x: ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
