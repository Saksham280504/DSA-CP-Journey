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
vector<int> preOrderTraversal(Node* root) { // {root,left,right}
    vector<int> ans;
    if(root==nullptr) return ans;
    stack<Node*> st;
    st.push(root); // LIFO (This means we will first push right and then left, so that at top we get left first and then right)

    while(!st.empty()) {
        Node* node = st.top();
        st.pop();
        ans.push_back(node->data);
        if(node->right!=nullptr) st.push(node->right);
        if(node->left!=nullptr) st.push(node->left);
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

    return 0;
}
