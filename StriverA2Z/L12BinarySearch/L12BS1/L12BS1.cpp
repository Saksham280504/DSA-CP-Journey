#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void BinarySearchIterative(vector<int>& arr, int n, int target) {
    int low = 0;
    int high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid]==target) {
            cout << mid << endl;
            return;
        }
        else if(arr[mid] < target) low = mid+1;
        else high = mid-1;
    }

    cout << "Target Not Found";
}

int BinarySearchRecursive(vector<int>& arr, int low, int high, int target) {
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(arr[mid]==target) return mid;
    else if(arr[mid] < target) return BinarySearchRecursive(arr, mid+1, high, target);
    else return BinarySearchRecursive(arr, low, mid -1, target);   
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

    // When we traverse through the entire area element by element to find our requested element, then that type of search is called Linear search

    // Binary search is an algorithm which is always applicable whenever we are applying a search in a sorted area.

    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    int target;
    cin >> target;

    // BinarySearchIterative(arr,n,target); 
    // Iterative Approach
    // Recursive approach

    int ind;

    ind = BinarySearchRecursive(arr,0,n-1,target);

    if(ind == -1) {
        cout << "Target not found" << endl;
        return 0;
    }
    
    cout << ind << endl;

    // TC -> O(log2(N))

    // Overflow case: Imagine if the array is of size INT_MAX, then in that case what we need to do is to make sure that we use any of the following 2 methods to prevent overflow.

    // 1st method: define low, high and mid as long long

    // 2nd method: This is only applicable when array size is smaller than or equal to INT_MAX. Here, we use mid = low + (high-low)/2.

    return 0;
}
