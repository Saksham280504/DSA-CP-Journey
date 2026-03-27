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

// This approach is wrong, because you are looking for smallest descendent here and not for the minimum and maximum ancestor, this will not work!!
// class Solution {
// private:
//     int minChild(TreeNode* node, int& maxDiff) {
//         if(node==nullptr) return INT_MIN;
//         int minLeft = minChild(node->left,maxDiff);
//         int minRight = minChild(node->right,maxDiff);
//         if(minLeft==INT_MIN) minLeft = node->val;
//         if(minRight==INT_MIN) minRight = node->val;
//         maxDiff = max(maxDiff, max(abs((node->val)-minLeft),abs((node->val)-minRight)));
//         int miniChild = min(node->val,min(minLeft,minRight));
//         return miniChild;
//     }
// public:
//     int maxAncestorDiff(TreeNode* root) {
//         int maxDiff = INT_MIN;
//         int minLeft = minChild(root->left,maxDiff);
//         int minRight = minChild(root->right,maxDiff);
//         if(minLeft==INT_MIN) minLeft = root->val;
//         if(minRight==INT_MIN) minRight = root->val;
//         maxDiff = max(maxDiff, max(abs((root->val)-minLeft),abs((root->val)-minRight)));
//         return maxDiff;
//     }
// };


// This is the correct solution, where at every node you check for what maximum and minimum ancestor you have encountered and then find out the difference.
class Solution {
    int dfs(TreeNode* node, int maxi, int mini) {
        if(node==nullptr) return maxi-mini;
        mini = min(mini,node->val);
        maxi = max(maxi,node->val);
        int left = dfs(node->left,maxi,mini);
        int right = dfs(node->right,maxi,mini);
        return max(left,right);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root,root->val,root->val);
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
