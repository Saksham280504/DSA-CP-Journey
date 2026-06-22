#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    int n,k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<ll,ll> mpp; // {element,count}

    ll count=0;
    int i=0;
    for(int j=0; j<n; j++) {
        mpp[arr[j]]++;
        while(mpp.size()>k) {
            mpp[arr[i]]--;
            if(mpp[arr[i]]==0) mpp.erase(arr[i]);
            i++;
        }
        count += (j-i+1);
    }
    cout << count << endl;

    return 0;
}
