#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int lisPrint(int n, vector<int>& arr) {
    vector<int> dp(n,1), hash(n);
    // DP-Array stores the size of LIS from index 0 to index 'i' where arr[i] is present in the LIS.
    // Hash-Array stores the index of the last variable of the LIS initiially (i.e. itself) and then afterwards if omitted stores the index of the second last element of the LIS formed till that index.
    
    int lastIndex = 0;
    int maxi = 1;
    for(int i=0; i<n; i++) {
        hash[i] = i;
        for(int prevI=0; prevI<i; prevI++) {
            if(arr[i]>arr[prevI] && dp[prevI] + 1 > dp[i]) {
                dp[i] = dp[prevI] + 1;
                hash[i] = prevI;
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    // The break-case for the while loop below is hash[lastIndex] == lastIndex because this will mean that at the index, no omitting have been done!!

    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(), temp.end());
    
    for(auto it: temp) cout << it << " ";
    cout << endl;

    return maxi;

    // TC -> O(N*N) + O(LIS)
    // SC -> O(N) + O(LIS)
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

    // Here we print the largest increasing subsequence

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int len = lisPrint(n,arr);
    cout << len << endl;

    return 0;
}
