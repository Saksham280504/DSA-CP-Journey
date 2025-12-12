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
    bool isSameTree(Node* p, Node* q) {
        if(p==nullptr || q==nullptr) return (p==q);
        return (p->data==q->data) && (isSameTree(p->left,q->left)) && (isSameTree(p->right,q->right));

        // TC -> O(N)
        // SC -> O(N) (auxillary recursive stack space)
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
