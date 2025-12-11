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
    vector<vector<int>> AllInOne(Node* root) {
        vector<vector<int>> ans;
        Node* node = root;
        if(node==nullptr) return ans;
        stack<pair<Node*,int>> st; // {node,num}
        st.push({node,1});
        vector<int> preOrder;
        vector<int> inOrder;
        vector<int> postOrder;

        while(!st.empty()) {
            if(st.top().second==1){ // Preorder
                int val = (st.top().first)->data;
                preOrder.push_back(val);
                st.top().second++;
                if(st.top().first->left!=nullptr) st.push({st.top().first->left,1});
            }
            else if(st.top().second==2) { // Inorder
                int val = (st.top().first)->data;
                inOrder.push_back(val);
                st.top().second++;
                if(st.top().first->right!=nullptr) st.push({st.top().first->right,1});
            }
            else { // Postorder
                int val = (st.top().first)->data;
                postOrder.push_back(val);
                st.pop();            
            }
        }
        ans.push_back(preOrder);
        ans.push_back(inOrder);
        ans.push_back(postOrder);
        return ans;
    }

    // TC -> O(3N)
    // SC -> O(4N)
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
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution sol;
    vector<vector<int>> ans = sol.AllInOne(root);

    for(auto x : ans) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
