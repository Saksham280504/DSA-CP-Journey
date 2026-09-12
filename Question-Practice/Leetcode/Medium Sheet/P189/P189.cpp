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
        left = right = nullptr;
    }
};
class Solution {
public:
    pair<TreeNode*,int> postOrder(TreeNode* node,int depth) {
        if(!node) return {nullptr,-1};
        auto [leftNode, maxLeftDepth] = postOrder(node->left,depth+1);
        auto [rightNode, maxRightDepth] = postOrder(node->right,depth+1);
        if(maxLeftDepth>maxRightDepth) return {leftNode,maxLeftDepth};
        else if(maxLeftDepth<maxRightDepth) return {rightNode,maxRightDepth};
        return {node,max({depth,maxLeftDepth,maxRightDepth})};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return postOrder(root,0).first;
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
