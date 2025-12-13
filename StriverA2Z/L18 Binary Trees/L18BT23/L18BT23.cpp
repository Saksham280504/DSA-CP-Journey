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

// Iterative approach (level order approach)
// class Solution {
//     public:
//     vector<int> rightSideView(Node* root) {
//         vector<int> ans;
//         if(root==nullptr) return ans;
//         queue<pair<Node*,int>> q; // {node,line}
//         map<int,int> nodes; // {line,node}
//         q.push({root,0});
//         while(!q.empty()) {
//             auto it = q.front();
//             q.pop();
//             Node* node = it.first;
//             int level = it.second;
//             nodes[level] = node->data;

//             // For right side view
//             if(node->left) q.push({node->left,level+1});
//             if(node->right) q.push({node->right,level+1});

//             // For left side view
//             // if(node->right) q.push({node->right,level+1});
//             // if(node->left) q.push({node->left,level+1});
//         }

//         for(auto it: nodes) {
//             ans.push_back(it.second);
//         }
//         return ans;

//         // TC -> O(N)
//         // SC -> O(N) (map) + O(N) (queue) (this can be very high for level-order solution)
//     }
// };

// Recursive approach:
class Solution {
    private:
    void right(Node* node, int level,vector<int>& ans) {
        if(node==nullptr) return;
        if(level==ans.size()) ans.push_back(node->data);
        right(node->right,level+1,ans);
        right(node->left,level+1,ans);
    }
    public:
    vector<int> rightSideView(Node* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        right(root,0,ans);
        return ans;

        // TC -> O(N)
        // SC -> O(Height of tree)
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
