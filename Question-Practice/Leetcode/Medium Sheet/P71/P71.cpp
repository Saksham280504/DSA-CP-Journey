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
private:
    vector<TreeNode*> generate(int start, int end) {
        if(start > end) return {NULL}; // We have reached a nullptr node

        vector<TreeNode*> ans;
        for(int i=start; i<=end; i++) { // i -> root of the BST
            vector<TreeNode*> left = generate(start,i-1);
            vector<TreeNode*> right = generate(i+1,end);
            for(auto l: left) {
                for(auto r: right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
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
