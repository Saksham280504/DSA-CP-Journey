#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    bool check(vector<int>& position, int m, int dist) {
        int cnt = 1;
        int last = position[0];
        for(int i=1; i<position.size(); i++) {
            if(position[i]-last>=dist) {
                cnt++;
                last = position[i];
            }
        }

        return cnt>=m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int mini = position[0], maxi = position[n-1];
        int low = 1, high = maxi-mini, ans = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(check(position,m,mid)) {
                ans = mid;
                low = mid+1; // This minimum distance is possible, we will try to find a distance bigger than this
            }
            else high = mid-1; // The minimum distance is too big
        }

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
