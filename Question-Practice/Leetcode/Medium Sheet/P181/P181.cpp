#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> posSpeed(n);
        for(int i=0; i<n; i++) {
            posSpeed[i].first = position[i];
            posSpeed[i].second = speed[i];
        }
        sort(posSpeed.rbegin(), posSpeed.rend());
        int fleet = 0;
        float maxTime = 0.0;
        for(int i=0; i<n; i++) {
            float time = (float)(target-posSpeed[i].first)/(posSpeed[i].second);
            if(time > maxTime) {
                fleet++;
                maxTime = time;
            }
        }
        return fleet;
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
