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
    Node* TreeBuild(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>& inMap) {
        if(preStart>preEnd || inStart > inEnd) return nullptr;
        Node* root = new Node(preorder[preStart]);
        int inRoot = inMap[root->data];
        int numsLeft = inRoot-inStart;
        root->left = TreeBuild(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
        root->right = TreeBuild(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
        return root;
    }
    public:
    Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap; // {node,index}
        int n = inorder.size();
        for(int i=0; i<n; i++) {
            inMap[inorder[i]] = i;
        }
        Node* root = TreeBuild(preorder,0,n-1,inorder,0,n-1,inMap);
        return root;
    }

    // TC -> O(N)
    // SC -> O(N)
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
