#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

class Solution {
    private:
    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node || node==p || node==q) return node;
        TreeNode* ln = lca(node->left,p,q);
        TreeNode* rn = lca(node->right,p,q);
        if(!ln) return rn;
        if(!rn) return ln;
        return node; // If both ln and rn exists then that would happen at LCA
    }
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p, TreeNode* q) {
            if(!root || !p || !q) return nullptr;
            return lca(root,p,q);
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
