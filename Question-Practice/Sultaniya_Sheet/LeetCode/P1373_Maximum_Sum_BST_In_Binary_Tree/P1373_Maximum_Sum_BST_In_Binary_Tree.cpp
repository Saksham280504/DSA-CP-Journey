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

struct subTreeInfo {
    bool isBST;
    int Min;
    int Max;
    int sum;
};

class Solution {
private:
    int maxBSTSum;

    subTreeInfo dfs(TreeNode* node) {
        if(!node) return {true,INT_MAX,INT_MIN,0};
        auto leftInfo = dfs(node->left);
        auto rightInfo = dfs(node->right);
        if(leftInfo.isBST && leftInfo.Max<node->val && rightInfo.isBST && node->val<rightInfo.Min) {
            int sumOfTree = node->val + leftInfo.sum + rightInfo.sum;
            maxBSTSum = max(maxBSTSum,sumOfTree);
            return {true,min(leftInfo.Min,node->val),max(rightInfo.Max,node->val), sumOfTree};
        }
        return {false,0,0,0};
    }
public:
    int maxSumBST(TreeNode* root) {
        maxBSTSum = 0; // at the worst case we will return an empty BST with sum = 0
        dfs(root);
        return maxBSTSum;
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
