#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Here, the candidates array can have duplicates
// Using a set to deal with duplicate combinations is not efficient, you have to deal with duplicates recursively.
class Solution {
private:
    void solve(int ind, int target, vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans) {
        if(target==0) {
            ans.push_back(curr);
            return;
        }
        if(ind==candidates.size()) return;

        for(int i=ind; i<candidates.size(); i++) {
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            curr.push_back(candidates[i]);
            solve(i+1,target-candidates[i], candidates, curr, ans); // Only using one index value once
            curr.pop_back(); // back-track
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // This allows you to deal with duplicate entries in candidates
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
