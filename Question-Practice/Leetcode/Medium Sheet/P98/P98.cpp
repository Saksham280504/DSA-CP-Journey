#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// This problem is based on tracking dynamic group size at every step.
// We introduced an array length[] of size n+2 which was supposed to store the group lengths at boundaries
// A variable to track count of groups of size m
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if(m==n) return n;
        vector<int> length(n+2,0);
        int cntM = 0;
        int res = -1;
        for(int step = 0; step<n; step++) {
            int pos = arr[step];
            int left = length[pos-1];
            int right = length[pos+1];
            int newSize = left+right+1;
            if(left==m) cntM--;
            if(right==m) cntM--;
            if(newSize==m) cntM++;
            length[pos-left] = newSize;
            length[pos+right] = newSize;
            if(cntM>0) res = step+1;
        }
        return res;
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
