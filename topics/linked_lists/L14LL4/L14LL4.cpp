#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* ConvertArrToDoublyLL(vector<int>& arr) {
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<n; i++) {
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void PrintLL(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    vector<int> arr = {1,2,3,4,5};
    Node* head = ConvertArrToDoublyLL(arr);
    PrintLL(head);

    return 0;
}
