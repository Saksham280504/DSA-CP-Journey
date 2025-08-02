#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
using ll = long long;
void solve() {

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
        int n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        int flag = 1;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            if(i>0) {
                if(arr[i]>=arr[i-1]) continue;
                flag = 0;
            }
        }

        if(flag==1) {
            cout << "YES" << endl;
            continue;
        }
        if(flag==0 && k==1) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }

    return 0;
}
