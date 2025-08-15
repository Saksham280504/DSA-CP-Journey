#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Node  {
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }

    // The bottom 2 public statements are known as constructors. Constructors are special type of memory functions which we use to initialize the objects of a class. 

    // In struct, we don't get the Object Oriented Programming Concepts like abstraction, encapsulation, inheritance etc., but if we want to have OOPs in these kind of data-structures (especially in industry) we should use class rather than struct.
};

Node* convertArr2LL(vector<int>& arr) {
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

int lengthOfLL(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while(temp) {
        // cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }

    return cnt;
}

int checkIfPresent(Node* head, int val) {
    Node* temp = head;
    int doesExist = 0;
    while(temp) {
        if(temp->data == val) {
        doesExist = 1;
        return doesExist;
        }
        temp = temp->next;
    }
    
    return doesExist;
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

    // LinkedList is a collection of elements of similar datatype, and elements are not stored at contiguous locations. Also, the size of the linkedList is not fixed, it can be modified.

    // The first element of the linkedList is known as Head of the LinkedList.

    // The last element of the linkedList is known as Tail of the LinkedList.

    // Every element of the linkedList contains a value, and the location of the next element. So, in order to traverse the entire linkedList we use the next-pointer system.

    // The last element contains null/nullptr in next.
    
    // LinkedList is used in the creation of stacks & queues.
    // In real life, linkedList is used in browser.

    vector<int> arr = {12,5,8,7};
    // Node* y = new Node(arr[0], nullptr);
    // cout << y;

    // Node y = Node(arr[0],nullptr);
    // cout << y.data; // 2
    // cout << y.next; // 0 (nullptr)

    // Node* y = new Node(arr[0],nullptr);
    // cout << y->data;

    Node* head = convertArr2LL(arr);

    // cout << head->data;

    // Node* temp = head;

    // while(temp) {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }

    // int length = lengthOfLL(head);
    // cout << length << endl;

    int val = 14;
    int existOrnot = checkIfPresent(head, val);
    if(existOrnot) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;

}
