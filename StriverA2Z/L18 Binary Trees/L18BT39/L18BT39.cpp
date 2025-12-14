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
    // Recursive approach
    // public:
    // Node* SearchBST(Node* root, int val) {
    //     if(!root) return root;
    //     if(root->data==val) return root;
    //     if(root->data<val) return SearchBST(root->right,val);
    //     return SearchBST(root->left,val);

    //     // TC -> O(log2N)
    //     // SC -> O(log2N)
    // }
    
    // Iterative Approach:
    public:
    Node* searchBST(Node* root, int val){
        Node* node = root;
        while(node && node->data!=val) {
            node = node->data<val ? node->right : node->left;
        }
        return node;
        // TC -> O(log2N)
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
