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
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        queue<pair<Node*,int>> q; // {node,line}
        map<int,int> nodes; // {line,node}
        q.push({root,0});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            nodes[line] = node->data; // Makes sure that always the latest value is taken
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }

        for(auto it: nodes) {
            ans.push_back(it.second);
        }

        return ans;

        // TC ->O(N)
        // SC -> O(N) (map) + O(N) (queue)

        // Just like top-view we can't use recursive solution for bottom view as well.
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
