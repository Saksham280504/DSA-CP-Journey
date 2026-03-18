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
    long long total = 0;
    long long ans  = 0;
    int mod = 1e9+7;
    
    long long totalS(TreeNode* node) {
        if(node==nullptr) return 0;
        long long left = totalS(node->left);
        long long right = totalS(node->right);
        return left + right + node->val;
    }

    long long solve(TreeNode* node) {
        if(node==nullptr) return 0;
        long long left = solve(node->left);
        long long right = solve(node->right);
        long long subs = left + right + node->val;
        ans = max(ans, subs*(total-subs));
        return subs;
    }
public:
    int maxProduct(TreeNode* root) {
        total = totalS(root);
        solve(root);
        return ans%mod;
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
