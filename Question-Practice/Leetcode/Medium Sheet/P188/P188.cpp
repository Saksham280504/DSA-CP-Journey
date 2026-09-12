#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    private:
    void dfs(TreeNode* node, unordered_map<TreeNode*,TreeNode*>& parent) {
        if(!node) return;
        if(node->left) {
            parent[node->left] = node;
            dfs(node->left,parent);
        }
        if(node->right) {
            parent[node->right] = node;
            dfs(node->right,parent);
        }
    }
    public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        dfs(root,parent);
        vector<int> result;
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        int dis = 0;
        q.push(target);
        vis[target] = true;
        while(!q.empty()) {
            if(dis==k) break;
            dis++;
            int q_size = q.size();
            while(q_size--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(parent[node] && !vis[parent[node]]) {
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
        }

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
        }

        return result;

        // TC -> O(N) (parent-check) + O(N) (k distance traversal)
        // SC -> O(N) (overall)
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
