#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Approach-1
// #define ll long long
// class Solution {
// public:
//     int nthSuperUglyNumber(int n, vector<int>& primes) {
//         int k = primes.size();
//         vector<ll> dp(n+1);
//         dp[1]=1;
//         vector<int> pointer(k,1);
//         for(int i=2; i<=n; i++) {
//             ll mini = LLONG_MAX;
//             for(int j=0; j<k; j++) {
//                 mini = min(mini,(ll)primes[j]*(dp[pointer[j]]));
//             }
//             dp[i] = mini;
//             for(int j=0; j<k; j++) {
//                 if(mini==((ll)primes[j]*(dp[pointer[j]]))) pointer[j]++;
//             }
//         }
//         return dp[n];
//         // TC -> O(N*K)
//     }
// };

// Approach-2
#define ll long long
class Element {
    public:
    ll prod;
    ll prime;
    int p_idx;
    bool operator>(const Element& other) const {
        return prod > other.prod;
    }
};
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<ll> dp;
        dp.push_back(0);
        dp.push_back(1);
        priority_queue<Element,vector<Element>, greater<Element>> pq;
        int k = primes.size();
        for(int i=0; i<k; i++) {
            pq.push({(ll)primes[i],(ll)primes[i],1});
        }
        while(dp.size()<=n) {
            auto [prod,prime,p_idx] = pq.top();
            pq.pop();
            if(prod!=dp.back()) dp.push_back(prod);
            p_idx++;
            ll nprod = prime*(dp[p_idx]);
            pq.push({nprod,prime,p_idx});
        }
        return dp.back();
    }

    // TC-> O(NlogK)
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
