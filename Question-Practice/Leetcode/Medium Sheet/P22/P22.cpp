#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxLen = 0;
        map<int,int> mpp;
        mpp[0] = -1;
        for(int i=0; i<n; i++) {
            if(nums[i]==0) sum += 1;
            else sum -= 1;
            if(mpp.find(sum)!=mpp.end()) {
                maxLen = max(maxLen, i-mpp[sum]);
            }
            else mpp[sum] = i;
        }

        return maxLen;
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
