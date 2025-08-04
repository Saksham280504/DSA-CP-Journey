#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n,k,x;
    cin >> n >> k >> x;
    int sum = 0;
    vector<int> arr;
    int length = arr.size();
    int flag = 0;
    int numOfOps = 0;
    if(k==1 && x==1) {
        cout << "NO" << endl;
        return;
    }
    while(flag==0 && numOfOps <= n) {
        for(int i=1; i<=k; i++) {
            if(sum==n) {
            flag = 1;
            break;
            }
            if(i==x) continue;
            sum += i;
            arr.push_back(i);
            length++;
            numOfOps++;
            if(sum > n && length ) {
            sum -= i;
            arr.pop_back();
            length--;
            }
        }
    }
    
    if(flag) {
        cout << "YES" << endl;
        cout << length << endl;
        for(int i=0; i<length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    cout << "NO" << endl;
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
