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
    // true-> before
    // false -> next
    bool reverse;

    private:
    void pushAll(Node* node) {
        while(node) {
            st.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }

    public:
    BSTIterator(Node* root, bool isReverse) {
        bool reverse = isReverse;
        pushAll(root);
    }

    int next() {
        Node* temp = st.top();
        st.pop();
        if(reverse) pushAll(temp->left);
        else pushAll(temp->right);
        return temp->data;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
    public:
    bool findTarget(Node* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i = l.next();
        int j = r.next(); // This is r.before(), we have used one single class for mainitaining code quality
        while(i<j) {
            int sum = i+j;
            if(sum==k) return true;
            else if(sum<k) i = l.next();
            else j = r.next();
        }
        return false;
    }

    // TC -> O(N)
    // SC -> O(2H)
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
