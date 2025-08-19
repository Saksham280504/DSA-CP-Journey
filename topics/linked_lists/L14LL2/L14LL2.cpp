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

Node* ConvertArrToLL(vector<int>& arr) {
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
        temp=temp->next;
    } 
    cout << endl;
}

Node* DeleteHead(Node* head) {
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

Node* DeleteTail(Node* head) {
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp = head;

    while(temp->next->next!=NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

Node* DeleteKthElement(Node* head, int k) {
    if(head==NULL) return NULL;
    if(k==1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp) {
        cnt++;
        if(cnt==k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node* DeleteElement(Node* head, int el) {
    if(head==NULL) return NULL;
    if(head->data == el) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp) {
        if(temp->data==el) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
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

    vector<int> arr = {5,9,10,12};
    Node* head = ConvertArrToLL(arr);
    printLL(head);

    // Delete Head ELement
    // head = DeleteHead(head);
    // printLL(head);

    // Delete Tail Element
    // head = DeleteTail(head);
    // printLL(head);

    // Delete Kth ELement
    // head = DeleteKthElement(head, 5);
    // printLL(head);

    // Delete element with value

    head = DeleteElement(head, 17);
    printLL(head);

    return 0;
}
