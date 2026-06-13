#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Node {
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int data) {
        val = data;
        next = prev = nullptr;
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
    int n;
    cin >> n;
    Node* root = new Node(1);
    Node* previous = root;
    for(int i=2; i<=n; i++) {
        Node* node = new Node(i);
        previous->next = node;
        node->prev = previous;
        previous = node;
    }
    previous->next = root;
    root->prev = previous;
    int removes = 0;
    if(n>1) {
        root = root->next;
        previous = previous->next;
    }
    while(removes<n) {
        cout << root->val << " ";
        removes++;
        previous->next = root->next;
        root->prev = nullptr;
        root = root->next;
        root->prev = previous;
        previous = previous->next;
        root = root->next;
    }

    return 0;
}
