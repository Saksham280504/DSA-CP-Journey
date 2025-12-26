#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    long long n;
    cin >> n;
    long long ans_a = 1, ans_b = n-1; // If n = 2,3, then a=1, b=n-1 (1,2)
    for(long long fac=2; fac*fac<=n; fac++) { // This will give us all the divisors of n, the reason why we are considering factors from 2 is that if fac=1, then ans_a = n/fac = n, thus making ans_b=0 which is not acceptable as ans_a, ans_b must be > 0
        if(n%fac!=0) { // If n has no factor, then the smallest LCM of(a,b) is when a = 1 and b=n-1 (observation)
            ans_a = max(1LL,ans_a);
            ans_b = n-ans_a;
        }
        else {
            ans_a = max(n/fac,ans_a); // The smaller the fac such that n%fac==0, the bigger will be the n/fac value
            ans_b = n-ans_a;
        }
    }

    cout << ans_a << " " << ans_b << endl;

    // We greedily try to find the smallest factor of n, in order to get the maximum value of ans_a, and minimum value of ans_b, thus giving us the smallest LCM(a,b)
    // LCM(a,b) = a.b/gcd(a,b) (definition of LCM)
    // To minimize LCM, we must make product (a.b) smallest and gcd largest
    // If fac is the smallest factor of n, this will make a = n/fac the largest fac of n. Since a is a factor of n, this means that n-a=b is also a multiple of a (as n-a+a = n which shows that if n comes in table of a, then n-a must also come in table of a). Now, gcd(a,b) = gcd(a,n-a) = a (largest possible value).
    // So LCM(a,b) = a(n-a)/a = n-a = b (smallest)
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
