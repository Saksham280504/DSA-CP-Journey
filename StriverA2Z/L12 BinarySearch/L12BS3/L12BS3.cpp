#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int LowerBound(vector<int>& arr, int n, int k) {
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]>=k) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    return ans;
}

int UpperBound(vector<int>& arr, int n, int k) {
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]>k) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    return ans;
}

int firstOccurance(vector<int>& arr, int n, int x) {
    int low = 0;
    int high = n-1;
    int first = -1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid]==x) {
            first = mid;
            high = mid-1;
        }
        else if(arr[mid] > x) high = mid -1;
        else low = mid+1; 
    }

    return first;
}

int LastOccurance(vector<int>& arr, int n, int x) {
    int low = 0;
    int high = n-1;
    int last = -1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid]==x) {
            last = mid;
            low = mid+1;
        }
        else if(arr[mid] > x) high = mid -1;
        else low = mid+1; 
    }

    return last;
}

pair<int,int> firstAndLastOccurance(vector<int>& arr, int n, int x) {
    int first = firstOccurance(arr,n,x);
    if(first==-1) return {-1,-1};
    int last = LastOccurance(arr,n,x);
    return {first, last};
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

    // First and Last Occurance in an Array

    // Brute-force method (Linear search)

    // int first = -1;
    // int last = -1;

    // for(int i=0; i<n; i++) {
    //     if(arr[i]==x) {
    //         if(first == -1) first = i;
    //         last = i;
    //     }
    // }

    // TC -> O(N)
    // cout << first << " & " << last << endl;

    // Better-approach (Using lowerBound and UpperBound)

    // int lb;
    // lb = LowerBound(arr,n,x);

    // if(lb==n || arr[lb]!=x) cout << -1 << " " << -1 << endl; // There is no occurance of x in the array
    // else cout << lb << " " << UpperBound(arr,n,x) -1  << endl; // There is atleast one occurance of x in the array

    // TC -> 2*O(log2(N))
    // SC -> O(1)

    // Optimal Approach (Using Plain Binary Search)

    // int first, last;

    // first = firstOccurance(arr,n,x);

    // if(first == -1) {
    //     cout << -1 << " " << -1 << endl;
    //     return 0;
    // }
    // last = LastOccurance(arr,n,x);

    // cout << first << " " << last << endl;

    // TC -> 2*O(log2(N))
    // SC -> O(1)

    // Now if a problem is given in which an array that can contain duplicates is given to us and we are asked to print the frequency of number x, then frequency = lastOccurance - first Occurance + 1

    pair<int,int> ans = firstAndLastOccurance(arr,n,x);

    if(ans.first == -1) cout << 0 << endl;
    else cout << ans.second - ans.first + 1 << endl;

    return 0;
}
