#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int SearchInSortedArray(vector<int>& arr, int n, int x) {
    int low = 0;
    int high  = n-1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]==x) return mid;
        // Left half is Sorted
        else if(arr[low] <= arr[mid]) {
            if(arr[low] <= x && x <= arr[mid]) high = mid-1;
            else low = mid+1;
        }
        // Right half is Sorted
        else {
            if(arr[mid] <= x && x <= arr[high]) low = mid+1;
            else high = mid-1;
        }
    }

    return -1;
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

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    // Search in Rotated Sorted Array

    // Brute-force method (Linear Search)

    // for(int i=0; i<n; i++) {
    //     if(arr[i]==target) {
    //         cout << i << endl;
    //         break;
    //     }
    // }

    // Better Approach (Binary Search because the array is "Sorted")

    // Procedure:

    // 1. Identify the sorted half->left/right
    // 2. Check for the number in sorted
    // 2. If present,remove the unsorted part
    // 3. If not, then remove the sorted part
    // 4. Repeat from 1

    int index = SearchInSortedArray(arr, n, target);

    if(index==-1) cout << "No Occurance" << endl;
    else cout << index << endl;

    // TC -> O(log2(N))
    // SC -> O(1)

    return 0;
}
