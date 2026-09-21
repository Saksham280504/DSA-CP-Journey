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
    int totalPaths = 0;
    unordered_map<long long,long long> freq; // {sum,freq}
    void dfs(TreeNode* node, long long currSum, long long targetSum) {
        if(!node) return;
        currSum = currSum + (long long)node->val;
        if(freq.count(currSum-targetSum)) {
            totalPaths += freq[currSum-targetSum];
        }
        freq[currSum]++;
        dfs(node->left,currSum,targetSum);
        dfs(node->right,currSum,targetSum);
        freq[currSum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        freq.clear();
        totalPaths = 0;
        freq[0] = 1;
        dfs(root,0,targetSum);
        return totalPaths;
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
