#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode() {
        val = 0;
        next = nullptr;
    }
    ListNode(int data) {
        val = data;
        next = nullptr;
    }
    ListNode(int data, ListNode* nextNode) {
        val = data;
        next = nextNode;
    }
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for(int i=1; i<left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        for(int i=0; i<(right-left); i++) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
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
