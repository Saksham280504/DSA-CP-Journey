#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    pair<int,int> dfs(TreeNode* node) {
        if(!node) return {0,0};
        auto [left_keep, left_skip] = dfs(node->left);
        auto [right_keep,right_skip] = dfs(node->right);
        int node_keep = node->val + left_skip + right_skip;
        int node_skip = 0 + max(left_keep,left_skip) + max(right_keep,right_skip);
        return {node_keep,node_skip};
    }
public:
    int rob(TreeNode* root) {
        auto [root_keep,root_skip] = dfs(root);
        return max(root_keep,root_skip);
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
