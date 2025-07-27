#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
using ll = long long;
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
    for(int z=0; z<t; z++) {
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
 
        while(n) {
            int closest = INT_MIN;
            int closestInd = -1;
            int flag = 0;
            for(int i=0;i<n; i++) {
                if(arr[i] <= c) flag = 1;
                if(arr[i]>=closest && arr[i]<=c) {
                closest = arr[i];
                closestInd = i;
                }
            }
            if(flag==0) {
            cout << n << endl;
            break;
            }
            for(int i=0; i<n; i++) {
            if(i!=closestInd) arr[i] = 2*arr[i];
            else arr[i] = 0;
            }
            swap(arr[closestInd],arr[n-1]);
            n--;
        }
    }
    return 0;
}