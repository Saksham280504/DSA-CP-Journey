#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxLeft = 0, maxRight = 0, totalWater = 0;
        while(left<right) {
            if(height[left]<=height[right]) {
                if(maxLeft<=height[left]) maxLeft = height[left];
                else totalWater += maxLeft-height[left];
                left++;
            }
            else {// height[left]>height[right]
                if(maxRight<=height[right]) maxRight = height[right];
                else totalWater += maxRight-height[right];
                right--;
            }
        }
        return totalWater;
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
