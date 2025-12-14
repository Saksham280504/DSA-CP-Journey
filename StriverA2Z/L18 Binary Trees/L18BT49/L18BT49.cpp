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

// Successor
class Solution {
    private:
    void check(Node* node, Node* x, int& successor) { // Our aim is to find the node such that node->data is just greater than x->data, so I want to reach the smallest node which is greater than x
        if(!node) return;
        if(node->data<=x->data) {
            check(node->right,x,successor);
        }
        else {
            successor = node->data;
            check(node->left,x,successor);
        }
    }
    public:
    int inOrderSuccessor(Node* root, Node* x) {
        int successor = -1;
        check(root,x,successor);
        return successor;
    }
};

// Predecessor
class Solution {
    private:
    void check(Node* node, Node* x, int& predecessor) { // Our aim is to find the node such that node->data is just lesser than x->data, so I want to reach the greatest node which is lesser than x
        if(!node) return;
        if(node->data>=x->data) { 
            check(node->left,x,predecessor);
        }
        else {
            predecessor= node->data;
            check(node->right,x,predecessor);
        }
    }
    public:
    int inOrderPredecessor(Node* root, Node* x) { 
        int predecessor= -1;
        check(root,x,predecessor);
        return predecessor;
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
