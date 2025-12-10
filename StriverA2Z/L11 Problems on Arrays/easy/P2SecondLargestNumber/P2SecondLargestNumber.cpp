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

    // brute-force method
    sort(arr.begin(), arr.end());
    int secondSmallest = arr[1];
    for(int i=0; i<n; i--) {
        if(arr[i]<secondSmallest) {
            secondSmallest = arr[i];
            break;
        }
    }

    cout << secondSmallest << endl;

    // This will take NlogN + N TC.

    // Better method
    // int largest = arr[0];
    // for(int i=0; i<n; i++) {
    //     if(arr[i] > largest) {
    //         largest = arr[i];
    //     }
    // }

    // cout << largest << endl;

    // int secondLargest = -1;
    // for(int i=0; i<n; i++) {
    //     if(arr[i]>secondLargest && arr[i]!=largest) secondLargest = arr[i];
    // }

    // cout << secondLargest << endl;

    // Here, the time complexity is O(2N).

    //optimal approach

    // int Largest = arr[0];
    // int secondLargest = -1; // assuming there are no negative numbers in the array

    // for(int i=1; i<n; i++) {
    //     if(arr[i] > Largest) {
    //         secondLargest = Largest;
    //         Largest = arr[i];
    //     }
    //     else if(arr[i] < Largest) {
    //         if(arr[i] > secondLargest) secondLargest = arr[i];
    //     }
    // }

    // cout << Largest << endl;
    // cout << secondLargest << endl;

    // Here, the TC is O(N).
    return 0;
}
