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

// Recursive Solution -> TC -> O(N^2)
// SC -> O(N) (recursive stack space)
class Solution {
private:
    TreeNode* build(int l, int r, vector<int>& nums) {
        if(l>r) return NULL;
        int maxInd = l;
        for(int i=l; i<=r; i++) {
            if(nums[maxInd]<nums[i]) {
                maxInd = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxInd]);
        root->left = build(l,maxInd-1,nums);
        root->right = build(maxInd+1,r,nums);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(0,nums.size()-1,nums);
    }
};

// Monotonic Stack Approach -> TC -> O(N)
// SC -> O(N)

class Solution {
    public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;
        for(int num : nums) {
            TreeNode* curr = new TreeNode(num);
            while(!st.empty() && st.top()->val<num) {
                curr->left = st.top();
                st.pop();
            }

            if(!st.empty()) {
                st.top()->right = curr;
            }

            st.push(curr);
        }

        while(st.size()>1) st.pop();
        return st.top();
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
