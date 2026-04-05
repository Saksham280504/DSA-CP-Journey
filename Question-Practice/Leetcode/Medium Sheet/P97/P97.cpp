#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Here rather than picking element by element, we think about picking the window of size k which is closest to x.
// There are always to windows to compare:- 
// 1. arr[mid].....arr[mid+k-1]
// 2. arr[mid+1]....arr[mid+k]
// So here we only need to compare arr[mid] and arr[mid+k] as all the remaining elements are common
// If in case x-arr[mid]>arr[mid+k]-x, then that means all the elements from arr[l] to arr[mid] are at a greater distance from x than arr[mid+1] to arr[r], thus move the area of attention to right (l = mid+1)
// Otherwise stay at left (r=mid)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0;
        int r = n-k;
        while(l<r) {
            int mid = l + (r-l)/2;
            if(x-arr[mid]>arr[mid+k]-x) l = mid+1;
            else r = mid;
        }
        return vector<int>(arr.begin()+l,arr.begin()+l+k);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
