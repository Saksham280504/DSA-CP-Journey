#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,a,b;
    cin >> n >> a >> b;
    if((a+b)>n) {
        cout << "NO" << endl;
        return;
    }
    if((a==0 && b>0) || (a>0 && b==0)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> p1(n), p2(n);
    for(int i=0; i<n; i++) p1[i] = i+1;
    if(a>0 && b>0) {
        int k = a+b;
        for(int i=0; i<k; i++) {
            if(i<b) { // first all the b matches were won by 2nd player
                p2[i] = p1[i]+a;
            }
            else { // remaining a matches player 1 won
                p2[i] = p1[i]-b;
            }
        }
        for(int i=k; i<n; i++) {
            p2[i] = i+1;
        }
    }
    else {
        for(int i=0; i<n; i++) { // both a and b are 0
            p2[i] = i+1;
        }
    }
    for(int x: p1) cout << x << " ";
    cout << endl;
    for(int x: p2) cout << x << " ";
    cout << endl;
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
