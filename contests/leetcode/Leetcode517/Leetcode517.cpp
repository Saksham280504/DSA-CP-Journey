#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int cnt = 1;
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<pair<bool,bool>> hash(maxi+1,{false,false}); // {occured, occured_again}
        hash[nums[0]] = {true,false};
        for(int i=1; i<n; i++) {
            if(nums[i]==nums[i-1]) continue;
            if(!hash[nums[i]].first) {
                cnt++;
                hash[nums[i]].first = true;
            }
            else if(!hash[nums[i]].second) {
                cnt--;
                hash[nums[i]].second = true;
            }
        }
        return cnt;
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
