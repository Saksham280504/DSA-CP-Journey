#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> hDist;

        int r = hFences.size();
        int c = vFences.size();

        for(int i=0; i<r; i++) {
            for(int j=i+1; j<r; j++) {
                long long dist = (long long)(hFences[j] - hFences[i]);
                hDist.insert(dist);
            }
        }
        long long commonDist = 0;
        for(int i=0; i<c; i++) {
            for(int j=i+1; j<c; j++) {
                long long dist = (long long)(vFences[j] - vFences[i]);
                if(hDist.count(dist)>0) commonDist = max(commonDist,dist);
            }
        }
        if(commonDist==0) return -1;
        int mod = 1e9+7;
        return (commonDist*commonDist)%mod;
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
