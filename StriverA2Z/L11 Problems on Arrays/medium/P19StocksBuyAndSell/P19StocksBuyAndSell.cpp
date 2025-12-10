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

    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    // Brute-force method

    // int MaxDiff = 0, BuyInd = 0, SellInd = 0;
    // for(int i=1; i<n; i++) {
    //     for(int j=0; j<i; j++) {
    //         if(arr[i]-arr[j] > MaxDiff) {
    //             MaxDiff = arr[i] - arr[j];
    //             BuyInd = j;
    //             SellInd = i;
    //         }
    //     }
    // }

    // cout << "Buying day: " << BuyInd << endl;
    // cout << "Selling day: " << SellInd << endl;
    // cout << "Profit : " << MaxDiff << endl;

    // TC -> O(N*N) (approx.)
    // SC -> O(1)


    // Optimal approach

    int mini = arr[0], profit = 0, BuyInd = 0, SellInd = 0;

    for(int i=1; i<n; i++) {
        int cost = arr[i]-mini;
        if(profit < cost) {
            SellInd = i;
            profit = cost;
        }

        if(mini > arr[i]) {
            BuyInd = i;
            mini = arr[i];
        }
    }
        cout << "Buying day: " << BuyInd << endl;
        cout << "Selling day: " << SellInd << endl;
        cout << "Profit : " << profit << endl;

    // TC -> O(N)
    // SC -> O(1)

    return 0;
}
