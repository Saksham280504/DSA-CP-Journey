#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'


// Brute-force method

class Stack {
    stack<pair<int,int>> st;

    public:
    void Push(int val) {
        if(st.empty()) {
            st.push({val, val});
        }
        else {
            st.push({val, min(val, st.top().second)});
        }
    }

    int GetMin() {
        if(st.empty()) {
            cout << "Empty Stack" << endl;
            exit(1);
        }
        else {
            return st.top().second;
        }
    }

    int Top() {
        if(st.empty()) {
            cout << "Empty Stack" << endl;
            exit(1);
        }
        else {
            return st.top().first;
        }
    }

    int Pop() {
        int x = st.top().first;
        st.pop();
        return x;
    }
};
// TC -> O(1)
// SC -> O(2*N)

 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here 

    // I have to create a stack that can provide a functionality of GetMin.

    Stack st;

    st.Push(4);
    st.Push(8);
    st.Push(12);
    st.Push(16);

    cout << st.GetMin() << endl;
    cout << st.Top() << endl;
    cout << st.Pop() << endl;
    cout << st.Top() << endl;

    st.Push(2);
    cout << st.GetMin() << endl;
    return 0;
}
