#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void printPrimeFactorization(int n) {
    vector<int> spf(n+1);
    for(int i=0; i<=n; i++) spf[i] = i;

    for(int i=2; i*i<=n; i++) {
        if(spf[i]==i) {
            for(int j=i*i; j<=n; j++) {
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
    while(n!=1) {
        cout << spf[n] << " ";
        n = n/spf[n];
    }
    cout << endl;
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

    return 0;
}
