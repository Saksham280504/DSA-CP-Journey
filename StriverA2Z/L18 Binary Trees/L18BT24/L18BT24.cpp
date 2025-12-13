#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
    private:
    bool isSymmetricHelp(Node* left, Node* right) { // RLRi (for root->left) & RRiL (for root->right)
        if(left==nullptr || right==nullptr) return left==right;
        if(left->data!=right->data) return false;
        return isSymmetricHelp(left->left,right->right) && isSymmetricHelp(left->right,right->left);
    }
    public:
    bool isSymmetric(Node* root) {
        return (root==nullptr || isSymmetricHelp(root->left,root->right));

        // TC -> O(N)
        // SC -> O(N) (worst case) -> skew tree
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
