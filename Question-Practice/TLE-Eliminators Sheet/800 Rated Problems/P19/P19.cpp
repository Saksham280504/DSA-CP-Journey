#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int posCounter  = 0;
    int negCounter = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i]==1) posCounter++;
        else negCounter++;
    }
    int numOfOperations = 0;
    while(posCounter<negCounter || negCounter%2==1) {
        posCounter++;
        negCounter--;
        numOfOperations++;
    }

    cout << numOfOperations << endl;
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
