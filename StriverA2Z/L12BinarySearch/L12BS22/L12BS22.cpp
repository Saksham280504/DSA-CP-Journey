#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
double median(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    if(n>m) return median(arr2, arr1);
    int low = 0, high = n; // low,high -> minimum,maximum number of elements that can be picked from arr1 (smaller array)
    int num = n+m;
    int left = (num+1)/2;
    while(low<=high) {
        int mid1 = (low+high)/2;
        int mid2 = left-mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n) r1 = arr1[mid1];
        if(mid2 < m) r2 = arr2[mid2];
        if(mid1 - 1 >= 0) l1 = arr1[mid1-1];
        if(mid2 - 1 >= 0) l2 = arr2[mid2-1];
        // We need l1 <= r2 and l2 <= r1
        if(l1 <= r2 && l2 <= r1) {
            if(num%2==1) return max(l1,l2);
            return ((double) (max(l1,l2) + min(r1,r2)))/2.0;
        }
        else if(l1 > r2) high = mid1-1;
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

    int n,m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);

    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }

    for(int i=0; i<m; i++) {
        cin >> arr2[i];
    }

    // Median of two sorted arrays

    // Brute-force approach

    // vector<int> arr;

    // int i=0;
    // int j=0;

    // while(i<n && j < m) {
    //     if(arr1[i] <= arr2[j]) {
    //         arr.push_back(arr1[i]);
    //         i++;
    //     }
    //     else {
    //         arr.push_back(arr2[j]);
    //         j++;
    //     }
    // }

    // while(i<n) {
    //     arr.push_back(arr1[i]);
    //     i++;
    // }
    // while(j<m) {
    //     arr.push_back(arr2[j]);
    //     j++;
    // }

    // int num = n+m;
    // int ele1 = arr[num/2];
    // int ele2 = arr[(num/2)-1];
    // if(num%2==0) {
    //     double median = (double(ele1)+double(ele2))/2.0;
    //     cout << median << endl;
    // }
    // else {
    //     int median = ele1;
    //     cout << median << endl;
    // }

    // This is partially excepted
    // TC -> O(n+m)
    // SC -> O(n+m) 

    // Better-Approach

    // int i = 0;
    // int j = 0;
    // int cnt = 0;
    // int ele1;
    // int ele2;
    // int num = (n+m);
    // int ind1 = (num)/2;
    // int ind2 = ind1-1;

    // while(i<n && j<m) {
    //     if(arr1[i]<=arr2[j]) {
    //         if(cnt==ind1) ele1 = arr1[i];
    //         if(cnt==ind2) ele2 = arr1[i];
    //         i++;
    //         cnt++;
    //     }
    //     else {
    //         if(cnt==ind1) ele1 = arr2[j];
    //         if(cnt==ind2) ele2 = arr2[j];
    //         j++;
    //         cnt++;
    //     }
    // }

    // while(i<n) {
    //     if(cnt==ind1) ele1 = arr1[i];
    //     if(cnt==ind2) ele2 = arr1[i];
    //     i++;
    //     cnt++;
    // }
    // while(j<m) {
    //     if(cnt==ind1) ele1 = arr2[j];
    //     if(cnt==ind2) ele2 = arr2[j];
    //     j++;
    //     cnt++;
    // }

    // if((num)%2==0) {
    //     double median = ((double)(ele1) + (double)(ele2))/2.0;
    //     cout << median << endl;
    // }

    // else {
    //     int median = ele1;
    //     cout << median << endl;
    // }

    // This is also partially accepted
    // TC -> O(N+M)
    // SC -> O(1)

    // Optimal Approach

    double med = median(arr1,arr2);
    cout << med << endl;
    
    // TC -> O(min(n,m))
    // SC -> O(1)
    return 0;
}
