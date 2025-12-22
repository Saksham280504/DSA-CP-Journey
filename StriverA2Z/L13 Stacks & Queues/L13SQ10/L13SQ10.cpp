#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n,-1);
        vector<int> temp(m,-1);
        stack<int> st;
        for(int i=m-1; i>=0; i--) {
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            temp[i] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(nums1[i]==nums2[j]) {
                    ans[i] = temp[j];
                }
            }
        }

        return ans;

        // TC -> O(N*M + 2M)
        // SC -> O(N+M+M)
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
