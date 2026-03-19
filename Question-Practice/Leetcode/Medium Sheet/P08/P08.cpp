#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        priority_queue<pair<int,TreeNode*>, vector<pair<int,TreeNode*>>, greater<>> pq;
        pq.push({1,root});
        set<int> st;
        int maxSum = INT_MIN;
        int maxLevel = -1;
        int sum = 0;
        while(!pq.empty()) {
            auto [level, node] = pq.top();
            pq.pop();
            if(st.find(level)==st.end()) sum = node->val;
            else sum += node->val;
            if(maxSum<sum) {
                maxSum = sum;
                maxLevel = level;
            }
            st.insert(level);
            if(node->left!=nullptr) pq.push({level+1,node->left});
            if(node->right!=nullptr) pq.push({level+1,node->right});
        }

        return maxLevel;
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
