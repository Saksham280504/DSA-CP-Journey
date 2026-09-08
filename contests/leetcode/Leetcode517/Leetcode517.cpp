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

// Q2
#define ll long long
class Solution {
private:
    ll power(ll base, ll exp, ll mod) {
        base %= mod;
        ll res = 1;
        while(exp) {
            if(exp&1) res = (res*base)%mod;
            base = (base*base)%mod;
            exp >>= 1;
        }
        return res;
    }
public:
    int sumDecoded(vector<long long>& nums) {
        ll mod = 1e9+7;
        ll sum = 0;
        for(ll num: nums) {
            ll width = num%10;
            ll d = num/10;
            string ds = to_string(d);
            ll dsize = ds.size();
            ll x=0, y=0;
            for(ll i=0; i<dsize; i++) {
                char c = ds[i];
                ll z = c-'0';
                if(i<width) x = (x*10)+z;
                else y = (y*10)+z;
            }
            sum = (sum + power(x,y,mod))%mod;
        }
        return sum;
    }
};

// Q3
class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int INF = 1e9;
        vector<int> dp(sum+1,INF);
        dp[0] = 0;
        for(int x: nums) {
            vector<pair<int,int>> cand;
            // Multiplication
            int val = x;
            int cost = 0;
            while(val<=sum) {
                cand.push_back({val,cost});
                cost++;
                val*=2;
            }
            // Division
            val = x/2;
            cost = 1;
            while(val>0) {
                cand.push_back({val,cost});
                cost++;
                val/=2;
            }
            for(int w=sum; w>=0; w--) {
                for(auto &[v,c]: cand) {
                    if(w>=v && dp[w-v]!=INF) {
                        dp[w] = min(dp[w],dp[w-v]+c);
                    }
                }
            }
        }
        return (dp[sum]==INF) ? -1 : dp[sum];
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
