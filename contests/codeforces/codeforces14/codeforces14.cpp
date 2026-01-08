#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
void solvea() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    if(a[0]==0 && a[n-1]==0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}

void solveb() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    sort(a.begin(),a.end());
    vector<int> mex(n+1);
    for(int i=0; i<k-1; i++) mex[a[i]] = 1;
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
        solvea();
    }

    return 0;
}
