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
private:
    int maxCopies(int ind, int budget,vector<vector<int>>& dp, vector<vector<int>>& items, unordered_map<int,int>& dividend) {
        if(ind==0) {
            if(items[0][1]>budget) return dp[ind][budget] = 0;
            int numCopies = 0;
            if(dividend.count(items[ind][0])) numCopies += dividend[items[ind][0]];
            numCopies += (budget/items[0][1]);
            return dp[ind][budget] = numCopies;
        }
        if(dp[ind][budget]!=-1) return dp[ind][budget];
        // NotTake
        int notTake = 0 + maxCopies(ind-1,budget,dp,items,dividend);
        // Take
        int original_budget = budget;
        int take = 0;
        int price = items[ind][1];
        if(price<=budget) {
            int numCopies = 0;
            if(dividend.count(items[ind][0])) numCopies += dividend[items[ind][0]];
            while(budget) {
                if(price>budget) break;
                numCopies++;
                budget -= price;
                take = max(take,numCopies + maxCopies(ind-1,budget,dp,items,dividend));
            }
        }

        return dp[ind][original_budget] = max(take,notTake);
    }
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<vector<int>> dp(n,vector<int>(budget+1,-1));
        unordered_map<int,int> dividend;
        for(int i=0; i<n; i++) {
            if(dividend.count(items[i][0])) continue;
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(items[j][0]%items[i][0]) {
                    dividend[items[i][0]]++;
                }
            }
        }
        int maxi = maxCopies(n-1,budget,dp,items,dividend);
        return maxi;
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
