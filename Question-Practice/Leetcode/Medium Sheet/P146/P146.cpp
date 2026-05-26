#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int kept = arr[0];
        int ignored = 0; // If the 0th element is deleted from a single element array, the sum becomes zero
        int max_sum = arr[0];

        for(int i=1; i<n; i++) {
            int prev_kept = kept;
            int prev_ignored = ignored;

            kept = max(prev_kept+arr[i],arr[i]); // Kadane's algorithm for maximum subarray sum without any deletions
            ignored = max(prev_ignored+arr[i],prev_kept);

            max_sum = max({max_sum,kept,ignored});
        }

        return max_sum;
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
