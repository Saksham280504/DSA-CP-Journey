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

    // To create the nth gray code, we will use the n-1th grayCode. We will first put 0 as the prefix of the n=1th graycode, and then put 1 as the prefix of the reversed n-1th graycode.

    int n;
    cin >> n;
    int limit = 1<<n;

    for(int i=0; i<limit; i++) {
        int g = (i^(i>>1)); // This is the formula to create all the 2^n numbers in grayCode form
        for(int k=n-1; k>=0; k--) {
            cout << ((g>>k)&1);
        }
        cout << endl;
    }

    return 0;
}
