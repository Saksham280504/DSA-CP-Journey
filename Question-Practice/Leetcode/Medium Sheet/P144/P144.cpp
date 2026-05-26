#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;

        for(int i=0; i<n; i++) {
            while(!result.empty() && result.back()>nums[i] && (n-i)>(k-result.size())) {
                result.pop_back();
            }

            if(result.size()<k) result.push_back(nums[i]);
        }

        return result;

        // TC -> O(N)
        // SC -> O(K)
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
