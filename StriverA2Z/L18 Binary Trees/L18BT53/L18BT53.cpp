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

class NodeValue { // This class returns {treeSize, maximum node value in that subtree, minimum node value in that subtree}
    public:
    int maxiSize;
    int maxi;
    int mini;
    NodeValue(int maxSize, int maxNodeVal, int minNodeVal) {
        this->maxiSize = maxSize;
        this->maxi = maxNodeVal;
        this->mini = minNodeVal;
    }
};

class Solution {
    private:
    NodeValue largestBSTSubtreeHelper(Node* node) { // We apply a post order traversal that means we always check for left and right side of the node after the left and right have already been visited
        if(!node) return NodeValue(0,INT_MIN,INT_MAX);
        auto left = largestBSTSubtreeHelper(node->left);
        auto right = largestBSTSubtreeHelper(node->right);
        if(left.maxi < node->data && node->data<right.mini) {
            return NodeValue(left.maxiSize+right.maxiSize+1,max(node->data,right.maxi),min(node->data,left.mini));
        }
        return NodeValue(max(left.maxiSize,right.maxiSize),INT_MAX,INT_MIN);
    }
    public:
    int largestBSTSubtree(Node* root) {
        auto nodeVal = largestBSTSubtreeHelper(root);
        return nodeVal.maxiSize;
    }

    // TC -> O(N)
    // SC -> O(1) (ignoring the recursive stack space)
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
