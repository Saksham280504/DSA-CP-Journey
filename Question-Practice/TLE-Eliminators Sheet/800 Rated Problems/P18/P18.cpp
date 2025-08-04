#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int x,k;
    cin >> x >> k;

    vector<int> position;
    int moves = 1;

    if(x%k!=0) {
        cout << moves << endl;
        cout << x << endl;
        return;
    }
    position.push_back(x-k+1);
    position.push_back(k-1);
    moves++;

    cout << moves << endl;
    for(int i=0; i<2; i++) {
        cout << position[i] << " ";
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
