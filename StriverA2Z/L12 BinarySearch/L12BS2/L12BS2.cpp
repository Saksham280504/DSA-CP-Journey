#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int lowerBound(vector<int>& arr, int n, int x) {
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]>=x) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    return ans;

    // TC -> O(log2(N))
}

int upperBound(vector<int>& arr, int n, int x) {
    int low = 0;
    int high = n-1;
    int ans = 10;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]>x) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;

    // TC -> O(log2(N))
}

int Floor(vector<int>& arr, int n, int x) {
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid] <= x) {
            ans = arr[mid];
            low = mid+1;
        }
        else high = mid -1;
    }

    return ans;
}

int Ceil(vector<int>& arr, int n, int x) {
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]>=x) {
            ans = arr[mid];
            high = mid-1;
        }
        else low = mid+1;
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
    vector<int> arr;

    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    int x;
    cin >> x;

    // int lb;

    // lb = lowerBound(arr,n,x);

    // cout << lb << endl;

    // int ub;

    // ub = upperBound(arr,n,x);

    // cout << ub << endl;

    // LowerBound is the smallest index such that arr[ind] >= x
    // UpperBound is the smallest index such that arr[ind] > x

    // Search Insert Position: In this problem what we need to do is just look for the index at which x is present and if x is not present then look for the index where x can be inserted. We are given an array of sorted unique integers. So, to solve this problem we use lowerBound.

    int ind = lowerBound(arr, n, x); // This is my function

    cout << ind << endl;

    // We can also use C++ stl here.

    // ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin(); // Here we have used STL

    // cout << ind << endl;

    // Floor and Ceil of an array

    // Floor is the largest index such that arr[index] <= x
    // Ceil is the smallest index such that arr[index] >= x

    // So if the x is an element in the array, then the floor == ceil == x

    // Ceil is same as the lowerBound
    // Floor has slight modifications in the code

    // int floor;

    // floor = Floor(arr,n, x);

    // cout << floor << endl;

    // int ceil;

    // ceil = Ceil(arr, n, x);

    // cout << ceil << endl;

    return 0;
}
