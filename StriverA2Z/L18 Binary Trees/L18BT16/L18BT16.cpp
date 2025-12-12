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
    private: 
        int maxPath(Node* node, int & maxi) { 
            if(node==nullptr) return 0;
            int leftPath = max(0,maxPath(node->left,maxi)); // If in case for a node, its leftpath is negative, it will not take that path as we are trying to find the maximum sum path
            int rightPath = max(0,maxPath(node->right,maxi)); // If in case for a node, its rightpath is negative, it will not take that path as we are trying to find the maximum sum path
            maxi = max(maxi,node->data+leftPath+rightPath); // This line finds the path sum about every node and then takes the maximum
            return node->data + max(leftPath,rightPath); // This line tells the parent the node which path to take in order to attain the maximum path sum

            // TC -> O(N)
        }
    public:
        int maxPathSum(Node* root) {
        int maxi = INT_MIN;
            maxPath(root,maxi);
            return maxi;
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
