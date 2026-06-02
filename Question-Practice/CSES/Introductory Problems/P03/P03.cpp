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
    string s;
    cin >> s;
    int maxLen = 0;
    char prev = '#';
    int cnt = 0;
    for(char ch: s) {
        if(prev==ch) {
            cnt++;
            maxLen = max(cnt,maxLen);
        }
        else {
            prev = ch;
            cnt = 1;
        }
    }
    if(maxLen==0) cout << 1 << endl;
    else cout << maxLen << endl;

    return 0;
}
