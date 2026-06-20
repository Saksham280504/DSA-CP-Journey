#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

template <class T, T (*F)(T,T)>
struct AggStack {
    // stores {element, agg_val_by_applying_F_top_to_bottom}
    stack<pair<T,T>> st;

    void push(T val) {
        if(st.empty()) st.push({val,val});
        else st.push({val, F(val,st.top().second)});
    }

    T top() {
        return st.top().first;
    }

    T pop() {
        T ret = st.top().first;
        st.pop();
        return ret;
    }

    bool empty() {
        return st.empty();
    }

    bool size() {
        return st.size();
    }

    T get() {
        return st.top().second;
    }
};

template <class T, T (*F)(T,T)>
struct AggQueue {
    AggStack<T,F> In, Out;

    void push(T val) {
        In.push(val);
    }

    T pop() {
        if(Out.empty()) {
            while(!In.empty()) {
                Out.push(In.pop());
            }
        }
        return Out.pop();
    }

    T query() {
        if(Out.empty()) return In.get();
        if(In.empty()) return Out.get();
        return F(In.get(), Out.get());
    }
};

ll OR(ll a, ll b) {
    return a | b;
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
    int n,k;
    cin >> n >> k;
    ll x,a,b,c;
    cin >> x >> a >> b >> c;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        if(i==0) arr[i] = x;
        else arr[i] = ((a*(arr[i-1]))+b)%c;
    }

    // This is very very important problem to understand the implementation of sliding window for non-invertible operations.
    // Uptil now we had tried solving invertible operations (+,-,^) in which adding and removing the effect of entering and leaving element is straight forward.

    // Brute force is same, generate all windows, find OR of all windows and then perform xor on all of them, finally output the result -> TC -> O((n-k+1)*(k))
    // But when it comes to solving non-invertible operations with optimal approach, we can't perform insert and delete operations directly. For this we have two approaches -> 1) prefix,suffix approach 2) Aggregarated queue approach

    // Prefix/Suffix approach:
    // What we did here is partitioned the array in partitions of size k. Here for every index i, we calculated its bitwise OR as prefix[i] | suffix[i-k+1] where i belongs to (k-1...n-1) i.e all the ending indices of a window.
    // prefix[i] -> bitwise OR of all the numbers from starting of the partion in which the ith index belongs.
    // suffix[i-k+1] -> this will belong to the previous partition or i-k+1==0 if i==k-1, then suffix[i-k+1] will hold the bitwise OR of all the elements belonging to the previous partition, starting from the last element to the (i-k+1)th index element.
    // prefix[i]|suffix[i-k+1] thus will be equal to -> bitwise or of all the elements of the k-size window ending at index i.
    // vector<ll> prefix(n);
    // for(int i=0; i<n; i++) {
    //     if(i%k==0) prefix[i] = arr[i];
    //     else prefix[i] = (prefix[i-1] | arr[i]);
    // }

    // vector<ll> suffix(n);
    // suffix[n-1] = arr[n-1];
    // for(int i=n-2; i>=0; i--) {
    //     if(i%k==k-1) suffix[i] = arr[i];
    //     else suffix[i] = (suffix[i+1] | arr[i]);
    // }

    // ll total_xor = 0;
    // for(int i=k-1; i<n; i++) {
    //     ll curr = prefix[i] | suffix[i-k+1];
    //     total_xor = (total_xor^curr);
    // }
    // cout << total_xor << endl;

    // TC -> O(N)
    // SC -> O(N)

    // Aggregerated Queue Approach:
    // In this approach, we try to simulate the window as a queue which can perform the insert and delete operations with the help of push() and pop() operations in O(1) time. Along with the that we introduced one more operation as Query operation which gives us the desired non-invertible operation result of that window in O(1) time.
    // For this we work from the very start of the implementation of queue using two stacks. 
    // In this implementation we know we have one IN stack and one OUT stack. Whenver we push into Queue, we push into IN stack, and whenever we pop() from queue, we check if OUT is empty, if yes, move all the elements from IN to OUT. Then perform OUT.POP().
    // What we do here is create aggregrated stacks first, which will store not only pushed val, but also its aggregrated operation value from that element to the bottom of the stack.

    ll total_xor = 0;
    AggQueue<ll, OR> q;
    int i=0;
    for(int j=0; j<n; j++) {
        // Insertion
        q.push(arr[j]);
        // Deletion
        if((j-i+1)<k) continue;
        else {
            ll curr_or = q.query();
            total_xor = (total_xor ^ curr_or);
            q.pop();
            i++;
        }
    }
    cout << total_xor << endl;

    return 0;
}
