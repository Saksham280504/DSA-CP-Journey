#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    vector<int> dp; // dp[mask] = 0 -> unvisited, dp[mask] = 1 -> possible, dp[mask] = -1 -> not possible
    bool canWin(int maxInt, int total, int mask) {
        if(dp[mask]!=0) {
            return dp[mask]==1;
        }
        for(int i=1; i<=maxInt; i++) {
            int bit = 1<<i;
            if(!(mask&bit)) {
                if(i>=total || !canWin(maxInt,total-i,mask|bit)) {
                    dp[mask] = 1;
                    return true;
                }
            }
        }
        dp[mask] = -1;
        return false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal<=maxChoosableInteger) return true;
        int sum = (maxChoosableInteger)*(maxChoosableInteger+1)/2;
        if(sum<desiredTotal) return false;
        dp.assign(1<<(maxChoosableInteger+1),0);
        return canWin(maxChoosableInteger,desiredTotal,0);
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
