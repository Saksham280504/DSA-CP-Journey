#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long 

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
    ll x;
    cin >> n >> x;
    vector<ll> weights(n);
    for(int i=0; i<n; i++) cin >> weights[i];
    int N = 1<<n;
    ll INF = 1e18;
    vector<pair<ll,ll>> dp(N,{INF,INF});
    dp[0] = {1,0}; // When mask=0, we can consider our first lift is ready to take passengers. Currently it has none.

    for(int mask=0; mask<N; mask++) {
        ll rides = dp[mask].first;
        ll last_w = dp[mask].second;
        if(rides==INF) continue; // Unreachable State
        for(int i=0; i<n; i++) {
            if(mask&(1<<i)) continue; // already present in the subset
            int newMask = mask | (1<<i);
            pair<ll,ll> candidate;
            if(last_w+weights[i]<=x) candidate = {rides,last_w+weights[i]};
            else candidate = {rides+1,weights[i]};
            dp[newMask] = min(dp[newMask],candidate);
        }
    }
    int allPeople = N-1;
    cout << dp[allPeople].first << endl;

    return 0;
}
