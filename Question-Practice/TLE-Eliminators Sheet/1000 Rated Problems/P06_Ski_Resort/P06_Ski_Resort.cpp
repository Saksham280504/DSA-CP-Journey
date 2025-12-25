#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n,k,q;
    cin >> n >> k >> q;
    vector<long long> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i]>q) arr[i] = 0;
        else arr[i] = 1;
    }
    long long numOfOnes = 0;
    long long numOfWays = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]==1) numOfOnes++;
        else {
            if(numOfOnes>=k) {
                long long diff = numOfOnes-k+1;
                numOfWays += (diff)*(diff+1)/2;
            }
            numOfOnes = 0;
        }
    }

    if(numOfOnes>=k) {
        long long diff = numOfOnes-k+1;
        numOfWays += (diff)*(diff+1)/2;
    }

    cout << numOfWays << endl;
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
