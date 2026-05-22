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
    int leftHeight(TreeNode* node) {
        if(!node) return 0;
        int lh = leftHeight(node->left);
        return 1+lh;
    }
    int rightHeight(TreeNode* node) {
        if(!node) return 0;
        int rh = rightHeight(node->right);
        return 1+rh;
    }
    public:
        int countNodes(TreeNode* root) {
            if(!root) return 0;
            int lh = leftHeight(root);
            int rh = rightHeight(root);
            if(lh==rh) return (1<<lh) - 1;
            return 1 + countNodes(root->left) + countNodes(root->right);
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
