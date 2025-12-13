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
    int widthOfBinaryTree(Node* root) {
        long long ans = 0;
        if(!root) return ans;
        queue<pair<Node*,long long>> q;
        q.push({root,0});
        while(!q.empty()) { // Every time the while loop iterates we reach a new level
            long long minIndex = q.front().second;
            int size = q.size();
            long long first,last; // Width = last-first+1
            for(int i=0; i<size; i++) {
                long long curi = q.front().second-minIndex;
                Node* node = q.front().first;
                q.pop();
                if(i==0) first = curi;
                if(i==size-1) last = curi;
                if(node->left) q.push({node->left,curi*2+1});
                if(node->right) q.push({node->right,curi*2+2}); 
            }
            ans = max(ans,last-first+1);
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
