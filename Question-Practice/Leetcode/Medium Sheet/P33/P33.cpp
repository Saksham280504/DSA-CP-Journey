#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    bool isShipPossibleInDdays(vector<int>& weights, int days, int capacity) {
        int requiredDays = 1;
        int currLoad = 0;

        for(int w: weights) {
            if(currLoad+w > capacity) {
                requiredDays++;
                currLoad = 0;
            }
            currLoad += w;
        }

        return requiredDays<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);

        while(low<high) {
            int mid = low + (high-low)/2;
            if(isShipPossibleInDdays(weights,days,mid)) {
                high = mid;
            }
            else low = mid+1;
        }

        return low;
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
