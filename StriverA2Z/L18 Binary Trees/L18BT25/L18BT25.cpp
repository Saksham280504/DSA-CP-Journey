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

// Root-to-leaf path
// class Solution {
//     private:
//     void rootCheck(Node* node,vector<vector<int>>& ans, vector<int>& path) {
//         if(!node) return;
//         path.push_back(node->data);
//         if(!node->left && !node->right) {
//             ans.push_back(path);
//             path.pop_back();
//             return;
//         }
//         rootCheck(node->left,ans,path);
//         rootCheck(node->right,ans,path);
//         path.pop_back();
//     }
//     public:
//     vector<vector<int>> Paths(Node* root) {
//         vector<vector<int>> ans;
//         vector<int> path;
//         if(!root) return ans;
//         rootCheck(root,ans,path);
//         return ans;
//     }
// };

//Root-to-node path

class Solution {
    private:
    bool pathCheck(Node* node, vector<int>& path, int dest) {
        if(!node) return false;
        path.push_back(node->data);
        if(node->data==dest) return true;
        if(pathCheck(node->left,path,dest)) return true;
        else if(pathCheck(node->right,path,dest)) return true;
        path.pop_back();
        return false;
    }
    public:
    vector<int> pathToNode(Node* root, int dest) {
        vector<int> ans;
        if(!root) return ans;
        pathCheck(root,ans,dest);
        return ans;
    }

    // TC ->O(N)
    // SC ->O(Height of tree)
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
