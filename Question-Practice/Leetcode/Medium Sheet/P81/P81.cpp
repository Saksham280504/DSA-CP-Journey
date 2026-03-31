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
        left = nullptr;
        right = nullptr;
    }
};

// DFS Solution -> TC -> O(H)

class Solution {
private:
    void dfs(TreeNode* node, int val, int depth, int currDepth) {
        if(node==nullptr) return;
        if(currDepth==depth-1) {
            TreeNode* oldLeft = node->left;
            TreeNode* oldRight = node->right;
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            node->left->left = oldLeft;
            node->right->right = oldRight;
            return;
        }
        dfs(node->left,val,depth,currDepth+1);
        dfs(node->right,val,depth,currDepth+1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        dfs(root,val,depth,1);
        return root;
    }
};

// BFS Solution -> TC -> O(N)

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        int currDepth = 1;

        while(!q.empty()) {
            int size = q.size();
            if(currDepth == depth-1) {
                while(size--) {
                    TreeNode* node = q.front();
                    q.pop();
                    TreeNode* oldLeft = node->left;
                    TreeNode* oldRight = node->right;
                    node->left = new TreeNode(val);
                    node->right = new TreeNode(val);
                    node->left->left = oldLeft;
                    node->right->right = oldRight;
                }
                break;
            }

            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            currDepth++;
        }

        return root;
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
