#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mini = INT_MAX;
    for(char c='a'; c<='z'; c++) {
        bool isPossible = true;
        int i = 0;
        int j = n-1;
        int temp = 0;
        while(i<j) {
            if(s[i]==s[j]) {
                i++;
                j--;
                continue;
            }
            if(s[i]==c) {
                temp++;
                i++;
                continue;
            }
            if(s[j]==c) {
                temp++;
                j--;
                continue;
            }
            else {
                isPossible = false;
                break;
            }
        }
        if(isPossible) mini = min(temp,mini);
    }

    if(mini==INT_MAX) {
        cout << -1 << endl;
    }
    else cout << mini << endl;

    // TC -> O(26*N)
    // SC -> O(N)
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
