#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    void solve(vector<int>& nums, vector<int>& curr, vector<bool>& used, vector<vector<int>>& ans) {
        if(curr.size()==nums.size()) {
            ans.push_back(curr);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!used[i]) {
                curr.push_back(nums[i]);
                used[i] = true;
                solve(nums,curr,used,ans);
                used[i] = false;
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(n,false);
        solve(nums,curr,used,ans);
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
