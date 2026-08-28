#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

struct TreeNode {
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
    int cameras = 0;
    int postOrder(TreeNode* node) {
        if(!node) return 2;
        int leftState = postOrder(node->left);
        int rightState = postOrder(node->right);
        if(leftState==0 || rightState==0) {
            cameras++;
            return 1;
        }
        if(leftState==1 || rightState==1) return 2;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(postOrder(root)==0) cameras++;
        return cameras;

        // state 0 -> Camera is needed
        // state 1 -> Camera is present
        // state 2 -> Covered by cameras present at children
        // We greedily place cameras on the parents of the leaf nodes, this makes the highest chances for smallest number of cameras to be placed in the tree.
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
