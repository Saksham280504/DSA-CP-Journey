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
    Node* builder(int& pointer, vector<int>& preorder, long bound) {
        if(pointer==preorder.size() || preorder[pointer] > bound) return nullptr;
        Node* node = new Node(preorder[pointer]);
        pointer++;
        node->left = builder(pointer,preorder,node->data);
        node->right = builder(pointer,preorder,bound);
        return node;
    }
    public:
    Node* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return nullptr;
        int pointer = 0;
        long bound = LONG_MAX;
        return builder(pointer,preorder,bound);

        // TC -> O(N)
        // SC -> O(H) (auxillary stack space)
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
