#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            while(1<=nums[i] && nums[i]<=n && nums[nums[i]-1]!=nums[i]) swap(nums[nums[i]-1],nums[i]);
        }
        for(int i=0; i<n; i++) {
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
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
