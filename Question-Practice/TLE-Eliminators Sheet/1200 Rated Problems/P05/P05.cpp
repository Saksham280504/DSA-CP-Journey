#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,k;
    cin >> n >> k;
    vector<vector<int>> colors(k+1);
    for(int i=0; i<=k; i++) colors[i].push_back(0);
    for(int i=1; i<=n; i++) {
        int color;
        cin >> color;
        colors[color].push_back(i);
    }
    for(int i=0; i<=k; i++) colors[i].push_back(n+1);

    int mini = INT_MAX;
    for(int i=1; i<=k; i++) {
        priority_queue<int> pq;
        int n = colors[i].size();
        for(int j=1; j<n; j++) pq.push(colors[i][j]-colors[i][j-1]-1);
        int top = pq.top();
        pq.pop();
        if(top&1) {
            pq.push(top/2);
            pq.push(top/2);
        }
        else {
            pq.push((top/2)-1);
            pq.push(top/2);
        }
        mini = min(mini,pq.top());
    }
    cout << mini << endl;
    // TC -> O(KLogN)
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
