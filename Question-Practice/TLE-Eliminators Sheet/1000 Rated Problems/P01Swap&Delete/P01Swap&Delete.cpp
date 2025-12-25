#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    string s;
    cin >> s;
    int zeros=0, ones=0;
    for(auto it: s) {
        if(it=='0') zeros++;
        else ones++;
    }
    
    int tSize = 0;
    for(auto it: s) {
        if(it=='0') {
            if(ones>0) {
                tSize++;
                ones--;
            }
            else break;
        }
        else {
            if(zeros>0) {
                tSize++;
                zeros--;
            }
            else break;
        }
    }

    cout << s.size()-tSize << endl;

    // TC -> O(2N)
    // SC -> O(1)
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
