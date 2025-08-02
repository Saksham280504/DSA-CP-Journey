#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int num0 = 0, num1 =0;
    for(int i=0; i<n; i++) {
        if(s[i]=='0') num0++;
        else num1++;
    }
    string ans = "";
    for(int i=0; i<n; i++) {
        if(s[i]=='0') {
            if(num1!=0) {
                ans += '1';
                num1--;
            }
            else break;
        }
        else {
            if(num0!=0) {
                ans += '0';
                num0--;
            }
            else break;
        }
    }

    int m = ans.size();
    cout << n-m << endl;
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

// Completed till 1 problem of 1000 rating