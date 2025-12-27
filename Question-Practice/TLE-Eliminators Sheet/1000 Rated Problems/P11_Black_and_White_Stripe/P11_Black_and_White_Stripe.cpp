#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,k;
    cin >> n >> k;
    string strip;
    cin >> strip;
    vector<int> prefixSum(n,0); // This will give me the total number of whites from start till ith position
    prefixSum[0] = strip[0]=='W' ? 1 : 0;
    for(int i=1; i<n; i++) {
        prefixSum[i] = strip[i]=='W' ? prefixSum[i-1]+1 : prefixSum[i-1];
    }
    int minChange = INT_MAX;
    for(int i=0; i<n-k+1; i++) {
        int stripWhites = prefixSum[i+k-1] - prefixSum[i];
        if(strip[i]=='W') stripWhites++;
        minChange = min(minChange,stripWhites);
    }

    cout << minChange << endl;
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
