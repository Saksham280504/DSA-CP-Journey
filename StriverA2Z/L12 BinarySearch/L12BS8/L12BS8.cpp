#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int FindUniqueElement(vector<int>& arr,int n) {
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];
    
    int low = 1;
    int high = n-2;

    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
        return arr[mid];
        if((mid%2==1 && arr[mid-1]==arr[mid]) || (mid%2==0 && arr[mid+1]==arr[mid])) low = mid+1;
        else high = mid-1;
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

    for(int  i=0; i<n; i++) {
        cin >> arr[i];
    }

    // Single element is sorted array

    // Brute-force approach (Linear Search)

    // for(int i=0; i<n; i++) {
    //         if(arr[i]==arr[i-1] || arr[i]==arr[i+1]) continue;
    //         else {
    //             cout << arr[i] << endl;
    //             return 0;
    //         }
    // }

    // This is working but not covering the edge-cases(i==0 || i==n-1)

    // for(int i=0; i<n; i++) {
    //     if(i==0) {
    //         if(arr[i]==arr[i+1]) continue;
    //     }
    //     else if(i==n-1) {
    //         if(arr[i]==arr[i-1]) continue;
    //     }
    //     else {
    //         if(arr[i]==arr[i-1] || arr[i]==arr[i+1]) continue;
    //         else {
    //             cout << arr[i] << endl;
    //             return 0;
    //         }
    //     }
    // }

    // This is working and covering the edge-cases(i==0 || i==n-1)

    // cout << "No single Element" << endl;

    // TC -> O(N)

    // Optimal Solution (Binary Search)

    int UniqueElement = FindUniqueElement(arr,n);

    if(UniqueElement==-1) {
        cout << "NO UNIQUE ELEMENT" << endl;
        return 0;
    } 

    cout << UniqueElement << endl;

    // TC -> O(log2(N))
    
    return 0;
}
