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

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        map<char,int> mpp;

        for(int i=0; i<n; i++) {
            mpp[s[i]]++;
        }

        int numOfOdd = 0;
        for(auto it: mpp) {
            if((it.second)%2!=0) numOfOdd += ((it.second)%2);
        }
        if((numOfOdd-k)>1) {
            cout << "NO" << endl;
            continue;
        }
        else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
