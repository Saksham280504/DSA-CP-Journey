#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int subsets = 1<<n;

        for(int num = 0; num<subsets; num++) {
            vector<int> subset;
            for(int i=0; i<n; i++) {
                if(num&(1<<i)) {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }

        return ans;

        // TC -> O(N*(2^N))
        // SC -> O((2^N)*N)
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
