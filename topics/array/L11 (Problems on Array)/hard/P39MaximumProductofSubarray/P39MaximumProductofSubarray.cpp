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

    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    // brute-force method
    
    // int maxi = INT_MIN;
    // for(int i=0; i<n; i++) {
    //     for(int j=i+1; j<n; j++) {
    //         int product = 1;
    //         for(int k = i; k<=j; k++) {
    //             product = product*arr[k];
    //         }
    //         maxi = max(maxi, product);
    //     }
    // }
    // TC -> O(N*N*N) (approx.)
    // SC -> O(1)

    // Better Approach

    // int maxi = INT_MIN;
    // for(int i=0; i<n; i++) {
    //     int product = 1;
    //     for(int j=0; j<n; j++) {
    //         product = product*arr[j];
    //         maxi = max(maxi, product);
    //     }
    // }

    // Optimal Approach (Observation-based)

    // Cases: 
    // 1. If all numbers are positive, then maximum product = product of all elements
    // 2. If -ve numbers are even in size, then maximum product  = product of all elements
    // 3. If number of -ve numbers is odd, then we always try to create prefix and suffix products and try to attain maximum out of those
    // 4. If array also have zeroes, then also we use the prefix and suffix method

    int prefix  = 1;
    int suffix = 1;
    int maxi = INT_MIN;
    for(int i=0; i<n; i++) {
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix = prefix*arr[i];
        suffix = suffix*arr[n-1-i];
        maxi = max(maxi, max(prefix, suffix));
    }

    cout << maxi << endl;

    return 0;
}
