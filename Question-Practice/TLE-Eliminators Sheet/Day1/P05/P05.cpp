#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    int tc;
    cin >> tc;
    while(tc--) {
        string s;
        cin >> s;
        string t = s;
        int n = s.size();
        queue<pair<char,int>> q;
        int num0 = 0;
        int num1 = 0;
        int paise = 0;
        for(int i=0; i<n; i++) {
            if(!q.empty()) {
                if(t[i]=='0') num0++;
                else num1++;
                if(q.front().first!=t[i]) {
                    swap(t[i],t[q.front().second]);
                    q.pop();
                }
                else {
                    q.push({t[i], i});
                }
            }
            else {
                if(t[i]=='0') num0++;
                else num1++;
                q.push({t[i],i});
            }
        }
        paise = abs(num0-num1);
        int f_paise = paise;
        for(int i=0; i<=(n-1-paise); i++) {
            if(t[i]==s[i]) {
                f_paise++;
            }
        }
        cout << f_paise << endl;
    }
    return 0;
}
