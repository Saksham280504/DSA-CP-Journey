#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    vector<ll> b; 
    vector<ll> c; 
    int lb=0;
    int lc=0;
    int flag = 0;
    for(int i=0; i<n; i++) {
        if(a[i]==1) {
            b.push_back(a[i]);
            lb++;
            flag = 1;
        }
        else if(flag==0) {
            b.push_back(a[i]);
            lb++;
            flag=1;
        }
        else {
            int isDivisor = 0;
            for(int j=0; j<lb; j++) {
                if(b[j]%a[i]==0) {
                    b.push_back(a[i]);
                    lb++;
                    flag = 1;
                    isDivisor = 1;
                    break;
                }
            }
            if(isDivisor==0) {
                c.push_back(a[i]);
                lc++;
                flag = 0;
            }
        }
    }

    for(int i=0; i<lc; i++) {
        for(int j=0; j<lb; j++) {
            if(b[j]%c[i]==0) {
                c.push_back(b[j]);
                lc++;
                b.erase(b.begin()+j);
                j--;
                lb--;
            }
        }
    }

    if(lb==0 || lc == 0) {
        cout << -1 << endl;
        return;
    }
    else {
        cout << lb << " " << lc << endl;
        for(int i=0; i<lb; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
        for(int i=0; i<lc; i++) {
            cout << c[i] << " ";
        }
        cout << endl;
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
