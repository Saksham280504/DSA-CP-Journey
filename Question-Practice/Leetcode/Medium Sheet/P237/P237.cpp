#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=2*n-1; i>=0; i--) {
            while(!st.empty() && st.top()<=nums[i]) st.pop();
            // Now either the stack is empty (no element is larger than nums[i] in the right), or st.top() > nums[i], where st.top() is the smallest element in stack from i+1 to 2*n-1 that is greater than nums[i]
            if(i<n) {
                ans[i] = st.empty() ? -1: st.top();
            }
            st.push(nums[i]); // Now the stack contains elements from index i to 2*n-1 with st.top() = nums[i], and the elements increase strictly as we go from top(i) to bottom (2*n-1)
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