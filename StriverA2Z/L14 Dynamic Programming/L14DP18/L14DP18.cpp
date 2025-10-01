#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numOfPartitionsTab(int n, int d, int target, vector<int>& arr, vector<vector<bool>>& dp) {
    for(int i=0; i<n; i++) dp[i][0]  = true;
    if(arr[0]<=target) dp[0][arr[0]] = true;

    for(int i=1; i<n; i++) {
        for(int k=1; k<=target; k++) {
            bool notPick = dp[i-1][k];
            bool pick = false;
            if(arr[i]<=k) pick = dp[i-1][k-arr[i]];
            dp[i][k] = pick | notPick;
        }
    }

    int cnt = 0;
    for(int k=0; k<=target; k++) {
        if(dp[n-1][k]==true && k>=(target-k) && (2*k-target)==d) cnt++;
    }

    return cnt;
}

int numOfPartitionsRecursion(int ind, int s2, vector<int>& arr) {
    if(ind==0) {
        if(s2==0 && arr[ind]==0) return 2;
        if(s2==0 || s2==arr[ind]) return 1;
        else return 0;
    }

    int notPick = numOfPartitionsRecursion(ind-1,s2,arr);
    int pick = 0;
    if(arr[ind]<=s2) pick = numOfPartitionsRecursion(ind-1,s2-arr[ind],arr);
    return pick + notPick;
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

    // We are given an array and we have to create two partitions such that:

    // 1. Their union create the original array
    // 2. The partitions have sum S1 and S2, such that S1 >= S2 and S1-S2 = 
    // Finally we have to count that how many subsets can we create this way

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int d;
    cin >> d;

    int target = 0;
    for(int i=0; i<n; i++) {
        target += arr[i];
    }
    vector<vector<bool>> dp(n, vector<bool>(target+1,false));

    int cnt1 = numOfPartitionsTab(n,d,target,arr,dp);
    cout << cnt1 << endl;

    // Here I have used the first way of finding subsets, i.e. using tabulation to find one subset S1 using the dp-array.

    // We can also apply the DP17 lecture here, by using the following analogy:
    // S1 >= S2
    // S1-S2 = D
    // S1+S2 = TotalSum
    // S2 = (TotalSum-D)/2

    // Now, we just need to find the number of subsets with sum S2 such that:
    // TotalSum-D>=0
    // (TotalSum-D)%2==0
    if(target-d<0 || (target-d)%2!=0) {
        cout << 0 << endl;
        return 0;
    }
    int s2 = (target-d)/2;
    int cnt2 = numOfPartitionsRecursion(n-1,s2,arr);

    cout << cnt2 << endl;
    return 0;
}
