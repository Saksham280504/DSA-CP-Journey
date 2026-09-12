#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> pairs;
        int n = nums1.size(), m = nums2.size();
        int i=0, j=0;
        while(k--) { 
            pairs.push_back({nums1[i],nums2[j]});
            if(i==(n-1)) {
                j++;
                i=0;
            }
            else if(j==(m-1)) {
                i++;
                j=0;
            }
            else if((nums1[i+1]+nums2[j])<(nums1[i]+nums2[j+1])) i++;
            else j++;
        }
        return pairs;
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
