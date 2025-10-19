#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void lds(int n, vector<int>& arr) {
    sort(arr.begin(), arr.end()); // You need a subset, so the order of the array doesn't matter

    vector<int> dp(n,1) , hash(n);
    int lastIndex = 0;
    int maxi = 1;
    for(int i=0; i<n; i++) {
        hash[i] = i;
        for(int j=0; j<i; j++) {
            if(arr[i]%arr[j]==0 && dp[i]<dp[j] + 1) {
                dp[i] = dp[j]+1;
                hash[i] = j;
            }
        }
        if(dp[i]>maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    int length = dp[lastIndex];
    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    while(hash[lastIndex]!=lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    
    while(length--) {
        cout << temp[length] << " ";
    }
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

    // You are given an array of size n and you need to find the largest divisible subset of that array, i.e. all the element pairs of that subset are divisible with each other.
    // For eg. {1,4,7,8,16} has LDS as {1,4,8,16} as all the pairs in this subset ({1,16},{1,4},{1,8},{4,8},{8,16}) are divisible to each other.
    // Now the difference between a subset and subsequence is that here, the elements don't need to follow the order as per the parent array.
    // Thus, {1,4,8,16} , {1,8,4,16}, {16,8,4,1} etc. all are correct answers
    // The smallest size of lds is 1, as a single element is always divisible by itself.

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    lds(n,arr);


    return 0;
}
