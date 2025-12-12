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
    public:
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<Node*> q;
        bool LeftToRight = true;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp(size);
            for(int i=0; i<size; i++) {
                Node* node = q.front();
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                int index = (LeftToRight) ? i : size-1-i; // Here is where we save the time of reversing the array at last by using simple logic
                temp[index] = node->data;
            }
            LeftToRight = !LeftToRight;
            ans.push_back(temp);
        }

        return ans;

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
