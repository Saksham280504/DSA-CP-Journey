#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool isElementPresent(vector<int>& arr, int n, int x) {
    int low = 0;
    int high = n-1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]==x) return true;
        if(arr[mid]==arr[low] && arr[mid]==arr[high]) {
            low++;
            high--;
            continue;
        }
        if(arr[mid] <= arr[high]) {
            if(arr[mid] < x && x <= arr[high]) low = mid + 1;
            else high = mid-1;
        }
        else {
            if(arr[low] <= x && x < arr[mid]) high = mid-1;
            else low = mid+1;
        }
    }
    return false;
}
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

    int target;
    cin >> target;
    // Search in Sorted Array containing duplicates

    // Brute-force method (Linear Search)

    // for(int i=0; i<n; i++) {
    //     if(arr[i]==target) cout << i << " ";
    // }

    // Better Approach (Binary Search) -> Using Binary search, we can't print the indices, for that we will stick to linear search but still using binary search we can the print the occurance(YES/NO) here.

    bool doesExist = isElementPresent(arr,n,target);

    // TC -> O(log2(N)) for the average case
    // TC -> O(N/2) (worst case) [3,3,3,1,3,3,3,3,3,3,3]

    if(doesExist) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
