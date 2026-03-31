#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> st;
        int prefixSum = 0;
        int cnt = 0;
        for(int x: nums) {
            prefixSum += x;
            if(st.count(prefixSum-target)) {
                cnt++;
                st.clear();
                prefixSum = 0;
            }
            st.insert(prefixSum);
        }

        return cnt;
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
