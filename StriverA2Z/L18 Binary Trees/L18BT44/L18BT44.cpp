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
    Node* findMax(Node* node) {
        while(node->right) node = node->right;
        return node;
    }
    private:
    Node* deleteFunc(Node* node) {
        if(!node->left) return node->right;
        else if(!node->right) return node->left;
        Node* maxRight = findMax(node->left);
        maxRight->right = node->right;
        return node->left;
    }
    public:
    Node* deleteNode(Node* root, int key) {
        if(!root) return root;
        if(root->data==key) {
            return deleteFunc(root);
        }
        Node* node = root;
        while(node) {
            if(node->data>key) {
                if(node->left && node->left->data==key) {
                    node->left = deleteFunc(node->left);
                }
                else node = node->left;
            }   
            else {
                if(node->right && node->right->data==key) {
                    node->right = deleteFunc(node->right);
                }
                else node = node->right;
            }
        }

        return root;
    }

    // TC -> O(log2N)
    // SC -> O(1)
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
