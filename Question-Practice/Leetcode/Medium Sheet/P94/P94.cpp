#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    map<int,int> dp;
    int minDays(int n) {
        if(n<=1) return n;
        if(dp.count(n)) return dp[n];
        int by2 = n%2 + minDays(n/2);
        int by3 = n%3 + minDays(n/3);
        return dp[n] = 1 + min(by2,by3);
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
