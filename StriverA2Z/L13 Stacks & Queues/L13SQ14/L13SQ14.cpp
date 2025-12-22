#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0;
        int r=n-1;
        int lmax=0, rmax=0, total=0;
        while(l<r) {
            if(height[l]<=height[r]) {
                if(lmax>height[l]) total += lmax-height[l];
                else lmax = height[l];
                l = l+1;
            }
            else {
                if(rmax>height[r]) total += rmax-height[r];
                else rmax = height[r];
                r = r-1;
            }
        }
        return total;

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
