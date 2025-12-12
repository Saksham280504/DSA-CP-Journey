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

// class Solution {
//     private:
//     int findDiameter(Node* node, int& dia) { // You have to pass the diameter by reference
//         if(!node) return 0;
//         int lh = findDiameter(node->left,dia);
//         int rh = findDiameter(node->right,dia);
//         dia = max(dia,lh+rh);
//         return 1 +  max(lh,rh);
//     }
//     public:
//     int diameterOfBinaryTree(Node* root) {
//         int dia = 0;
//         findDiameter(root,dia);
//         return dia; 
//         // TC-> O(N)
//        // SC->O(N)
//     }
// };

class Solution {
        private:
        int height(Node* node) {
        if(node==nullptr) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        return 1+max(lh,rh);
    }
    void findDiamter(Node* node, int& dia) {
        if(node==nullptr) return;
        int lh = height(node->left);
        int rh = height(node->right);
        dia = max(dia,lh+rh);
        findDiamter(node->left,dia);
        findDiamter(node->right,dia);
    }
public:
    int diameterOfBinaryTree(Node* root) {
        // Brute-force Approach
        int dia = 0;
        findDiamter(root,dia);
        return dia;

        // TC -> O(N^2)
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

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    int dia = sol.diameterOfBinaryTree(root);
    cout << dia << endl;

    return 0;
}
