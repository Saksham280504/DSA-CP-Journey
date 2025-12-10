#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int merge(vector<int>& arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    int count = 0;
    while(left <= mid && right <= high) {
        // arr[left] is smaller than or equal to arr[right]
        if(arr[left]<=arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        // arr[right] is smaller than arr[left]
        else {
            temp.push_back(arr[right]);
            count += mid-left+1;
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i= low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
    return count;
}
int mergeSort(vector<int>& arr,int low, int high) {
    int count = 0;
    if(low>=high) return count;
    int mid = (low+high)/2;
    count += mergeSort(arr,low,mid);
    count += mergeSort(arr,mid+1,high);
    count += merge(arr,low,mid,high);
    return count;
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
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }
    
    // Brute-force method
    
    // int count = 0;
    // for(int i=0; i<n; i++) {
    //     for(int j=i+1; j<n; j++) {
    //         if(arr[i] > arr[j]) count++;
    //     }
    // }

    // TC -> O(N*N)
    // SC -> O(1)

    // Optimal Solution (Using Merge Sort)

    int count = 0;
    count = mergeSort(arr,0,n-1);
    // TC -> O(NlogN)
    // SC -> O(N)

    // Here we are distorting the array in optimal solution.

    cout << count << endl;

    return 0;
}
