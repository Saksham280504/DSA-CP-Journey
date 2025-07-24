#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int findKthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    if(n1>n2) return findKthElement(arr2, arr1, k);

    int low=0, high=n1;
    int left = k;
    while(low<=high) {
        int mid1 = (low+high)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1<n1) r1 = arr1[mid1];
        if(mid2<n2) r2 = arr2[mid2];
        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2 = arr2[mid2-1];

        if(l1<=r2 && l2<=r1) {
            return max(l1,l2);
        }
        if(l1>r2) high = mid1-1;
        else low = mid1+1;
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

    int n, m;
    cin >> n >> m;
    
    vector<int> arr1(n);
    vector<int> arr2(m);

    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }

    for(int i=0; i<m; i++) {
        cin >> arr2[i];
    }

    int k;
    cin >> k;

    // Brute-force method

    vector<int> arr3;
    int low1 = 0;
    int low2 = 0;

    while(low1<n && low2<m) {
        if(arr1[low1]<=arr2[low2]) arr3.push_back(arr1[low1++]);
        else arr3.push_back(arr2[low2++]);
    }
    while(low1<n) {
        arr3.push_back(arr1[low1++]);
    }
    while(low2<m) {
        arr3.push_back(arr2[low2++]);
    }

    cout << arr3[k-1] << endl;

    // TC -> O(n+m)
    // SC -> O(n+m)

    // Better method
    int i = 0;
    int j = 0;
    int cnt = 0;

    while(i<n && j<m) {
        if(arr1[i]<=arr2[j]) {
            if(cnt==k-1) cout << arr1[i] << endl;
            i++;
            cnt++;
        }
        else {
            if(cnt==k-1) cout << arr2[j] << endl;
            j++;
            cnt++;
        }
    }

    while(i<n) {
        if(cnt==k-1) cout << arr1[i] << endl;
        i++;
    }

    while(j<m) {
        if(cnt==k-1) cout << arr2[i] << endl;
        j++;
    }

    // TC -> O(n+m)
    // SC -> O(1)
    // Optimal approach

    cout << findKthElement(arr1, arr2, k);
    // TC -> O(min(n,m))

    return 0;
}
