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
    if(n<4 && n!=1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    if(n==4) {
        cout << 2 << " " << 4 << " " << 1 << " " << 3;
        return 0;
    }
    vector<int> ans(n);
    int num = 1;
    for(int i=0; i<n; i+=2) {
        ans[i] = num;
        num++;
    }
    for(int i=1; i<n; i+=2) {
        ans[i] = num;
        num++;
    }
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
