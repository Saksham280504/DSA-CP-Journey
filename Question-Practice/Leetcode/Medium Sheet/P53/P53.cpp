#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int n = clips.size();
        int end = 0, farthest = 0, ans = 0, i=0;

        while(farthest<time) {

            // Try all clips till the current end
            while(i<n && clips[i][0]<=end) {
                farthest = max(clips[i][1],farthest);
                i++;
            }

            // couldn't extend
            if(farthest==end) return -1;

            ans++;
            end = farthest;
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
