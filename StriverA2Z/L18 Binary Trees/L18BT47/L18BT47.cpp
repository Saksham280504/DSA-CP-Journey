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
    public:
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(!root) return nullptr;
        int curr = root->data;
        if(curr<p->data && curr<q->data) { // Both p and q lies on the right of node
            return lowestCommonAncestor(root->right,p,q);
        }
        if(curr>p->data && curr>q->data) { // Both p and q lies on the left of node
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;

        // TC -> O(Height of tree)
        // SC -> O(Height of tree) (Auxillary Stack space)
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
