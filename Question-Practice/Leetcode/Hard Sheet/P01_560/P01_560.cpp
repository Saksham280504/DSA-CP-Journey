#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        freq[0] = 1; // empty prefix
        int cnt = 0;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(freq.count(sum-k)) cnt += freq[sum-k];
            freq[sum]++;
        }
        return cnt;
        // TC-> O(N)
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
