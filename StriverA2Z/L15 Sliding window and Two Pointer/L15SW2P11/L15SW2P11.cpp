#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    int subarraysWithAtMostKDistinct(vector<int>& nums, int k) {
        if(k<0) return 0;
        map<int,int> mpp; // {integer,freq}
        int l=0, r=0, num=0;
        int n = nums.size();
        while(r<n) {
            mpp[nums[r]]++;
            while(mpp.size()>k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            if(mpp.size()<=k) num += (r-l+1);
            r++;
        }
        return num;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums,k) - subarraysWithAtMostKDistinct(nums,k-1);
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
