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
    vector<int> inOrderTraversal(Node* root) { // {left,root,right}
        vector<int> ans;
        if(root==nullptr) return ans;
        Node* node = root;
        stack<Node*> st;

        while(true) {
            if(node!=nullptr) {
                st.push(node);
                node = node->left;
            }
            else {
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->data);
                node = node->right;
            }
        }

        return ans;
    }

    // Why did we check for empty stack only when the node==nullptr??
    // When the tree starts inorder traversal, we will notice that once the root is added to the ans array, the stack becomes empty even though we have a new node to check for. So in order to make sure that we still check for that new node, we have made sure to never check for empty set when a new node is there (This is why we have used an infinite loop). Now if the node == nullpointer, then we must check for empty stack because that will happen only when the traversal of the entire tree is finished. So we use that condition is order to get out from the infinite loop as our traversal is finished now.
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
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    Solution sol;
    vector<int> ans = sol.inOrderTraversal(root);

    for(auto x: ans) cout << x << " ";

    return 0;
}
