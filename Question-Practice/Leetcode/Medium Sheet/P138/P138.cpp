#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        for(int i=1; i<n; i++) {
            ans[i] = ans[i-1]*nums[i-1];
        }
        int suffix = 1;
        for(int i=n-1; i>=0; i--) {
            ans[i] *=suffix;
            suffix *= nums[i];
        }
        return ans;
        // TC -> O(N)
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
