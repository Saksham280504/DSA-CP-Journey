#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int product = 1;
        while(n>4) {
            product *= 3;
            n -= 3;
        }
        // Until now we have made sure that we have multiplied till the 2nd last partition.
        // The last partition will either be 2 (multiply by 2), 3(multiply by 3), or 4 (multiply by 4)
        product *= n;
        return product;
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
