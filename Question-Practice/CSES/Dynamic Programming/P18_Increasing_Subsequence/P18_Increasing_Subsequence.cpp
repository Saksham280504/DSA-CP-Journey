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

    // Brute Force -> TC -> O(N^2) -> TLE
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for(int i=0; i<n; i++) cin >> arr[i];

    // vector<int> dp(n,0);
    // for(int i=0; i<n; i++) {
    //     dp[i] = 1;
    //     for(int j=0; j<i; j++) {
    //         if(arr[j]<arr[i])dp[i] = max(dp[i],dp[j]+1);
    //     }
    // }
    // cout << *max_element(dp.begin(), dp.end()) << endl;

    // Approach - 2
    // This approach will not work because you are just searching for the nearest Previous smaller element in the array, but that doesn't promise the largest LIS
    // int n;
    // cin >> n;
    // vector<pair<int,int>> arr(n);
    // for(int i=0; i<n; i++) {
    //     cin >> arr[i].first;
    //     arr[i].second = i;
    // }

    // vector<int> pse(n);
    // stack<int> st;
    // for(int i=0; i<n; i++) {
    //     while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
    //     if(st.empty()) pse[i] = -1;
    //     else pse[i] = st.top();
    //     st.push(i);
    // }

    // sort(arr.begin(), arr.end());

    // vector<int> lis(n,0);
    // for(int i=0; i<n; i++) {
    //     int idx = arr[i].second;
    //     int pseIdx = pse[idx];
    //     lis[idx] = 1;
    //     if(pseIdx!=-1) lis[idx] = max(lis[idx],lis[pseIdx]+1);
    // }
    // cout << *max_element(lis.begin(), lis.end()) << endl;

    // Optimal Approach -> TC -> O(NlogN)
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> dp;
    // dp[i] -> smallest last element of subsequence of size i+1
    for(int i=0; i<n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if(it==dp.end()) dp.push_back(arr[i]);
        else *it = arr[i];
    }

    cout << dp.size() << endl;
    return 0;
}
