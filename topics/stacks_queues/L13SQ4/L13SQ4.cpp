#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Brute-force approach

// class Queue {
//     stack<int> s1, s2;

//     public: 
//     void Push(int x) {
//         while(s1.size()) {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         cout << "The element pushed is " << x << endl;
//         s1.push(x);
//         while(s2.size()) {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

//     int Pop() {
//         if (s1.empty()) {
//         cout << "Stack is empty";
//         exit(0);
//         }
//         int val = s1.top();
//         s1.pop();
//         return val;
//     }
//     int Top() {
//         if (s1.empty()) {
//         cout << "Stack is empty";
//         exit(0);
//     }
//         return s1.top();
//     }

//     int Size() {
//         return s1.size();
//     }
// };

// TC ->  O(2N)
// SC -> O(2N)

// Better Approach

class Queue {
    stack<int> s1, s2;
    public: 
    void Push(int x) {
        s1.push(x);
    }

    int Pop() {
        if(s1.empty() && s2.empty()) {
            cout << "Empty Queue" << endl;
            exit(1);
        }
        if(!s2.empty()) {
            int val = s2.top();
            s2.pop();
            return val;
        }
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            int val = s2.top();
            s2.pop();
            return val;
        }
    }

    int Top() {
        if(s1.empty() && s2.empty()) {
            cout << "Empty Queue" << endl;
            exit(1);
        }
        if(!s2.empty()) {
            return s2.top();
        }
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    int Size() {
        return (s1.size() + s2.size());
    }
};

// TC -> O(1)
// SC -> O(2N)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    Queue q;
    q.Push(3);
    q.Push(4);
    cout << "The element poped is " << q.Pop() << endl;
    q.Push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.Size() << endl;
    return 0;
}
