#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'


// At every index, we have two choices, either select the current element, add it to the sum and stay at the same index, or move to the next index.
class Solution {
    private:
    void solve(int ind, int target,vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans) {
        if(target==0) {
            ans.push_back(curr);
            return;
        }
        if(ind == candidates.size()) return;

        if(candidates[ind]<=target) {
            curr.push_back(candidates[ind]);
            solve(ind,target-candidates[ind], candidates, curr, ans);
            curr.pop_back(); // back-track
        }

        solve(ind+1,target,candidates,curr,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,target,candidates,curr,ans);
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
