#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    vector<int> getSieve(int n) {
        vector<int> sieve(n+1,1);
        for(int i=2; i*i<=n; i++) {
            if(sieve[i]) {
                for(int j=i*i; j<=n; j+=i) {
                    sieve[j] = 0;
                }
            }
        }
        return sieve;
    }
  public:
    int countPrimes(int l, int r) {
        vector<int> sieve = getSieve(2*100000);
        for(int i=3; i<=2*100000; i++) {
            sieve[i] += sieve[i-1];
            if(i>r) break;
        }
        return sieve[r]-sieve[l-1];
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
