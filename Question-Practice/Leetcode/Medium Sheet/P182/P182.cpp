#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

using tiii = tuple<int,int,int>;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> result;
        if(n1==0 || n2==0 || k==0) return result;
        priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
        for(int i=0; i<min(n1,k); i++) {
            pq.push({nums1[i]+nums2[0],i,0});
        }
        while(!pq.empty() && result.size()<k) {
            auto [sum,i,j] = pq.top();
            pq.pop();
            result.push_back({nums1[i],nums2[j]});
            if(j+1<n2) {
                pq.push({nums1[i]+nums2[j+1],i,j+1});
            }
        }
        return result;
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
