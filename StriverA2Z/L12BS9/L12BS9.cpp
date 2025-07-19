#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int FindPeakElement(vector<int>& arr, int n) {
    if(n==0) return arr[0];
    if(arr[0] > arr[1]) return arr[0];
    if(arr[n-1] > arr[n-2]) return arr[n-1];
    int low = 1;
    int high = n-2;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
            return arr[mid];
        }
        else if(arr[mid-1] < arr[mid]) {
            low = mid+1;
        }
        else high = mid-1;
    }

    // This is only the code when all elements are unique

    // This code only gives one peak even if the array has nultiple peaks

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

    // Find Peak Element (arr[i-1] < arr[i] > arr[i+1])

    // brute-force approach

    // if(arr[0] > arr[1]) cout << arr[0] << " ";
    // for(int i=1; i<n-1; i++) {
    //     if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) cout << arr[i] << " ";
    // }
    // if(arr[n-1] > arr[n-2]) cout << arr[n-1] << " ";
    // return 0;

    // TC -> O(N)
    // SC -> O(1)

    // Optimal Approach (Binary Search)

    int peak = FindPeakElement(arr,n);

    cout << peak << endl;


    return 0;
}
