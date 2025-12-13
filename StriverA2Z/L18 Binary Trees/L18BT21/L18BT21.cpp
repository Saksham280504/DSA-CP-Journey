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
    vector<int> topView(Node *root) {
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
            if(nodes.find(line)==nodes.end()) {
                nodes[line] = node->data;
            }
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }

        for(auto it: nodes) {
            ans.push_back(it.second);
        }

        return ans;

        // TC ->O(N)
        // SC -> O(N) (map) + O(N) (queue)

        // Why do we not use recursive approach for this problem?
        // In a recursive traversal we follow DFS approach so there it might happen that we will visit the bottom node first than the top node of the same vertical line, therefore we can't use recursive approach directly whereas we would have to introduce another parameter as height over there which will make sure that the node with the minimum height on a vertical line is finally inserted. It makes the code complex therefore don't use it.
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
