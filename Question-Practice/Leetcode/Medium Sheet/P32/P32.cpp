#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--; // [1,1] is also a test case that means repetitive elements is also possible

        if(i>=0) {
            int j = n-1;
            while(nums[j]<=nums[i]) j--;
            swap(nums[j], nums[i]);
        }

        reverse(nums.begin()+i+1, nums.end());
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
