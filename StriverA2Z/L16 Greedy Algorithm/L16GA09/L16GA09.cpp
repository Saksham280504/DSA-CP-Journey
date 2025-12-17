#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int cnt = 0;
        int maxCnt = 0;
        int arrPointer = 0;
        int depPointer = 0;
        int n = arr.size();
        int m = dep.size();

        // 1. Perform Sort
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());

        // 2. Start the iteration

        while(arrPointer<n && depPointer<m) {
            if(arr[arrPointer] <= dep[depPointer]) { // This shows that a train arrives before or exactly when the earliest current train departs. There is no guaranteed free platform yet, so we must assume a new platform is needed. This is a safe greedy choice
                cnt++;
                maxCnt = max(maxCnt,cnt);
                arrPointer++;
            }
            else {
                cnt--;
                depPointer++;
            }
        }

        while(arrPointer<n) {
            cnt++;
            maxCnt = max(maxCnt,cnt);
            arrPointer++;
        }

        // Departing trains alone will not affect the maxCnt thus there is no extra loop for just remaining departing trains as there is no arriving train

        return maxCnt;

        // TC -> O(2NlogN + 2N)
        // SC -> O(1)
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
