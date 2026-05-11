#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
// int findRequiredRuns(int opponentScore, int currentScore) {
//     // write your code here 
//     return opponentScore-currentScore+1;
// }

// Q2
// class Solution {
// public:
//     bool isBitSet(long long n, int i) {
//         long long x = 1LL<<i;
//         return n&x;
//     }
// };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    int x = 1<<2;
    int n = 12;
    if(n&x) cout << "true";
    else cout << false;

    return 0;
}
