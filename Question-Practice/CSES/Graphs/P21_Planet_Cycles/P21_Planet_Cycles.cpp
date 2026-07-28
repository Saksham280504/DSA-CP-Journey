#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> arr;
vector<int> dp; // cycle lengths for all nodes inside cycle, and distance to cycle + cycle-length for all nodes outside the cycle.
vector<int> dist; // distance of node from that component
vector<bool> vis;
int cycle_start = -1, cycle_length = 0;

void dfs(int u, int curr_dist) {
    if(vis[u]) return;
    vis[u] = true;
    dist[u] = curr_dist;
    int v = arr[u];
    if(!vis[v]) {
        dfs(v,curr_dist+1);
    }
    else {
        if(!dp[v]) {
            cycle_length = dist[u] - dist[v] + 1;
            cycle_start = v;
        }
        else {
            cycle_length = dp[v];
        }
    }
    if(cycle_start!=-1) {
        dp[u] = cycle_length;
        if(u==cycle_start) {
            cycle_start = -1;
        }
    } else {
        dp[u] = dp[v] + 1;
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
    int n;
    cin >> n;
    arr.resize(n+1);
    dp.assign(n+1,0);
    dist.assign(n+1,0);
    vis.assign(n+1,false);
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            cycle_start = -1;
            cycle_length = 0;
            dfs(i,1);
        }
    }

    for(int i=1; i<=n; i++) cout << dp[i] << " ";
    cout << endl;

    return 0;
}
