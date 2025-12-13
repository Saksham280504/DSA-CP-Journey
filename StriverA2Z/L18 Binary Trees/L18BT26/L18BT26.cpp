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
    Node* lca(Node* node, Node* p, Node* q) {
        if(!node || node==p || node==q) return node;
        Node* ln = lca(node->left,p,q);
        Node* rn = lca(node->right,p,q);
        if(!ln) return rn;
        else if(!rn) return ln;
        else return node; // If at a node, both ln and rn exists, that would only happen at the LCA
    }
    public:
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(!root || !p || !q) return nullptr;
        return lca(root,p,q);
    }

    // TC -> O(N)
    // SC -> O(height of tree)
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
