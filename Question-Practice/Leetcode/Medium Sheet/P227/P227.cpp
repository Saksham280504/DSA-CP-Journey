#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class CustomStack {
private:
    vector<int> st; // To simulate the elements stored in stack
    vector<int> inc; // Lazy Increment Propogation
    int capacity; // max size of stack
public:
    CustomStack(int maxSize) {
        capacity = maxSize;
    }
    
    void push(int x) {
        if(st.size()<capacity) {
            st.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() {
        if(st.empty()) return -1;
        int idx = st.size()-1;
        int ele = st.back() + inc[idx];
        if(idx>0) {
            inc[idx-1] += inc[idx];
        }
        st.pop_back();
        inc.pop_back();
        return ele;
    }
    
    void increment(int k, int val) {
        if(!st.empty()) {
            int n = st.size();
            inc[min(n,k)-1] += val; // For O(1) TC, we don't add val in all bottom k elements, we only add it in the min(n,k)-1 th index element, when popping out that index element, we check if its not the only element in stack. If not, its value is passed down to the element below it -> inc[idx-1] += inc[idx]
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
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
