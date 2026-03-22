#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int mod = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long result = 1;
        base %= mod;

        while(exp>0) {
            if(exp&1) result = (result*base)%mod;
            base = (base*base)%mod;
            exp >>= 1;
        }

        return result;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long ans = (power(5,even)*power(4,odd))%mod;
        return (int)ans;
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
