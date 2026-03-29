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


// Inorder traversal of a BST gives nodes in sorted order. So there are only two cases of swaps- 1. Adjacent swaps, 2. Non-Adjacent swaps
class Solution {
    private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    void inOrder(TreeNode* node) {
        if(!node) return;
        inOrder(node->left);
        if(prev && node->val < prev-> val) {
            if(!first) {
                first = prev;
                middle = node;
            }
            else {
                last = node;
            }
        }
        prev = node;
        inOrder(node->right);
    }
    public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        inOrder(root);
        if(first && last) {
            swap(first->val,last->val);
        }
        else if(first && middle) {
            swap(first->val,middle->val);
        }
        // TC -> O(N)
        // SC -> O(1) (without ASS)
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
