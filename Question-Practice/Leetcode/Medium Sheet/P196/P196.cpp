#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        iota(perm.begin(),perm.end(),0);
        vector<int> OriginalPerm = perm;
        int cnt = 0;
        while(true) {
            cnt++;
            vector<int> arr(n);
            for(int i=0; i<n; i++) {
                if(i&1) arr[i] = perm[n/2 + (i-1)/2];
                else arr[i] = perm[i/2];
            }
            if(arr==OriginalPerm) break;
            perm = arr;
        }
        return cnt;
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
