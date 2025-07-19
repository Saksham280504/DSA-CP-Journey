#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numberOfRotations(vector<int>& arr, int n) {
    int low = 0;
    int high = n-1;
    int mini = INT_MAX;
    int miniIndex = -1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid]==arr[high] && arr[low]==arr[mid]) {
            low++;
            high--;
            continue;
        }

        if(arr[low]<=arr[high]) {
            if(arr[low]<=mini) {
                mini = arr[low];
                miniIndex = low;
                return miniIndex;
            }
        }

        if(arr[mid]<=arr[high]) {
            if(arr[mid]<=mini) {
                mini = arr[mid];
                miniIndex = mid;
                high = mid-1;
            }
        }
        else {
            if(arr[low]<=mini) {
                mini = arr[low];
                miniIndex = low;
                low = mid+1;
            }
        }
    }
    return miniIndex;
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

    // Number of rotations on an Array -> Here we just need to find out the minimum of the array and then the index at which the minimum is present is the number of times the array has been rotated.

    int miniIndex = numberOfRotations(arr,n);

    cout << miniIndex << endl;
    return 0;
}
