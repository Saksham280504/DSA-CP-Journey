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
    vector<int> postorderTraversal(Node* root) {
        stack<Node*> st;
        Node* curr = root;
        vector<int> ans;

        while(curr!=nullptr || !st.empty()) {
            if(curr!=nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                Node* temp = st.top()->right;
                if(temp==nullptr) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                    while(!st.empty() && temp==st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->data);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }

        return ans;
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
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->right = new Node(5);
    root->left->left->right->right->right = new Node(6);
    root->right = new Node(7);
    root->right->left = new Node(8);

    Solution sol;
    vector<int> ans = sol.postorderTraversal(root);

    for(auto x: ans) {
        cout << x << " ";
    }


    return 0;
}
