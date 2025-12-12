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
    private:
    bool isLeaf(Node* node) {
        if(node->left==nullptr && node->right==nullptr) return true;
        return false;
    }
    void addLeftBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->left;
        while(curr) {
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    void addLeaves(Node* root, vector<int>& ans) {
        if(isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left,ans);
        if(root->right) addLeaves(root->right,ans);
    }
    void addRightBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->right;
        stack<int> st;
        while(curr) {
            if(!isLeaf(curr)) st.push(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }
    public:
    vector<int> boundary(Node* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root,ans);
        addLeaves(root,ans);
        addRightBoundary(root,ans);

        return ans;
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

    return 0;
}
