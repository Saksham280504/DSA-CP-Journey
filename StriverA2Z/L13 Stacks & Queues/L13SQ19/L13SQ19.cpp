#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()]>heights[i]) {
                int elIndex  = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea,(nse-pse-1)*heights[elIndex]);
            }
            st.push(i);
        }
        while(!st.empty()) {
                int elIndex  = st.top();
                st.pop();
                int nse = n;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea,(nse-pse-1)*heights[elIndex]);
        }

        return maxArea;

        // TC -> O(N+N)
        // SC -> O(N)
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
