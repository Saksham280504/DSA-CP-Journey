#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
class Queue {
    int * arr;
    int start, end, currSize, maxSize;

    public:
        Queue() {
            arr = new int[16];
            start = -1;
            end = -1;
            currSize = 0;
        }

        Queue(int maxSize) {
            ( * this).maxSize = maxSize;
            arr = new int[maxSize];
            start = -1;
            end = -1;
            currSize = 0;
        }

        void push(int newElement) {
            if(currSize == maxSize) {
                cout << "Queue is full\nExiting..." << endl;
                exit(1);
            }
            if (end==-1) {
                start = 0;
                end = 0;
            } else end = (end+1)%maxSize;
            arr[end] = newElement;
            cout << "The element pushed is " << newElement << endl;
            currSize++;
        }

        int pop() {
            if(start==-1) {
                cout << "Queue Empty\nExiting..." << endl;
            }
            int popped = arr[start];
            if(currSize==1) {
                start = -1;
                end = -1;
            } else start = (start+1)%maxSize;
            currSize--;
            return popped;
        }

        int top() {
            if(start==-1) {
                cout << "Queue is Empty" << endl;
                exit(1);
            }
            return arr[start];
        }

        int size() {
            return currSize;
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

    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
   cout << "The peak of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peak of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;  

    return 0;
}


// TC -> O(1)
// SC -> O(N)