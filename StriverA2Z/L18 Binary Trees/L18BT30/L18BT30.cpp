#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Node{
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
    void parentMark(Node* node, unordered_map<Node*, Node*>& parent) {
        if(!node) return;
        if(node->left) {
            parent[node->left] = node;
            parentMark(node->left,parent);
        }
        if(node->right) {
            parent[node->right] = node;
            parentMark(node->right,parent);
        }
    }
    Node* FindLocation(Node* node, int target) {
        if(!node) return nullptr;
        if(node->data==target) return node;
        Node* lnode = FindLocation(node->left,target);
        Node* rnode = FindLocation(node->right,target);
        if(!lnode) return rnode;
        return lnode;
    }
    public:
    int minTime(Node* root, int target) {
        unordered_map<Node*,Node*> parent;
        parentMark(root,parent);
        Node* location = FindLocation(root,target); 
        queue<Node*> q;
        unordered_map<Node*, bool> vis;
        q.push(location);
        vis[location] = true;
        int mini = 0;
        while(!q.empty()) { // Every time the while loop iterates we reach a new set of neighbours
            bool burned = false; // We are not sure that whether there will be a spread of fire beyond these neighbours, so if !burned after checking every neighbour, then there is no need to do a mini++.
            int size = q.size();
            for(int i=0; i<size; i++) { // In one iteration of while loop we go on all the neighbours and see if extension of fire is possible or not
                Node* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]) {
                    burned = true;
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]) {
                    burned = true;
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]]) {
                    burned = true;
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
            if(burned) mini++;
        }

        return mini;

        // TC -> O(N) (parent mark) + O(N) (location) + O(N) (burning)
        // SC -> O(N)
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
