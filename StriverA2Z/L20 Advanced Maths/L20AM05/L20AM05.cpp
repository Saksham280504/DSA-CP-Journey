#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    double myPow(double x, int n) {
        long m = n;
        m = abs(m);
        double ans = 1;
        while(m>0) {
            if(m%2==1) {
                ans = ans*x;
                m = m-1;
            }
            else {
                x = x*x;
                m = m/2;
            }
        }
        if(n<0) return 1.0/ans;
        return ans;
    }

    // TC -> O(log2N)
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
