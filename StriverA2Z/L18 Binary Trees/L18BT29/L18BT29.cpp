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
        left = right = nullptr;
    }
};

class Solution {
    private:
    void parentCheck(Node* node, unordered_map<Node*,Node*>& parent) { // This functions helps us in maintaining all the child-parent relations
        if(!node) return;
        if(node->left) {
            parent[node->left] = node;
            parentCheck(node->left,parent);
        }
        if(node->right) {
            parent[node->right] = node;
            parentCheck(node->right,parent);
        }
    }
    public:
    vector<int> distanceK(Node* root, Node* target, int k) {
        vector<int> result;
        if(!root) return result;
        unordered_map<Node*,Node*> parent;
        parentCheck(root,parent);

        queue<Node*> q;
        unordered_map<Node*,bool> vis;
        q.push(target);
        vis[target] = true;
        int dis = 0;
        while(!q.empty()) {
            if(dis==k) break;
            dis++;
            int size = q.size();
            for(int i=0; i<size; i++) {
                Node* node = q.front();
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
            result.push_back(q.front()->data);
            q.pop();
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
