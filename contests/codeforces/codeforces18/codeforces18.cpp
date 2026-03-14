#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve1() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }
    map<int,int> mpp;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            mpp[mat[i][j]]++;
        }
    }
    
    int maxi = INT_MIN;
    for(auto it: mpp) {
        maxi = max(maxi,it.second);
    }
    if(maxi<=(n*(n-1))) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

void solve2() {
    int n,k,p,m;
    cin >> n >> k >> p >> m;
    k--;
    p--;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int mini = INT_MAX;
    int minIndex = -1;
    for(int i=0; i<k; i++) {
        if(arr[i]<=mini) {
            mini = arr[i];
            minIndex = i;
        }
    }

    int cnt = 0;
    while(m>=0) {
        if(mini>m && p>k) break;
        if(p<=k && m>=arr[p]) {
            int x = arr[p];
            arr.erase(arr.begin()+p);
            p = n-1;
            m -= x;
            arr.push_back(x);
            cnt++;
        }
        else {
            int x = arr[minIndex];
            arr.erase(arr.begin() + minIndex);
            p--;
            m -= x;
            arr.push_back(x);
            int temp = INT_MAX;
            for(int i=0; i<k; i++) {
                if(arr[i]<=temp) {
                temp = arr[i];
                minIndex = i;
                }
            }
            mini = temp;
        }
    }
    cout << cnt << endl;
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
    while(t--) solve2();

    return 0;
}
