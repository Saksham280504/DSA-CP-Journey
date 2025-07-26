#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class QueueNode {
    public:
        int val; // Stores the actual value of the node
        QueueNode *next; // Pointer to the next node in the queue

        QueueNode(int data) { // Constructor for QueueNode
            val = data; // Initializes the value with the provided 'data'
            next = nullptr; // Initializes the next pointer to nullptr (indicating no next node yet)
        }
};

QueueNode *Front = nullptr, *Rear = nullptr; // Global Pointers

// Front: This pointer points to the front (or head) of the queue. This is where elements are dequeued (removed).

// Rear: This pointer points to the rear (or tail) of the queue. This is where new elements are enqueued (added).

class Queue {
    public:
        int size = 0; // Stores the current number of elements in the queue

        // Declarations of member functions
        bool Empty();
        void Enqueue(int value);
        void Dequeue();
        int Peek();
};

// Implementation of Member Functions (Outside the Class):

// The functions are defined using the Queue :: scope resolution operator, indicating they are members of the Queue class.

bool Queue :: Empty()
 {
    return Front == nullptr; // Returns true if the queue is empty (Front points to nothing)
 }
int Queue :: Peek()
 {
    if(Empty()) { // Checks if the queue is empty using the Empty() method 
        cout << "Queue is Empty" << endl; // Informative message
        return -1; // Return -1 to indicate an error (no element to peek)
    }
    else return Front->val; // Return the value of the front element without removing it
 }

 void Queue :: Enqueue(int value) {
    QueueNode * Temp;
    Temp = new QueueNode(value); // Create a new node with the given value
    if(Temp == nullptr) // Check if memory allocation failed (new returned nullptr)
    cout << "Memory allocation failed" << endl; // Informative message
    else {
        if(Front==nullptr) { // If the queue is currently empty  
            Front = Temp; // The new node becomes both the front and rear
            Rear = Temp;
        }
        else { // If the queue is not empty
            Rear->next = Temp; // The current rear's 'next' pointer points to the new node
            Rear = Temp; // The new node becomes the new rear
        }
        cout << value << " Inserted into Queue" << endl; // Informative message
        size++; // Increment the queue size
    }
 }

 void Queue :: Dequeue() {
    if (Front == nullptr) // Check if the queue is empty
        cout << "Queue is Empty" << endl; // Informative message
    else
    { 
        cout<< Front->val <<" Removed From Queue" <<endl; // Informative message
        QueueNode *Temp = Front; // Create a temperory pointer to the node being removed (to delete it later).
        Front = Front->next; // Move the front pointer to the next node (effectively removing the old front)
        delete Temp; // Free the memory allocated for the removed node
        size--; // Decrement the queue size

        if(Front == nullptr) Rear = nullptr; // If after dequeuing, Front becomes nullptr, it means the queue is now empty.
        // In this case, Rear should also be set to nullptr.
    }  
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
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout<<"The size of the Queue is "<<Q.size<<endl;
    cout<<"The Peek element of the Queue is "<<Q.Peek()<<endl;

    return 0;
}
