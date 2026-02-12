#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool isMinOrMax(set<int>& st, int val) {
    if(val==(*st.begin())) return true;
    if(val==(*st.rbegin())) return true;
    return false;
}
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    set<int> st(arr.begin(),arr.end());
    int i=0, j=n-1;
    while(i<j) {
        if(isMinOrMax(st,arr[i])) {
            st.erase(arr[i]);
            i++;
            continue;
        }
        if(isMinOrMax(st,arr[j])) {
            st.erase(arr[j]);
            j--;
            continue;
        }
        break;
    }

    if(i<j) {
        cout << i+1 << " " << j+1 << endl;
    }
    else cout << -1 << endl;
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
