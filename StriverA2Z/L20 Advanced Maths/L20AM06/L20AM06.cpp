#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n+1,1);
        for(int i=2; i*i<=n; i++) {
            if(prime[i]==1) {
                for(int j=i*i; j<=n; j+=i) prime[j] = 0;
            }
        }
        int cnt = 0;
        for(int i=2; i<n; i++) {
            if(prime[i]==1) cnt++;
        }

        return cnt;

        // TC -> O(N + Nlog(logN))
        // SC -> O(N)
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
