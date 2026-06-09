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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    int cnt = 1;
    int prev = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i]!=prev) {
            prev = arr[i];
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
