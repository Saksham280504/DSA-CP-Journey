#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Node{
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
    int Leftheight(Node* node) {
        if(!node) return 0;
        int lh = Leftheight(node->left);
        return lh+1;
    }
    int rightheight(Node* node) {
        if(!node) return 0;
        int rh = rightheight(node->right);
        return rh+1;
    }
    public:
    int countNodes(Node* root) {
        if(!root) return 0;
        int lh = Leftheight(root);
        int rh = rightheight(root);
        if(lh==rh) return (1<<lh)-1; // Apparently (1<<lh) == 2^lh, since we are given a complete tree therefore it will be for sure that in the last level too if some nodes are missing, the present nodes will be to as left as possible, thus if there is even one node at the bottom level it will be for sure to the extreme left and it will from left to right thus if incase the bottom level has a node to the extreme right then that means that the tree is completely filled.
        return 1 + countNodes(root->left) + countNodes(root->right); // If the tree is not completely filled you have to calculate the number of nodes on both left and right seperately.

        // TC -> O(height of tree^2) -> O((logN)^2)
        // SC -> O(logN) // For a complete binary tree, the height of tree = logN
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
