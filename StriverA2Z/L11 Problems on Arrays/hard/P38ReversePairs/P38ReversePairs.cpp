#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int CreatePairs(vector<int>& arr, int low, int mid, int high) {
    int count = 0;
    int right = mid+1;
    for(int i=low; i<=mid; i++) {
        while(right <= high && arr[i] > 2*arr[right]) right++;
        count = count + (right-(mid+1));
    }
    return count;
}
void merge(vector<int>& arr, int low, int mid, int high) {
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
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

    for(int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
}
int mergeSort(vector<int>& arr, int low, int high) {
    int count = 0;
    if(low>=high) return count;
    int mid = (low+high)/2;
    count += mergeSort(arr,low,mid);
    count += mergeSort(arr,mid+1,high);
    count += CreatePairs(arr, low, mid, high);
    merge(arr,low,mid,high);
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

    // brute-force approach

    // int count = 0;
    // for(int i=0; i<n; i++) {
    //     for(int j=i+1; j<n; j++) {
    //         if(arr[i] > 2*arr[j]) count++;
    //     }
    // }

    // TC ->O(N*N)
    // SC ->O(1)

    // Optimal Approach (Merge Sort)

    int count = 0;
    count = mergeSort(arr, 0, n-1);
    
    // TC -> O(2*NlogN)
    // SC -> O(N)

    // Here we are distorting the array in optimal solution.

    cout << count << endl;
    return 0;
}
