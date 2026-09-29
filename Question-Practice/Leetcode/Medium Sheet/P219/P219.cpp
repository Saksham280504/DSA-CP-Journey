#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

#define ll long long
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        ll mod = 1e9+7;
        vector<ll> preSum(n+1,0);
        for(int i=1; i<=n; i++) {
            preSum[i] = preSum[i-1]+(ll)nums[i-1];
        } 
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()) { // nums[st.top()] < nums[i]
                pse[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()) { // nums[st.top()] < nums[i]
                nse[i] = st.top();
            }
            st.push(i);
        }
        ll max_min_product = 0;
        for(int i=0; i<n; i++) {
            int left = pse[i]+1;
            int right = nse[i]-1;
            ll subArraySum = preSum[right+1]-preSum[left];
            ll currProduct = (ll)nums[i]*subArraySum;
            max_min_product = max(max_min_product,currProduct);
        }
        return max_min_product%mod;
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
