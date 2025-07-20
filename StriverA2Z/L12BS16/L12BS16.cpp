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

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    // Find Kth missing positive Integer

    // Brute-force method

    // for(int i=0; i<n; i++) {
    //     if(arr[i]<=k) k++;
    //     else break;
    // }

    // For every number from 1 to arr[n-1] (largest element) which is lesser than k and is present in array, the value of k increases by 1

    // cout << k << endl;

    // TC -> O(N)
    // SC -> O(1)

    // Optimal Solution

    int low = 0;
    int high = n-1;

    while(low<=high) {
        int mid = (low+high)/2;
        // arr[mid]-(mid+1) is equal to the total missing numbers uptil arr[mid].
        if(arr[mid]-(mid+1)<k) low = mid+1;
        else high = mid-1;
    }

    // Now we have the two nearby indices such that our kth missing number lies in between arr[high] & arr[low].

    // Now we know that uptil high, the total number of missing numbers are missing = arr[high]-(high+1). Also, to reach the Kth missing number we need to know how much more missing numbers we need to cross. For that we have the formula:

    // more = k - (missing)
    // Now, kth missing number = arr[high] + more
    // So, kth missing number = arr[high] + k -(missing)
    // kth missing number = arr[high] + k - (arr[high] - (high+1))
    // kth missing number = (high+1) + k  (or low+k)
    // Using this formula is important to fulfill the edge-case of k < arr[0].

    cout << high + 1 + k << endl;

    // TC -> O(log2(N))
    // SC -> O(1)

    return 0;
}
