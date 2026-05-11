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
public:
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if(!node) return {NULL,0};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        // Both side have same depths
        if(left.second==right.second) return {node,left.second+1};

        if(left.second>right.second) return {left.first, left.second+1};

        return {right.first, right.second+1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
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
