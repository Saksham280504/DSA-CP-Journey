#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long mod = 1e9+7;

        long long totalSum = 0;
        for(int x: arr) totalSum += x;

        long long maxForOne = 0;
        long long currSumOne = 0;
        for(int i=0; i<n; i++) {
            currSumOne += arr[i];
            if(currSumOne<0) currSumOne = 0;
            maxForOne = max(maxForOne,currSumOne);
        }

        if(k==1) return maxForOne%mod;

        long long maxForTwo = 0;
        long long currSumTwo = 0;
        for(int i=0; i<2*n; i++) {
            currSumTwo += arr[i%n];
            if(currSumTwo<0) currSumTwo = 0;
            maxForTwo = max(maxForTwo,currSumTwo);
        }

        if(totalSum>0) {
            long long intermediateSum = (((k-2)%mod)*(totalSum%mod))%mod;
            return (intermediateSum+maxForTwo)%mod;
        }
        return maxForTwo%mod;
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
