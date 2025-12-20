#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        for(int i=0; i<k; i++) lsum += cardPoints[i];
        int rsum = 0;
        int lp = k-1;
        int rp = n-1;
        int maxSum = 0;
        while(lp>=0) {
            maxSum = max(maxSum,lsum+rsum);
            lsum -= cardPoints[lp];
            rsum += cardPoints[rp];
            lp--;
            rp--;
        }
        maxSum = max(maxSum,lsum+rsum);
        return maxSum;

        // TC -> O(N)
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
