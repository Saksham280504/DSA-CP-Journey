#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        long xorr = 0;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            xorr = xorr^(long)arr[i];
        }
        
        xorr = (xorr&(xorr-1))^xorr;
        
        long b1=0, b2=0;
        for(int i=0; i<n; i++) {
            if(xorr&((long)arr[i])) b1 = b1^(long)arr[i];
            else b2 = b2^(long)arr[i];
        }
        
        return {b1,b2};
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
