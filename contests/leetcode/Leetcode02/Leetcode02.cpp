#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
// class Solution {
// public:
//     int digitFrequencyScore(int n) {
//         map<int,int> mpp;
//         while(n) {
//             int d = n%10;
//             mpp[d]++;
//             n = n/10;
//         }

//         int score = 0;
//         for(auto it: mpp) {
//             score += (it.first*it.second);
//         }

//         return score;
//     }
// };

// Q2
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
         int n = items.size();
         vector<int> first_buy(n,0);
         for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j && (items[i][0]!=0) && (items[j][0]%items[i][0]==0)) first_buy[i]++;
            }
         }

         vector<int> dp(budget+1,0);
         for(int i=0; i<n; i++) {
            int price = items[i][1];
            vector<int> next_dp = dp;
            for(int b = price; b<=budget; b++) {
                next_dp[b] = max(dp[b],dp[b-price] + 1 + first_buy[i]);
            }

            for(int b = price; b<=budget; b++) {
                next_dp[b] = max(next_dp[b], next_dp[b-price] + 1);
            }

            dp = move(next_dp);
         }

         return dp[budget];
    }
};

// Q3
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<bool> first_count(n,false);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j && items[i][0]!=0 && (items[j][0]%items[i][0]==0)) {
                    first_count[i] = true;
                    break;
                }
            }
        }

        vector<int> dp(budget+1,0);
        for(int i=0; i<n; i++) {
            int price = items[i][1];
            vector<int> next_dp = dp;
            for(int b=price; b<=budget; b++) {
                next_dp[b] = max(dp[b],dp[b-price] + 1 + first_count[i]);
            }
            for(int b=price; b<=budget; b++) {
                next_dp[b] = max(next_dp[b], next_dp[b-price] + 1);
            }
            dp = move(next_dp);
        }
        return dp[budget];
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
