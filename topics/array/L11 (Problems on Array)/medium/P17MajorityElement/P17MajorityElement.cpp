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

    // brute - force  method

    // for(int i=0; i<n; i++) {
    //     int count = 0;
    //     for(int j=0; j<n; j++) {
    //         if(arr[j]== arr[i]) count++;
    //     }
    //     if(count > n/2) {
    //     cout << "The majority element is: " << arr[i];
    //     return 0;
    // }

    // cout << "No majority element" << endl;

    // TC -> O(N*N)
    // SC -> O(1)

    // Better Approach

    // map<int, int> mpp;

    // for(int i=0; i<n; i++) {
    //     mpp[arr[i]]++;
    // }

    // For the above loop, the TC will be O(NlogN) for the ordered map.
    // For the unordered map, the TC is O(N) for the best and average case.
    // In case of unordered map, the TC for the worst case is O(N*N).

    // for(auto it: mpp) {
    //     if(it.second > n/2) {
    //         cout << "The majority element is: " << it.first;
    //         return 0;
    //     }
    // }
    // Here in the worst case, that is when all the elements in the array are unique, the TC will be O(N)
    // cout << "No Majority element" << endl;

    // So, in the worst case, for ordered map the TC -> O(NlogN) + O(N)
    // SC -> O(N) for the worst case

    // Optimal Solution (Moore's Voting Algorithm)

    int element = arr[0];
    int count=0;
    for (int i=0; i<n; i++) {
        if(arr[i]==element) count++;
        else count --;
        if(count == 0) {
            element = arr[i+1];
            count = 0;
        }
    }
    if(count==0) {
    cout << "No majority element" << endl;
    return 0;
    }
    else {
        int eleCount = 0;
        for (int i=0; i<n; i++) {
            if(arr[i]==element) eleCount++;
        }
        if(eleCount > n/2) {
           cout << "Majority element is: " << element << endl;
           return 0;
        }
        else cout << "No majority element" << endl; 
    }

    // TC -> O(N) + O(N)
    // SC -> O(1)
    return 0;
}
