#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numOfLIS(int n, vector<int>& arr) {
    vector<int> dp(n,1), cnt(n,1);
    int maxi = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                cnt[i] = cnt[j];
            }
            else if(arr[i] > arr[j] && dp[i] == dp[j] + 1) cnt[i] += cnt[j];
        }
        maxi = max(maxi,dp[i]);
    }

    int num = 0;

    for(int i=0; i<n; i++) {
        if(dp[i] == maxi) num += cnt[i];
    }

    return num;
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

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    return 0;
}
