#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct CompareNode {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;
        for(ListNode* head : lists) {
            if(head!=nullptr) pq.push(head);
        } 
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while(!pq.empty()) {
            auto smallest = pq.top();
            pq.pop();
            temp->next = smallest;
            temp = temp->next;
            if(smallest->next != nullptr) pq.push(smallest->next);
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
