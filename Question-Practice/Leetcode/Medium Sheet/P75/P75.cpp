#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        // For a valid triangle of sides (a,b,c) => 1. a<=b<=c 2. a+b>c
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0; i<n; i++) { // nums[i] = a
            for(int j=i+1; j<n; j++) { // nums[j] = b
                int sum = nums[i] + nums[j]; // a+b
                auto it = lower_bound(nums.begin()+j+1, nums.end(), sum); 
                // lower_bound() will give me the smallest index such that nums[k]>=sum
                // Thus, the range of k becomes [j+1,..,ind-1] (where ind = it - nums.begin()) -> if ind = n that means that none of the element in the nums was bigger than the sum
                // Why from j+1 ? because we want c>=b, and since nums is sorted thus that will only happen from [j+1,...,ind-1]
                int ind = it - nums.begin();
                ans += ind-j-1; // ind-1-(j+1)+1
            }
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
