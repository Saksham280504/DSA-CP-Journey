#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
using ll = long long;
void solve() {
    ll n;
    cin >> n;

    ll m = n;
    bool isDivisble = false;
    bool isFive = false;
    int k = 0;
    // 25 or 75
    while(!isDivisble && m > 0) {
        int lastInd = m%10;
        if(lastInd!=5) {
            k++;
            m/=10;
        }
        else if(lastInd==5 && !isFive) {
            m/=10;
            isFive = true;
        }
        else if((lastInd==7 || lastInd==2) && (isFive)) {
            isDivisble = true;
        }
    }

    cout << k << " ";
    k=0;
    bool isZero = false;
    m = n;
    isDivisble = false;

    // n00 or 50
    while(!isDivisble && m > 0) {
        int lastInd = m%10;
        if(lastInd!=0) {
            k++;
            m/=10;
        }
        else if(lastInd==0 && !isZero) {
            m/=10;
            isZero = true;
        }
        else if((lastInd==5 || lastInd==0) && (isZero)) {
            isDivisble = true;
        }
    }
    cout << k << endl;
}

int32_t main() {
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