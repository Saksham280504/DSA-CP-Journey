#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n,m;
    cin >> n >> m;
    string x,s;
    cin >> x >> s; 
    int flag = 0;
    int cnt = 0;
    while(flag==0) {
        for(int i=0; i<n; i++) {
            if(x[i]!=s[0] || n-i < m) continue;
            flag = 1;
            for(int j=1; j<m; j++) {
                if(x[i+j] != s[j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                cout << cnt << endl;
                return;
            }
        }
        if(n>m && flag==0 && cnt > 5) {
            cout << -1 << endl;
            return;
        }
        x += x;
        n = x.size();
        cnt++;
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


// The argument of the problem is n*m <= 25 which means that even in the worst case when n=1 and m=25, we will see that after 5 operations n becomes 32 and if then s is not a substring of x, then it will never be happening that s will ever be a substring of x even if we performed infinite operations.