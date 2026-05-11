#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// We can't solve this problem using sliding window approach because the conditions are not montonic, if we move left immediately when window becomes invalid, this will neglect the possibility of this currently invalid interval becoming our answer. Therefore we need to check both expansion and shrinkage to be predictable.

// A key trick to identify when sliding window fails -> negatives exist, or condition is not monotonic, or validity can flip back and forth

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int> first;
        int sum = 0, ans = 0;
        for(int i=0; i<hours.size(); i++) {
            sum += (hours[i]>8 ? 1 : -1);
            if(sum>0) ans = i+1;
            else {
                if(first.count(sum-1)) {
                    ans = max(ans,i-first[sum-1]);
                }
            }

            if(!first.count(sum)) {
                first[sum] = i;
            }
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
