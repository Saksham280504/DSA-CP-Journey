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

    int k;
    cin >> k;

    // brute-force approach

    // for(int i=0; i<n; i++) {
    //     for(int j=i; j<n; j++) {
    //         int sum = 0;
    //         for(int l=i; l<=j; l++) {
    //             sum += arr[l];
    //         }   
    //         if(sum == k) counter++;
    //     }
    // }

    // TC -> O(N*N*N) (approx.)

    // better approach

    // for(int i=0; i<n; i++) {
    //     int sum = 0;
    //     for(int j=i; j<n; j++) {
    //         sum += arr[j];
    //         if(sum == k) counter++;
    //     }
    // }

    // TC -> O(N*N) (approx.)

    // optimal approach

    map<int,int> mpp;
    int preSum = 0;
    int counter = 0;
    mpp[0] = 1;
    
    for(int i=0; i<n; i++) {
        preSum += arr[i];
        int remove = preSum - k;
        if(mpp.find(remove) != mpp.end()) {
            counter = counter + mpp[remove];
        }
        mpp[preSum]++;
    }

    // TC -> O(N*log N) (for ordered_map)
    // TC -> O(N*1) (for the best and average case in unordered map)
    // TC -> O(N*N) (for the worst case in unordered map)

    cout << counter;

    return 0;
}
