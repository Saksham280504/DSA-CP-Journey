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
    Node* TreeBuild(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int,int>& inMap) {
        if(postStart>postEnd || inStart>inEnd) return nullptr;
        Node* root = new Node(postorder[postEnd]);
        int inRoot = inMap[root->data];
        int numsLeft = inRoot-inStart;
        root->left = TreeBuild(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsLeft-1,inMap);
        root->right = TreeBuild(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,inMap);
        return root;
    }
    public:
    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> inMap;
        for(int i=0; i<n; i++) {
            inMap[inorder[i]] = i;
        }
        Node* root = TreeBuild(inorder,0,n-1,postorder,0,n-1,inMap);
        return root;

        // TC -> O(N)
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
