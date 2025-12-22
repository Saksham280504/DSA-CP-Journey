#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=2*n-1; i>=0; i--) {
            while(!st.empty() && st.top()<=nums[i%n]) st.pop();
            if(i<n) {
                ans[i] = st.empty() ? -1: st.top();
            }
            st.push(nums[i%n]);
        }

        return ans;

        // TC -> O(4N)
        // SC -> O(2N + N)
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
