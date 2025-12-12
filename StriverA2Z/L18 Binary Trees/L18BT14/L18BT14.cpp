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
    // int height (Node* node) {
    //     if(node==nullptr) return 0;
    //     int lh = height(node->left);
    //     int rh = height(node->right);
    //     return 1 + max(lh,rh);
    // }
    int height(Node* node) { // Here we have made some tweeks and now we only get the height when we see that the tree is a balanced tree
        if(node==nullptr) return 0; // nullpointer node is also a balanced tree
        int lh = height(node->left);
        int rh = height(node->right);
        if(lh==-1 || rh==-1) return -1; // If at any node we find out that the tree is not Balanced, we return -1
        if(abs(lh-rh)>1) return -1; // If at any node we find out that the tree is not Balanced, we return -1
        return 1 + max(lh,rh);
    }
    public:
    // Brute-force solution
    // bool check1(Node* node) {
    //     if(node==nullptr) return true;

    //     int lh = height(node->left);
    //     int rh = height(node->right);

    //     if(abs(lh-rh)>1) return false;
    //     bool lc = check1(node->left);
    //     bool rc = check1(node->right);
    //     if(!lc || !rc) return false;
    //     return true;

    //     // TC -> O(N*N) (not favourable)
    // }

    // Optimized Approach (TC-> O(N))

    bool check2(Node* root) {
        if(height(root)<0) return false;
        return true;

        // TC -> O(N) (favourable)
        // SC -> O(N) (worst case->skew tree)
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
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    return 0;
}
