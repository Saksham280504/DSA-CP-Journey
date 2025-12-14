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
    int findCeil(Node* root, int key) {
        if(!root) return -1;
        Node* node = root;
        int ceil = -1;
        while(node) {
            if(node->data==key) {
                ceil = key;
                break;
            }
            if(node->data>key) {
                ceil = node->data;
                node = node->left;
            }
            else node = node->right;
        }

        return ceil;

        // TC -> O(log2N)
        // SC -> O(1)
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
