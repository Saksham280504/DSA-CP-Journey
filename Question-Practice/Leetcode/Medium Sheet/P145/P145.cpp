#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0; // These are the pointers which point to the next ugly number to be multiplied by 2,3, or 5.

        for(int i=1; i<n; i++) {
            int next_2 = ugly[p2]*2;
            int next_3 = ugly[p3]*3;
            int next_5 = ugly[p5]*5;

            int next_ugly_num = min({next_2,next_3,next_5});
            ugly[i] = next_ugly_num;

            if(next_ugly_num==next_2) p2++;
            if(next_ugly_num==next_3) p3++;
            if(next_ugly_num==next_5) p5++;
        }
        return ugly[n-1];
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
