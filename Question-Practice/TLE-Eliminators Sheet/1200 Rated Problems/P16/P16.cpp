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

    int n,q;
    cin >> n >> q;
    vector<pair<long long,int>> a(n,{0LL,0});
    long long sum = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i].first;
        sum += a[i].first;
    }
    pair<long long,int> global = {0LL,-1};
    for(int i=1; i<=q; i++) {
        int t;
        cin >> t;
        if(t==1) {
            int ind;
            long long x;
            cin >> ind >> x;
            if(a[ind-1].second > global.second) {
                sum += (x-a[ind-1].first);
            }
            else {
                sum += (x-global.first);
            }
            a[ind-1].second = i;
            a[ind-1].first = x;
        }
        else {
            long long x;
            cin >> x;
            global.first = x;
            global.second = i;
            sum = n*x;
        }

        cout << sum << endl;
    }

    return 0;
}
