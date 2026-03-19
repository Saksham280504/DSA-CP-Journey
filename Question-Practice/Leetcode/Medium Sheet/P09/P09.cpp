#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private: int getMax(vector<int>& arr) {
        int maxLen = 1, curr = 1;
        int n = arr.size();
        for(int i=1; i<n; i++) {
            if(arr[i]==arr[i-1]+1) curr++;
            else curr = 1;
            maxLen = max(maxLen,curr);
        }
        return maxLen + 1;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        // Removing consecutive bars create higher gap, hence we look for maxium number of consecutive bars in horizontal and vertical sides.
        
        int hmax = getMax(hBars);
        int vmax = getMax(vBars);
        int side = min(hmax, vmax);
        return side*side;
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
