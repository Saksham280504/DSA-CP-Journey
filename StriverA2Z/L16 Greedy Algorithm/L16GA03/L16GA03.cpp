#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution{
    int minCoins(int n) {
        vector<int> deno = {10,5,2,1};
        int coins = 0;
        for(int i=0; i<n; i++) {
            if(deno[i]<=n) {
                coins += n/deno[i];
                n = n%deno[i];
            }
        }

        return coins;
    }

    // TC -> O(N)
    // SC -> O(1)

    // Greedy approach is applicable because the sum of any two adjacent denominations of coins is always lesser than the denomination of the next coin
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
