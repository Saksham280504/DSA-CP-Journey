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
class Solution {
    private:
    int moves;
    int PostOrder(TreeNode* node) {
        if(!node) return 0;
        int left_balance = PostOrder(node->left);
        int right_balance = PostOrder(node->right);
        moves += abs(left_balance) + abs(right_balance);
        return node->val-1+left_balance+right_balance;
    }
    public:
    int distributeCoins(TreeNode* root) {
        moves = 0;
        PostOrder(root);
        return moves;
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
