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
    void right(vector<int>& ans, int level, TreeNode* node) {
        if(!node) return;
        if(ans.size()==level) ans.push_back(node->val);
        right(ans,level+1,node->right);
        right(ans,level+1,node->left);
    }
    public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        right(ans,0,root);
        return ans;
    }

    // TC -> O(N)
    // SC -> O(Height of Tree)
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
