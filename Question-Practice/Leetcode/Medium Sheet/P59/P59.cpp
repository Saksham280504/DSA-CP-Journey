#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    bool areMBouquets(int day, vector<int>& bloomDay,int k, int m) {
        int bouquets = 0;
        int cnt = 0;
        for(int bloom: bloomDay) {
            if(bloom<=day) {
                cnt++;
                if(cnt==k) {
                    bouquets++;
                    cnt = 0;
                }
            }
            else {
                cnt = 0;
            }
        }

        return bouquets>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long)m*(long long)k;
        if(total>bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(areMBouquets(mid,bloomDay,k,m)) {
                ans = mid;
                high = mid-1; // look for a smaller day
            }
            else low = mid+1; // Look for higher days as on the mid day I was not able to make bouquests >= m
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
