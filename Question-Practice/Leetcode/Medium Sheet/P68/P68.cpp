#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    void solve(int ind, vector<int>& nums, vector<int>& curr, vector<bool>& used, vector<vector<int>>& ans) {
        ans.push_back(curr);

        for(int i=ind; i<nums.size(); i++) {
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            solve(i+1,nums,curr,used,ans);
            curr.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(),false);
        solve(0,nums,curr,used,ans);
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
