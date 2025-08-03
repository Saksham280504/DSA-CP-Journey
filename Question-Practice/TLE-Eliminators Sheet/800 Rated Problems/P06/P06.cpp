#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    map<int,int> mpp;
    
    for(int i=0; i<n; i++) {
        mpp[a[i]]++;
    }

    int mpSize = mpp.size();
    if(mpSize > 2) {
        cout << "NO" << endl;
        return;
    }
    else if(mpSize == 1) {
        cout << "YES" << endl;
        return;
    }
    else {
        vector<int> cnt;
        for(auto it: mpp) {
            cnt.push_back(it.second);
        }

        if(n%2==0) {
            if(cnt[0]!=cnt[1]) {
                cout << "NO" << endl;
                return;
            }
            else {
                cout << "YES" << endl;
                return;
            }
        }
        else {
            if(abs(cnt[0]-cnt[1])>1) {
                cout << "NO" << endl;
                return;
            }
            else {
                cout << "YES" << endl;
                return;
            }
        }
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
    while(t--) {
        solve();
    }

    return 0;
}
