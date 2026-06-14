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

    int n,k;
    cin >> n >> k;
    if(n==1) {
        cout << 1 << endl;
        return 0;
    }
    map<int,pair<int,int>> mpp; // {prev,next}
    mpp[1] = {n,2};
    for(int i=2; i<n; i++) {
        mpp[i] = {i-1,i+1};
    }
    mpp[n] = {n-1,1};

    int removes = 0;
    int prev = 1, node = 1;
    while(removes<n) {
        for(int i=0; i<k; i++) {
            node = mpp[prev].second;
            prev = node;
        }
        mpp[mpp[node].first].second = mpp[node].second;
        mpp[mpp[node].second].first = mpp[node].first;
        cout << node << " ";
        mpp.erase(mpp.find(node));
        removes++;
    }
    cout << endl;

    return 0;
}
