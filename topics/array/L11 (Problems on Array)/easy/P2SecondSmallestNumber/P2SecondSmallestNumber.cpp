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
    for(int i=0; i<n ; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    //brute-force method
    // sort(arr.begin(), arr.end());
    // int secondSmallest = arr[1];
    // for(int i=0; i<n; i++) {
    //     if(arr[i]>arr[0]) {
    //         secondSmallest = arr[i];
    //         break;
    //     }
    // }

    // cout << secondSmallest << endl;

    // This will take NlogN + N TC.

    //Better method
    // int smallest = arr[0];
    // for(int i=0; i<n; i++) {
    //     if(arr[i] < smallest) {
    //         smallest = arr[i];
    //     }
    // }

    // cout << smallest << endl;

    // int secondSmallest = INT_MAX;
    // for(int i=0; i<n; i++) {
    //     if(arr[i] < secondSmallest && arr[i]!=smallest) secondSmallest = arr[i];
    // }

    // cout << secondSmallest << endl;

    // Here, the time complexity is O(2N).

    //optimal approach

    int smallest = arr[0];
    int secondSmallest = INT_MAX; // Assuming there are no negative numbers in the array

    for(int i=0; i<n; i++) {
        if(arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] > smallest) {
            if(arr[i] < secondSmallest) secondSmallest = arr[i];
        }
    }

    cout << smallest << endl;
    cout << secondSmallest << endl;

    // Here, TC is o(N).
    return 0;
}
