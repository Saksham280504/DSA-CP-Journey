#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Brute-force method
// class MinStack {
//     stack<pair<int,int>> st; // {val, maximum found until now}
// public:
//     MinStack() {
//         // There is nothing needed to be written here, as there is only an empty stack that we already have from definition
//     }
    
//     void push(int val) {
//         if(st.empty()) st.push({val,val});
//         else st.push({val,min(val,st.top().second)});
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }

//     // TC -> O(1)
//     // SC -> O(2N)
// };

// Optimal Approach

class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        long long x = val;
        if(st.empty()) {
            st.push(x);
            mini = min(mini,x);
        }
        else if(x>=mini) st.push(x);
        else {
            st.push(2*x-mini);
            mini = x;
        }
    }

    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();

        if(x<mini) mini = 2*mini-x;
        if(st.empty()) mini = LLONG_MAX; // If after removal stack becomes empty, then mini becomes 1e9 (initial condition restored)
    }

    int top() {
        if(st.empty()) return -1;
        else if(st.top()<mini) return mini;
        return st.top();
    }

    int getMin() {
        return mini;
    }

    // TC -> O(1)
    // SC -> O(N)
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
