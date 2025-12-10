#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'


// Implementing Stack using Arrays -> Problem with this implementation is that arrays don't have dynamic size, that's why we might take extra space.
class Stack {
    int size;
    int * arr;
    int top;

    public:
        Stack() {
            top = -1;
            size = 1000;
            arr = new int[size];
        }

        void push(int x) {
            top++;
            arr[top] = x;
        }

        int pop() {
            int temp = arr[top];
            top--;
            return temp;
        }

        int Top() {
            return arr[top];
        }

        int Size() {
            return top+1;
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

    // Stack & Queues are Data-Structures that are used to store certain type of Data.

    // Stack follows Last In First Out (LIFO) rule.
    // Queue follows First In First Out (FIFO) rule.

    // We generally use C++ stls for using stacks & Queues, but if someone asks us on how do we implement stacks & Queues, then we can use various methods and that's what we are going to discuss below

    // Implementing Stack using Array:

    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}

// TC -> O(1)
// Sc -> O(N)
