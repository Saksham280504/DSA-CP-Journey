#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

#define ll long long

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll max_a = 0;
        ll max_diff = 0;
        ll max_ans = 0;
        for(ll num: nums) {
            // num acts as nums[k]
            max_ans = max(max_ans, max_diff*num);
            // num acts as nums[j]
            max_diff = max(max_diff,max_a-num);
            // num acts as nums[i]
            max_a = max(max_a,num);
        }
        return max_ans;
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
