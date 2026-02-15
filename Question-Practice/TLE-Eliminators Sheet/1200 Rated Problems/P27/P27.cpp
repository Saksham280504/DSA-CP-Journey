#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    int cnt0 = 0;
    int cnt1 = 0;
    vector<bool> canFlip(n,false);
    for(int i=0; i<n; i++) {
        if(a[i]=='0') cnt0++;
        else cnt1++;
        if(cnt0==cnt1) canFlip[i] = true;
    }

    bool HasFlipped = false;
    bool isPossible = true;

    for(int i=n-1; i>=0; i--) {
        if(HasFlipped==false) {
            if(a[i]!=b[i]) {
                if(canFlip[i]==true) {
                    HasFlipped = true;
                }
                else {
                    isPossible = false;
                    break;
                }
            }
        }
        else {
            if(a[i]==b[i]) {
                if(canFlip[i]==true) {
                    HasFlipped = false;
                }
                else {
                    isPossible = false;
                    break;
                }
            }
        }
    }

    if(!isPossible) cout << "NO" << endl;
    else cout << "YES" << endl;
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
