#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    // Here what we firstly try to catch is that we need to convert the less than or equal to relation to just equal to relation, and then we will use bi = n+1-ai
    vector<int> b(n);
    for(int i=0; i<n; i++) {
        b[i] = n+1-a[i];
    }

    for(int i=0; i<n; i++) {
        cout << b[i] << " ";
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

    int t;
    cin >> t; 
    while(t--) {
        solve();
    }

    return 0;
}
