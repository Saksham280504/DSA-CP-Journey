#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int SmallestGreaterElementIndex(vector<int>& arr, int val,int n) {
        int low = 0, high = n-1, ans = n;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(arr[mid]>val) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();

        // 1. Sort the array
        sort(arr.begin(), arr.end());

        // 2. Prefix sum
        vector<long long> prefixSum(n,0);
        prefixSum[0] = arr[0];

        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
        if(prefixSum[n-1]<=target) {
            return arr[n-1];
        }

        long long diff = llabs(prefixSum[n-1]-1LL*target);
        int val = arr[n-1];
        for(int i=0; i<arr[n-1]; i++) {
            int idx = SmallestGreaterElementIndex(arr,i,n);
            long long sum = 1LL*i*(n-idx);
            if(idx!=0) {
                sum += prefixSum[idx-1];
            }
            long long currDiff = llabs(sum-1LL*target);
            if(currDiff<diff) {
                val = i;
                diff = currDiff;
            }
            else if(currDiff==diff) {
                val = min(val,i);
            }
        }

        return val;
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
