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
    vector<vector<int>> arr;
    for(int i=0; i<n; i++) {
        vector<int> interval;
        for(int i=0; i<2; i++) {
            int nums;
            cin >> nums;
            interval.push_back(nums);
        }
        arr.push_back(interval);
    }

    // brute-force method

    // sort(arr.begin(), arr.end());

    // vector<vector<int>> ans;
    // for(int i=0 ;i<n; i++) {
    //     int start = arr[i][0];
    //     int end = arr[i][1];
    //     if(!ans.empty() && end<=ans.back()[1]) {
    //         continue;
    //     }
    //     for(int j=i+1; j<n; j++) {
    //         if(arr[j][0] <= end) {
    //             end = max(end, arr[j][1]);
    //         }
    //         else {
    //             break;
    //         }
    //     }
    //     ans.push_back({start, end});
    // }

    // TC -> O(NlogN + 2N)
    // SC -> O(N) (worst case & only used for returning the answer)

    // Optimal Approach

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++) {
        if(ans.empty() || ans.back()[1] < arr[i][0]) {
            ans.push_back(arr[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    // TC -> O(NlogN + N)
    // SC -> O(N) (worst case)

    int ansSize = ans.size();

    for(int i=0; i<ansSize; i++) {
        for(int j=0; j<2; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
