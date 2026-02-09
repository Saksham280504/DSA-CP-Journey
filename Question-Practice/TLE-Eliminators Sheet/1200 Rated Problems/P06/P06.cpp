#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    if(a.size()==1) {
        cout << 1 << endl;
        return;
    }
    vector<int> ans;
    ans.push_back(a[0]);
    ans.push_back(a[1]);

    for(int i=2; i<n; i++) {
        int currSize = ans.size();
        int x = ans[currSize-2]-ans[currSize-1];
        int y = ans[currSize-1]-a[i];
        if(x>0) {
            if(y>0) {
                ans[currSize-1] = a[i];
            }
            else if(y<0) {
                ans.push_back(a[i]);
            }
        }
        else { // x<=0 where x=0 can only occur at the first case i.e when ans[currSize-2] = v[0] and ans[currSize-1] = v[1] and v[0] = v[1]
            if(y<0) {
                ans[currSize-1] = a[i];
            }
            else if(y>0) {
                ans.push_back(a[i]);
            }
        }
    }

    int finalSize = ans.size();
    if(ans[0]==ans[1]) finalSize--;
    cout << finalSize << endl;
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
