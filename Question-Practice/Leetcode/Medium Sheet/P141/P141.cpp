#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int,int>> points;
        for(int i=0; i<n; i++)  {
            int sum = aliceValues[i] + bobValues[i];
            points.push_back({sum,i});
        }
        sort(points.begin(),points.end());
        int sum1 = 0, sum2 = 0;
        for(int i=n-1; i>=0; i-=2) sum1 += aliceValues[points[i].second];
        for(int i=n-2; i>=0; i-=2) sum2 += bobValues[points[i].second];

        if(sum1==sum2) return 0;
        if(sum1>sum2) return 1;
        return -1;
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
