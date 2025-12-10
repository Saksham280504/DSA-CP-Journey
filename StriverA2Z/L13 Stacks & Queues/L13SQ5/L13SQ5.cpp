#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

struct stackNode {
    int data; // Stores the actual value of the node
    stackNode * next; // Pointer to the next node in the stack (points downwards)
    stackNode(int d) { // Constructor of stackNode
        data = d; // Initializes the data with the provided value 'd'
        next = NULL; // Initializes the next pointer to NULL (indicating end of a chain or no next element yet)
    }
};

// This struct defines the basic building block of your linked list, which will represent the stack.

// data: Holds the integer value of an element pushed onto the stack.

// next: A pointer that points to the next stackNode in the sequence. In a stack implemented with a linked list, top points to the the last pushed element, and next pointers point towards older elements, forming a chain.

// Constructor stackNode(int d): This is a simple constructor that takes an integer d and initializes the node's data to d and its next pointer to NULL.

struct MyStack {
    stackNode * top; // Pointer to the topmost element of the stack
    int size; // Stores the current number of elements in the stack
    MyStack() { // Constructor for MyStack
        top = NULL; // Initializes an empty stack: top points to nothing
        size = 0; // Initial size is 0
    }

    // Pushes an element onto the top of the stack
    void stackPush(int x) {
        stackNode * element = new stackNode(x); // Create a new node with the data 'x'
        element -> next = top; // New node's 'next' points to the current top
        top = element; // The new node becomes the new top
        cout << "Element pushed" << endl; // Informative message
        size++; // Increment stack size
    }

    // Removes and returns the top element from the stack
    int stackPop() {
        if(top==NULL) { // Checks if the stack is empty
            return -1; // Return -1 to indicate error (empty stack)
        }
        int topData = top -> data; // Store the data of the current top node 
        stackNode * temp = top; // Create a temporary pointer to the current top node (to delete it later)
        top = top -> next; // Move top pointer to the next node (effectively removing the old top)
        delete temp; // Free the memory for the old top node
        size--; // Decrement in stack size
        return topData; // Return the data of the popped element
    }

    // Returns the current number of elements in the stack
    int stackSize() {
        return size;
    }

    // Checks if the stack is empty
    bool IsStackEmpty() {
        return top == NULL; // Returns true if top is NULL, false otherwise
    }

    // Returns the top element without removing it
    int stackPeek() {
        if(top==NULL) return -1; // Returns -1 if the stack is empty
        return top -> data; // Return data of the top element
    }

    // Prints all elements in the stack from top to bottom
    void printStack() {
        stackNode * current = top; // Start from the top
        while (current!=NULL) { // Iterate until the end of the linked list
            cout << current -> data << " "; // Print data
            current = current -> next; // Move to the next node
        }
        cout << endl; // Add a newline after printing the stack
    }
};

// top: This pointer is critical. It al
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    MyStack s; // Create an instance of MyStack

    s.stackPush(10); // Push 10

    cout << "Element popped: " << s.stackPop() << "\n"; // Pop 10
    cout << "Stack size: " << s.stackSize() << "\n"; // Should be 0
    cout <<"Stack empty or not? "<<s.IsStackEmpty() <<"\n"; // Should be true
    cout << "stack's top element: " << s.stackPeek() << "\n"; // Should return -1 (empty)

    // One more example
    s.stackPush(5);    
    s.stackPush(15);    
    s.stackPush(25);    
    s.stackPush(35);    
    cout << "Stack Elements: ";
    s.printStack(); // Should print 35 25 15 5

    cout << "Popped: " << s.stackPop() << endl; // Popped: 35

    cout << "Stack elements: ";
    s.printStack(); // Should print 25 15 5


    return 0;
}
