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
    // Recursive Method (reverse postorder approach -> right left root)
    // private:
    // void flattenTree(Node* node, Node*& prev) {
    //     if(!node) return;
    //     flattenTree(node->right,prev);
    //     flattenTree(node->left,prev);
    //     node->right = prev;
    //     node->left = nullptr;
    //     prev = node;
    // }
    // public:
    // void flatten(Node* root) { 
    //     if(!root) return;
    //     Node* prev = nullptr;
    //     flattenTree(root,prev);
    //     // TC -> O(N)
    //     // SC -> O(Height of tree)
    // }

    // Iterative Approach (level order)
    // public:
    // void flatten(Node* root) {
    //     if(!root) return;
    //     stack<Node*> st;
    //     st.push(root);
    //     while(!st.empty()) {
    //         Node* curr = st.top();
    //         st.pop();
    //         if(curr->right) st.push(curr->right);
    //         if(curr->left) st.push(curr->left);
    //         if(!st.empty()) curr->right = st.top();
    //         curr->left = nullptr;
    //     }
    // }
    // // TC-> O(N)
    // // SC -> O(N)

    // Morris Approach 
    public:
    void flatten(Node* root) {
        if(!root) return;
        Node* curr = root;
        while(curr) {
            if(curr->left) {
                Node* prev = curr->left;
                while(prev->right) {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }

        // TC -> O(N)
        // SC -> O(1)
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
