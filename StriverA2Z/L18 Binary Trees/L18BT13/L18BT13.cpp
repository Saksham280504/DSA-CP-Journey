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
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    public:
    int MaxDepth1(Node* node) {
        if(node==nullptr) return 0;
        return 1 + max(MaxDepth1(node->left),MaxDepth1(node->right)); // If there exists a valid node, then that has height of atleast 1

        // TC -> O(N)
        // SC -> O(Height) -> O(N) (worst case->skew DS)
    }

    int MaxDepth2(Node* node) {
        if(node==nullptr) return 1;
        queue<Node*> q;
        q.push(node);
        int height = 0;
        while(!q.empty()) {
            height++; // Whenever a while loop iteration starts running, we reach a new level
            int size = q.size(); // At every new iteration of the while loop, we will have the elements of the new level only.
            for(int i=0; i<size; i++) {
                Node* temp = q.front();
                q.pop();
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
        }

        return height;

        // TC ->O(N)
        // SC ->O(N)
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

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    int depth1 = sol.MaxDepth1(root);
    cout << depth1 << endl;

    int depth2 = sol.MaxDepth2(root);
    cout << depth2 << endl;

    return 0;
}
