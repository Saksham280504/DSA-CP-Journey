#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while(curr != nullptr) {
            if(curr->child != nullptr) {
                Node* NextNode = curr->next;
                Node* childNode = curr->child;
                while(childNode->next != nullptr) {
                    childNode = childNode->next;
                }
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;
                childNode->next = NextNode;
                if(NextNode) NextNode->prev = childNode;
            }
            curr = curr->next;
        }
        return head;
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
