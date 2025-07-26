#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Stack {
    queue<int> q;
    public:
    void Push(int x) {
        int s = q.size();
        q.push(x);
        for(int i=0; i<s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int Pop() {
        int popped = q.front();
        q.pop();
        return popped;
    }

    int Top() {
        return q.front();
    }

    int Size() {
        return q.size();
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

    Stack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);
    cout << "Top of the stack: " << s.Top() << endl;
    cout << "Size of the stack before removing element: " << s.Size() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "Top of the stack after removing element: " << s.Top() << endl;
    cout << "Size of the stack after removing element: " << s.Size();
    return 0;
}

// TC -> O(N)
// SC -> O(1)

// Here, we solved one problem and i.e. no extra space is now required here.