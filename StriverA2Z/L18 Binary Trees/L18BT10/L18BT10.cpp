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
public:
    vector<int> postOrderTraversal(Node* root) {
        vector<int> ans; 
        if(root==nullptr) return ans;
        stack<Node*> st1,st2;
        Node* node = root;
        st1.push(node);

        while(!st1.empty()) {
            Node* temp = st1.top();
            st1.pop();
            st2.push(temp);
            if(temp->left!=nullptr) st1.push(temp->left);
            if(temp->right!=nullptr) st1.push(temp->right);
        }

        while(!st2.empty()) {
            Node* temp = st2.top();
            st2.pop();
            ans.push_back(temp->data);
        }

        return ans;
    }

    // TC -> O(2N)
    // SC -> O(2N)
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
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->left->right->right = new Node(8);
    Solution sol;
    vector<int> ans = sol.postOrderTraversal(root);

    for(auto x: ans) cout << x << " ";

    return 0;
}
