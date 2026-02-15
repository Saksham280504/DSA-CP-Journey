#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    int val1 = 1;
    int val2 = -1;
    vector<pair<int,int>> roads;
    for(int i=2; i<=n; i++) {
        if(a[val1]!=a[i]) {
            roads.push_back({val1,i});
            val2 = i;
            break;
        }
    }
    if(val2==-1) {
        cout << "NO" << endl;
        return;
    }
    
    for(int i=2; i<=n; i++) {
        if(i==val2) continue;
        if(a[i]==a[val1]) {
            roads.push_back({val2,i});
        }
        else roads.push_back({val1,i});
    }

    cout << "YES" << endl;
    int m = roads.size();
    for(int i=0; i<m; i++) {
        cout << roads[i].first << " " << roads[i].second << endl;
    }
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
