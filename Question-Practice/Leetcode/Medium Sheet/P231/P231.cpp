#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(st.empty() || nums[i]<nums[st.top()]) st.push(i);
        }
        int ans = 0;
        for(int j=n-1; j>=0; j--) {
            while(!st.empty() && nums[st.top()]<=nums[j]) {
                ans = max(ans,j-st.top());
                st.pop();
            }
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
