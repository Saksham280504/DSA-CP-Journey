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
    int maxLen = 0;
    void dfs(TreeNode* node, bool go_left, int length) {
        if(!node) return;
        maxLen = max(maxLen,length); // Whenever you reach a node, compare the max_zig_zag_path with the current zig-zag path length.
        if(go_left) { // You can go left
            dfs(node->left,false,length+1); // You went left, the zigzag path continues
            dfs(node->right,true,1); // You didn't go left, start a new zigzag path
        }
        else { // You can go right
            dfs(node->right,true,length+1); // You went right, the zigzag path continues
            dfs(node->left,false,1); // You didn't go right, start a new zigzag path
        }
    }
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        dfs(root->left,false,1);
        dfs(root->right,true,1);
        return maxLen;
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
