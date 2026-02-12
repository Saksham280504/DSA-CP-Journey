#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i=0; i<m; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> gaps(m);
    for(int i=0; i<m-1; i++) {
        gaps.push_back(a[i+1]-a[i]-1);
    }
    gaps.push_back(a[0]-1+n-a[m-1]);
    sort(gaps.rbegin(), gaps.rend());

    int numSaved = 0;
    int numDays = 0;
    for(auto gap: gaps) {
        int currGap = gap - numDays*2;
        if(currGap>0) {
            numSaved++;
            currGap -= 2;
            numDays++;
            if(currGap>0) {
                numSaved += currGap;
                numDays++;
            }
        }
    }

    cout << n-numSaved << endl;
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
