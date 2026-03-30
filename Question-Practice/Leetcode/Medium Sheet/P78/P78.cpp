#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:

    // Instead of smashing two stones which result in |stone1-stone2|, we try to assign + or - sign to all the elements resulting in |stone1 - stone2 + stone3 - stone4 -stone5 ... | like formation, and to minimize it we look for a largest subsetSum <= TotalSum/2
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(),0);
        int target = sum/2;
        vector<int> dp(target+1,0); // dp[j] -> maximum subset sum achievable that is <=j

        for(int stone: stones) { 
            for(int j=target; j>=stone; j--) {
                dp[j] = max(dp[j],dp[j-stone]+stone);
            }
        }

        // As we encounter a new stone, we try to check what maximum sum till target is achievable as the subset sum.

        return sum-2*dp[target];
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
