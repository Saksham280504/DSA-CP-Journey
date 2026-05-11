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
        left = nullptr;
        right = nullptr;
    }
};

// The key idea of the problem is:
// On every node, try to expand a path from: 
// left child -> current node
// right child -> current node
// But only if the child has the same value as that of the current node
// The answer at a node can become: leftPath + rightPath

class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* node) { // We follow postOrder Traversal approach here -> left->right->node
        if(!node) return 0;

        // 1. Recursively try to find the longest same-value chain from the leftSubTree and rightSubTree.
        int left = dfs(node->left);
        int right = dfs(node->right);
        int leftPath = 0, rightPath = 0;

        // 2. Now try to check that can the left and right SubTree be connected to the currentNode.
        if(node->left && node->left->val==node->val) leftPath = left+1;
        else leftPath = 0; // If not then that subTree is of no use for further connections, hence remove it (make path = 0)
        if(node->right && node->right->val==node->val) rightPath = right+1;
        else rightPath = 0;

        ans = max(ans,leftPath + rightPath); // ans variable holds the value of the longest same-value path length through a node of the tree.

        return max(leftPath, rightPath); // 3. The parent can only carry one branch upward so it will carry the longest path.
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
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
