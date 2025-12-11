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
    int MaxDepth(Node* node) {
        if(node==nullptr) return 0;
        return 1 + max(MaxDepth(node->left),MaxDepth(node->right)); // If there exists a valid node, then that has height of atleast 1

        // TC -> O(N)
        // SC -> O(N) (worst case->skew DS)
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
    root->right->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    int depth = sol.MaxDepth(root);
    cout << depth << endl;

    return 0;
}
