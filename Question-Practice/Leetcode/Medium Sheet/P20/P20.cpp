#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxi = INT_MIN;    
        int l = 0;
        int r = n-1;
        while(l<r) {
            int area = (r-l)*min(height[l], height[r]);
            maxi = max(maxi,area);
            if(height[l]<=height[r]) l++;
            else r--;
        }
        return maxi;
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
