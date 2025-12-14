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
    public:
    Node* insertIntoBST(Node* root, int val) {
        if(!root) return new Node(val);
        Node* node = root;
        while(true) {
            if(node->data<val) {
                if(node->right) node = node->right;
                else {
                    node->right = new Node(val);
                    break;
                }
            }
            else {
                if(node->left) node = node->left;
                else {
                    node->left = new Node(val);
                    break;
                }
            }
        }
        return root;
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
