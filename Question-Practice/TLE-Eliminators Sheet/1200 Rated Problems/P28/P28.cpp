#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> remain(m+1,0);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        remain[a[i]%m]++;
    }
    int cnt=0;
    for(int i=0; i<m; i++) {
        int x = remain[i];
        int y = remain[(m-i)%m];
        if(x==0 && y==0) continue;
        int tmp = min(x,y);
        x -= min(tmp+1,x);
        y -= min(tmp+1,y);
        cnt++;
        cnt += (x+y);
        remain[i] = 0;
        remain[(m-i)%m] = 0;
    }
    cout << cnt << endl;
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
