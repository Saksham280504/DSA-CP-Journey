#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int findingMinimum(vector<int>& arr, int n) {
    int low = 0 , high = n-1;
    int ans  = INT_MAX;

    while(low<=high) {

        int mid=(low+high)/2;

        if(arr[mid]==arr[low] && arr[mid]==arr[high]) {
            low++;
            high--;
            continue;
        }
        if(arr[low]<=arr[high]) {
            ans = min(arr[low],ans);
            return ans;
            // arr[low]<=arr[high] is a proof that arraw from low to high is sorted because from the very start too we knew that we were given a rotated sorted array, which means that only some part of array is not sorted, and once the pointer moves away from those elements, we can say that the rest of the array is sorted
        }
        if(arr[low]<=arr[mid]) {
            ans = min(ans,arr[low]);
            low = mid+1;
        }
        else {
            ans = min(ans,arr[mid]);
            high = mid-1;
        }
    }
    return ans;
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

    // Searching Minimum in a rotated Sorted Array

    // brute-force method (Linear Search)

    // int mini = INT_MAX;
    // for(int i=0; i<n; i++) {
    //     if(arr[i]<=mini) mini=arr[i];
    // }

    // TC -> O(N)

    // Better-approach (Binary Search)

    int mini = findingMinimum(arr,n);

    // TC -> O(log2(N))

    cout << mini << endl;

    return 0;
}
