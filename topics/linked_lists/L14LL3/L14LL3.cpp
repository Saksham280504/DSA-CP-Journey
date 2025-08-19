#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1) {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* ConvertArrtoLL(vector<int>& arr) {
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<n; i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

Node* insertHead(Node* head, int val) {
    if(head==NULL) return new Node(val);
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertLast(Node* head, int val) {
    if(head==NULL) return new Node(val);
    Node* mover = head;
    while(mover->next != NULL) mover = mover->next;
    Node* temp = new Node(val);
    mover->next = temp;
    return head;
}

Node* insertKthElement(Node* head, int k, int val) {
    if(head==NULL) {
        if(k==1) return new Node(val);
        else return NULL;
    }
    if(k==1) {
        Node* temp = new Node(val,head);
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp) {
        cnt++;
        if(cnt==k-1) {
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int val, int el) {
    if(head==NULL) return NULL;
    if(head->data == val) return new Node(el,head);
    Node* temp = head;
    while(temp->next != NULL) {
        if(temp->next->data == val) {
            Node* x = new Node(el,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }

    return head;
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

    vector<int> arr = {5,12,8,7};
    Node* head = ConvertArrtoLL(arr);
    printLL(head);
    // head = insertHead(head,1);
    // printLL(head);
    // head = insertLast(head,10);
    // printLL(head);
    // head = insertKthElement(head,5,5);
    // printLL(head);
    head = insertBeforeValue(head,19,1);
    printLL(head);

    return 0;
}
