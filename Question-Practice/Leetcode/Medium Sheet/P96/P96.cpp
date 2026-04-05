#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while(i+1<n && arr[i]<=arr[i+1]) i++;
        if(i==n-1) return 0;

        int j = n-1;
        while(j-1>=0 && arr[j-1]<=arr[j]) j--;

        int ans = min(n-(i+1),n-(n-1-j+1)); // [0....i] -> i+1 elements in prefix are sorted, so we removed n-(i+1) elements from suffix
        // [j...n-1] -> n-j elements in suffix are sorted, so we removed (n-(n-j)) elements from prefix

        int l = 0, r=j;

        while(l<=i && r<n) {
            if(arr[l]<=arr[r]) {
                ans = min(ans,r-l-1);
                l++;
            }
            else r++;
        }

        return ans;
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
