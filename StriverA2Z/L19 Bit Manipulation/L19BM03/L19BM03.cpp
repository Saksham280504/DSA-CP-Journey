#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign = true;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) sign = false;
        long n = abs((long) dividend); // To prevent from overflow (if dividend or divisor = -2^31, then on doing its absolute it will move out the bounds of int, thus we need to type cast both the dividend and divisor before taking its absolute)
        long d = abs((long) divisor);
        long ans = 0; // To prevent overflow as ans will be storing powers of 2
        while(n>=d) {
            int cnt=0;
            while(d*(1L<<(cnt+1))<=n) cnt++; // If we do (1<<x), then here 1 is of int data type, and since it might happen that cnt might increase to very large values (~31), thus (1<<(cnt+1)) will overflow at that time, thus to prevent that we use 1L<<(cnt+1) where 1 now is of long datatype.
            ans += (1L<<cnt);
            n -= d*(1L<<cnt);
        }

        if(ans==(1L<<31) && sign) return INT_MAX; // Here as we see 1<<31 would have resulted in overflow in int datatype, we use 1L<<31 so that the datatype of 1 becomes long and thus overflow doesn't occur
        if(ans==(1L<<31) && !sign) return INT_MIN; 

        return (sign) ? ans : -ans;
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
