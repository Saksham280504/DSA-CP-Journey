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
    cin >> n;
    vector<pair<ll,ll>> tasks(n);
    for(int i=0; i<n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end());

    ll reward = 0;
    ll totalTime = 0;
    for(int i=0; i<n; i++) {
        totalTime += tasks[i].first;
        reward += (tasks[i].second - totalTime);
    }

    cout << reward << endl;

    return 0;
}
