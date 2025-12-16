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

class BSTIterator {
    stack<Node*> st;
    private:
    void pushAll(Node* node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }
    public:
    BSTIterator(Node* root) {
        pushAll(root);
    }
    int next() {
        Node* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->data;
    }

    bool hasNext() {
        return !st.empty();
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
