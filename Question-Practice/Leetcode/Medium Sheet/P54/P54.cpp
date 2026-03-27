#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'


// Approach-1 => TC -> O(M*N*S) (S=> Number of possible sums)
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        unordered_set<int> curr;
        curr.insert(0);

        for(auto &row: mat) {
            unordered_set<int> next;
            for(int val: row) {
                for(int sum: curr) {
                    int newSum = val + sum;

                    // pruning
                    if(newSum<=2000) {
                        next.insert(newSum);
                    }
                }
            }
            curr = next;
        }

        int mini = INT_MAX;
        for(int sum: curr) {
            mini = min(mini,abs(target-sum));
        }

        return mini;
    }
};

// Approach-2
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<bool> dp(5001,false);
        dp[0] = true;

        for(auto &row: mat) {
            vector<bool> next(5001,false);
            for(int val: row) {
                for(int sum=0; sum<=(5000-val); sum++) {
                    if(dp[sum]) {
                        next[sum+val] = true;
                    }
                }
            }
            dp = next;
        }

        int ans = INT_MAX;
        for(int i=0; i<=5000; i++) {
            if(dp[i]) {
                ans = min(ans,abs(i-target));
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
