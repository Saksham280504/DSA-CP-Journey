#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    long long n;
    cin >> n;
    cout << n << " ";
    while(n!=1LL) {
        if(n&1LL) {
            n = n*3LL+1LL;
            cout << n << " ";
        }
        else {
            n = n/2;
            cout << n << " ";
        }
    }

    return 0;
}
