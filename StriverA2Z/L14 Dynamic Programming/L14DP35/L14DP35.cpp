#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n' 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    // You are given an array of prices of stocks over n days starting from 0th day to (n-1)th day. We need to generate the maximum profit possible in buying and selling of stock, and thus print it.
    // The key points are that selling will only be done after buying
    // The profit should be maximum
    // The buying and selling can only be done once.

    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0; i<n; i++) cin >> prices[i];

    int mini = prices[0];
    int profit = 0; // The minimum value of profit can only be zero, because we don't want losses

    for(int i=1; i<n; i++) {
        int cost = prices[i] - mini;
        profit = max(profit,cost);
        mini = min(mini,prices[i]);
    }

    cout << profit << endl;

    return 0;
}
