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
class Solution {

    // The core intuition is that the new val is appended to the right of the existing array, thus it will only affect the right side of the mayBinary tree.

    // Case 1: when val > root->val (create a new node and add the root to its left, then return the node)
    // Case 2: when val < root->val (the val will be added to the right of the root only because it is present on the right-most side of the array)
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root || val > root->val) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        root->right = insertIntoMaxTree(root->right,val);
        return root;
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
