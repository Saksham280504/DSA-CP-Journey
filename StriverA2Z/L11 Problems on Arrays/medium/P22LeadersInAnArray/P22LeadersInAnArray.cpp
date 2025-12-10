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

    vector<int> LeaderArr;

    // brute-force method

    // for(int i=0; i<n; i++) {
    //     bool Leader = true;
    //     for(int j=i+1; j<n; j++) {
    //         if(arr[j] >= arr[i]) {
    //             Leader = false;
    //             break;
    //         }
    //     }
    //     if(Leader == true) {
    //         LeaderArr.push_back(arr[i]);
    //     }
    // }

    // TC -> O(N*N) (approx.)
    // SC -> O(N) (worst case) (We need this only for the answers)

    // Optimal Approach

    int maxi = INT_MIN;
    for(int i=n-1; i>=0; i--) {
        if(arr[i] > maxi) {
            LeaderArr.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    // TC -> O(N) (This is the case, when we submit the LeaderArr just the way we store it)
    // If in the question, we are asked to provide the answers in:

    // 1. In order they come in actual array -> TC-> O(2N)
    // 2. In sorted order -> TC-> O(NlogN)
    
    // SC -> O(N) (worst case)

    int m = LeaderArr.size();
    for(int i=0; i<m; i++) {
        cout << LeaderArr[i] << " ";
    }
    return 0;
}


// A leader element is always greater than all the elements present on its right.

