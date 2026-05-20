#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        st.push(INT_MAX);
        // The key greedy idea behind this question is that every number will be multiplied atleast once with another number.
        // In order to get the minimum sum, we need to multiply the smaller number with its smallest larger neighbour.

        int ans = 0;
        for(int x: arr) {
            while(st.top()<=x) {
                int mid = st.top();
                st.pop();
                ans += mid*(min(st.top(),x));
            }
            st.push(x);
        }

        while(st.size()>2) {
            int mid = st.top();
            st.pop();
            ans += mid*st.top();
        }

        return ans;
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

    return 0;
}
