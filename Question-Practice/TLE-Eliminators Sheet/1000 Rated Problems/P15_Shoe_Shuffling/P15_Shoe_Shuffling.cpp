#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    vector<long> shoe(n);
    for(auto &x: shoe) cin >> x;
    int i = 0; // i is the index of starting point of every new shoe size
    vector<int> ans;
    while(i<n) {
        int j = i;
        while(j<n && shoe[j]==shoe[i]) j++;
        if(j==i+1) { // Unique shoe size -> can't be shared with anyone
            cout << -1 << endl;
            return;
        }
        for(int k=i; k<j; k++) { // Every kth guy gets the shoe from (k+1)th guy, and if its the last guy, he gets the shoe of the ith (starting point) guy.
            if(k+1<j) {
                ans.push_back(k+1);
            }
            else ans.push_back(i);
        }
        i=j;
    }

    for(int i=0; i<n; i++) {
        ans[i]++;
        cout << ans[i] << " ";
    }
    cout << endl;

    // TC -> O(2*N)
    // SC -> O(N)
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
    while(t--) solve();

    return 0;
}
