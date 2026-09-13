#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0) return false;
        if(k==1) return true;
        map<int,int> freq;
        for(int x: nums) {
            freq[x]++;
        }
        for(auto [val,count]: freq) {
            if(count>0) {
                for(int i=0; i<k; i++) {
                    int next_val = val+i;
                    if(freq[next_val]<count) return false;
                    freq[next_val] -= count;
                }
            }
        }
        return true;
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
