#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

#define ll long long
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        ll low = 1, high = maxSum;
        ll leftLength = index;
        ll rightLength = n-1-index;
        auto computePartSum = [&] (ll count, ll target) {
            if(target>=count) return (count*(2*target+(count-1)*(-1)))/2;
            // target < count
            return (target*(target+1)/2) + (count-target);
        };
        ll ans = high;
        while(low<=high) {
            ll mid = low + (high-low)/2;
            ll sum = mid + computePartSum(leftLength,mid-1) + computePartSum(rightLength,mid-1);
            if(sum<=maxSum) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
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
