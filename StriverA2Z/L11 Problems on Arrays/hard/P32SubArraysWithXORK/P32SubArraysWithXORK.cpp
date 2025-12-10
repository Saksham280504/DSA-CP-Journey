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

    int target;
    cin >> target;

    // Brute-force method

    // int count = 0;
    // for(int i=0; i<n; i++) {
    //     for(int j=i; j<n; j++) {
    //         int XOR = 0;
    //         for(int k=i; k<=j; k++) {
    //             XOR = XOR^arr[k];
    //         }
    //         if(XOR == target) count++;
    //     }
    // }

    // TC -> O(N*N*N) -> O(N*N*N)
    // SC -> O(1)

    // Better Approach
    // int count = 0;
    // for(int i=0; i<n; i++) {
    //     int XOR = 0;
    //     for(int j=i; j<n; j++) {
    //         XOR = XOR^arr[j];
    //         if(XOR==target) count++;
    //     }
    // }

    // TC -> O(N*N)
    // SC -> O(1)

    // Optimal Approach

    int count = 0;
    map<int,int> mpp;
    int preXOR = 0;
    mpp[0] = 1; // THIS IS VERY IMPORTANT LINE, this is so because just for an example when preXOR = preXOR^arr[i] & i = 1 in our example, then there preXOR becomes 6 and remove becomes 0, and if we wouldn't have included mpp[0] = 1, then this case would have been rejected!!
    for(int i=0; i<n; i++) {
        preXOR = preXOR^arr[i];
        int remove = preXOR^target;
        if(mpp.find(remove)!=mpp.end()) {
            count = count + mpp[remove];
        }
        mpp[preXOR]++;
    }

    // TC -> O(NlogN) (for ordered map)
    // TC -> O(N) (best & average case in unordered_map)
    // TC -> O(N*N) (worst case in unordered_map)
    // SC -> O(N) (worst case)

    cout << count << endl;
    return 0;
}

// XOR:

// 1^1 -> 0
// 0^0 -> 0
// 1^0 -> 1
// 0^1 -> 1
// 0^N -> N
// N^N -> 0
