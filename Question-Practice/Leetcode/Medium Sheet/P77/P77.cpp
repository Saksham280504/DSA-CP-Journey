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

    // Inorder tells us about the split for the left and right sub binary trees. {left,root,right}
    // Preorder tells us about the index of each node. {root,left,right}
    private:
    int preIndex = 0;
    unordered_map<int,int> mpp;
    TreeNode* letsBuild(vector<int>& preorder, int left, int right) {
        if(left>right) return nullptr;
        int rootVal = preorder[preIndex++];
        int inIndex = mpp[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        root->left = letsBuild(preorder,left,inIndex-1);
        root->right = letsBuild(preorder,inIndex+1,right);
        return root;
    }
    
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++) {
            mpp[inorder[i]] = i;
        }

        return letsBuild(preorder,0,n-1);
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
