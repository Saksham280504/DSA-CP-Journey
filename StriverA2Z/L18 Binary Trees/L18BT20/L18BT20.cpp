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
    vector<vector<int>> verticalTraversal(Node* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<pair<Node* ,pair<int,int>>> q; // {node,vertical,level}
        map<int,map<int,multiset<int>>> nodes; // {vertical,level,nodes}
        q.push({root,{0,0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            nodes[vertical][level].insert(node->data);
            if(node->left) q.push({node->left,{vertical-1,level+1}});
            if(node->right) q.push({node->right,{vertical+1,level+1}});
        }

        for(auto p: nodes) { // {vertical,level,nodes} -> We traverse in ascending order of verticals
            vector<int> col; // This will contain the nodes of one vertical from top to bottom
            for(auto q: p.second) { // {level,nodes} -> we traverse in ascending order of levels
                col.insert(col.end(),q.second.begin(),q.second.end()); // For every level, we will insert at the end of the col all the elements of nodes[vertical][level] for that particular vertical and level
            }
            ans.push_back(col);
        }

        return ans;

        // TC -> O(NlogN)
        // SC -> O(N) (map) + O(N) (queue)
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
