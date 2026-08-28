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
    int moves;
    int postOrder(TreeNode* node) {
        if(!node) return 0;
        int left_balance = postOrder(node->left);
        int right_balance = postOrder(node->right);
        moves += abs(left_balance) + abs(right_balance);
        return node->val - 1 + left_balance + right_balance;
    }
    int distributeCoins(TreeNode* root) {
        moves = 0;
        postOrder(root);
        return moves;
    }

    // For any node T, we define the excess/deficit of coins by balance:- 
    // balance = T->val - 1(because it will hold one coin for itself) + left_balance + right_balance
    // If balance > 0, this means that T can give coins to its parent
    // If balance < 0, this means that T will ask for coins from its parent
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
