#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Node{
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
    public:
    vector<int> getInorder(Node* root) { // left root right
        vector<int> inorder;
        if(!root) return inorder;
        Node* curr = root;
        while(curr) {
            if(!curr->left) {
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else {
                Node* prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if(!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = nullptr;
                    inorder.push_back(curr->data); // Here I always push when I destroy the thread (2nd visit on curr)
                    curr = curr->right;
                }
            }
        }

        return inorder;

        // TC -> O(N)
        // SC -> O(1)
    }

    vector<int> getPreorder(Node* root) { // root left right
        vector<int> preorder;
        if(!root) return preorder;
        Node* curr = root;
        while(curr) {
            if(!curr->left) {
                preorder.push_back(curr->data);
                curr = curr->right;
            }
            else {
                Node* prev = curr->left;
                while(prev->right && prev->right!=curr) {
                    prev = prev->right;
                }
                if(!prev->right) {
                    prev->right = curr;
                    preorder.push_back(curr->data); // Here I always push when I make the thread (1st visit on curr)
                    curr = curr->left;
                }
                else {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return preorder;
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
    root->left->right->right = new Node(6);

    Solution sol;
    vector<int> inorder = sol.getInorder(root);
    vector<int> preorder = sol.getPreorder(root);

    for(auto x: inorder) cout << x << " "; 
    cout << endl;
    for(auto x: preorder) cout << x << " "; 

    return 0;
}
