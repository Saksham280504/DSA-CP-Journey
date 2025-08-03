#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    vector<int> eff(n-1);
    int sum = 0;
    for(int i=0; i<n-1; i++) {
        cin >> eff[i];
        sum += eff[i];
    }

    cout << (-1*sum) << endl;

    // If all efficiencies are summed up, it will result in 0
    // So missed efficiency = -(sum of rest)

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
