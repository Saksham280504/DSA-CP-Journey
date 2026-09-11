#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = high;
        auto isSplitPossible = [&] (int penalty) {
            int ops = 0;
            for(int x: nums) {
                ops += (x-1)/penalty;
                if(ops>maxOperations) return false;
            }
            return true;
        };
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(isSplitPossible(mid)) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
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
