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
    }
};

class Solution {
    public:
    void changeTree(Node* node) {
        if(!node) return;
        int sum=0;
        if(node->left) sum += node->left->data;
        if(node->right) sum += node->right->data;
        if(sum>=node->data) node->data = sum;
        else {
            if(node->left) node->left->data = node->data;
            if(node->right) node->right->data = node->data;
        }
        changeTree(node->left);
        changeTree(node->right);

        int total = 0;
        if(node->left) total += node->left->data;
        if(node->right) total += node->right->data;
        if(node->left || node->right) node->data = total;
    }

    // TC->O(N)
    // SC->O(Height of tree)
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
