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
    bool check(Node* node, long mini, long maxi) {
        if(!node) return true;
        if(mini<node->data && node->data<maxi) {
            return check(node->left,mini,node->data) &&
            check(node->right,node->data,maxi);
        }
        return false;
    }
    public:
    bool isValidBST(Node* root) {
        long mini = LONG_MIN;
        long maxi = LONG_MAX;
        return check(root,mini,maxi);
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
