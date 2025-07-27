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

        ll coins = 0;
        int bags_left = n;

        while(bags_left > 0) {
            ll MaxFreeWeight = INT_MIN;
            int MaxFreeInd = -1;
            for(int i=0;i<bags_left; i++) {
                if(arr[i] <= c) {
                    if(arr[i]>=MaxFreeWeight) {
                        MaxFreeWeight = arr[i];
                        MaxFreeInd = i;
                    }
                }
            }
            int destroyIndex;
            if(MaxFreeInd!=-1) {
                destroyIndex = MaxFreeInd;
            }
            else {
                ll MinPaidWeight = __LONG_LONG_MAX__;
                int MinPaidInd = -1;
                for(int i=0; i<bags_left; i++) {
                    if(arr[i]<MinPaidWeight && arr[i]>c) {
                        MinPaidWeight = arr[i];
                        MinPaidInd = i;
                    }
                }
                coins++;
                destroyIndex = MinPaidInd;
            }
            for(int i=0; i<bags_left; i++) {
            if(i!=destroyIndex) arr[i] = 2*arr[i];
            else arr[i] = 0;
            }
            swap(arr[destroyIndex],arr[bags_left-1]);
            bags_left--;
        }
        cout << coins << endl;
    }
    return 0;
}