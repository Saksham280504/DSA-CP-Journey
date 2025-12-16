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
    Node* prev;
    Node* first;
    Node* middle;
    Node* last;
    private:
    void inOrder(Node* node) {
        if(!node) return;
        inOrder(node->left);
        if(prev && node->data<prev->data) {
            if(!first) {
                first = prev;
                middle = node;
            }
            else {
                last = node;
            }
        }
        prev = node;
        inOrder(node->right);
    }
    public:
    void recoverTree(Node* root) {
        Node* prev = new Node(INT_MIN);
        inOrder(root);
        if(first && last) {
            swap(first->data,last->data);
        }
        else if(first && middle) {
            swap(first->data,middle->data);
        }

        // TC -> O(N)
        // SC -> O(1) (without ASS)
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
