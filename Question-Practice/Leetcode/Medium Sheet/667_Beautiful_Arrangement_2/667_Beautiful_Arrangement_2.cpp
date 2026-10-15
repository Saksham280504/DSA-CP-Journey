#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int low = 1, high = k+1;
        for(int i=0; i<=k; i++) {
            if(i&1) ans[i] = high--;
            else ans[i] = low++;
        }
        for(int i=k+1; i<n; i++) ans[i] = i+1;
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
