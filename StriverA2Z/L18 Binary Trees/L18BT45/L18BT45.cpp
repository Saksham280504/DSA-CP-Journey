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
    int kthSmallest(Node* root, int k) {
        int ans = -1;
        if(!root) return ans;
        Node* curr = root;
        int cnt = 0;
        while(curr) {
            if(!curr->left) {
                cnt++;
                if(cnt==k) ans = curr->data; // You can't break as morris traversal will need to complete it's traversal in order to restore the tree completely.
                curr = curr->right;
            }
            else {
                Node* prev = curr->left;
                while(prev->right && prev->right!=curr) prev = prev->right;
                if(!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = nullptr;
                    cnt++;
                    if(cnt==k) ans = curr->data;
                    curr = curr->right;
                }
            } 
        }

        return ans;

        // TC -> O(N)
        // SC -> O(1)

        // If we were asked kth largest, then we first find out the number of nodes in the tree (say N), and then find out (N-k+1)th smallest element.
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
