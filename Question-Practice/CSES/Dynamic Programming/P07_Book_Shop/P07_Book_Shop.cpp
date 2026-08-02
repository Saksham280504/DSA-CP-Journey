#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int n,x;
vector<pair<int,int>> PriceAndPage;
vector<vector<int>> dp;

int maxNumberOfPages(int book, int price) {
    if(price==0) return 0;
    if(book<0) return 0;
    if(dp[book][price]!=-1) return dp[book][price];
    int notPick = 0 + maxNumberOfPages(book-1,price);
    int pick = 0;
    if(PriceAndPage[book].first<=price) pick = PriceAndPage[book].second + maxNumberOfPages(book-1,price-PriceAndPage[book].first);
    return dp[book][price] = max(pick,notPick);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    cin >> n >> x;
    PriceAndPage.resize(n);
    for(int i=0; i<n; i++) { // price
        cin >> PriceAndPage[i].first;
    }
    for(int i=0; i<n; i++) { // pages
        cin >> PriceAndPage[i].second;
    }

    // Recursive Approach -> TLE -> Recursion depth is too Large
    // dp.assign(n,vector<int>(x+1,-1));
    // cout << maxNumberOfPages(n-1,x) << endl;

    // Tabulation Approach -> Accepted
    // dp.assign(n,vector<int>(x+1,0));
    // // If only one book is present then dp[0][price] = PriceAndPage[0].second only when price>=x
    // for(int price=PriceAndPage[0].first; price<=x; price++) {
    //     dp[0][price] = PriceAndPage[0].second;
    // }
    // for(int i=1; i<n; i++) {
    //     for(int price=1; price<=x; price++) {
    //         int notPick = 0 + dp[i-1][price];
    //         int pick = 0;
    //         if(price>=PriceAndPage[i].first) pick = PriceAndPage[i].second + dp[i-1][price-PriceAndPage[i].first];
    //         dp[i][price] = max(pick,notPick);
    //     }
    // }
    // cout << dp[n-1][x] << endl;

    // Space Optimization Approach -> Accepted
    vector<int> prev(x+1,0);
    for(int i=0; i<n; i++) {
        vector<int> curr(x+1);
        for(int price=1; price<=x; price++) {
            int notPick = 0 + prev[price];
            int pick = (price>=PriceAndPage[i].first ? PriceAndPage[i].second+prev[price-PriceAndPage[i].first] : 0);
            curr[price] = max(pick,notPick);
        }
        prev = curr;
    }

    cout << prev[x] << endl;

    return 0;
}
