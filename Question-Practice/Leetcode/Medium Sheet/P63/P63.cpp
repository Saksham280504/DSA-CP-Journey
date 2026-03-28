#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    void solve(int ind, int n, int k, vector<int>& curr, vector<vector<int>>& ans) {
        if(curr.size()==k) {
            ans.push_back(curr);
            return;
        }
        for(int i=ind; i<=n; i++) {
            curr.push_back(i);
            solve(i+1,n,k,curr,ans); // There is no use of used[T/F] array here, because we are always after pushing a number in curr, moving to the numbers ahead of him which will always be unused as for every ind we are only having the used numbers from its back and not from front.
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1,n,k,curr,ans);
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
