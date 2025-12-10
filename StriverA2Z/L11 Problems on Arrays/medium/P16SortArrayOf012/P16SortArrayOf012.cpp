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

    // brute - force approach

    // sort(arr.begin(), arr.end());

    // for(int i=0; i<n ; i++) {
    //     cout << arr[i] << " ";
    // }

    // TC -> O(NlogN)
    // SC -> O(N)

    // better approach

    // int count0 = 0;
    // int count1 = 0;
    // int count2 = 0;

    // for(int i=0; i<n; i++) {
    //     if(arr[i]==0) count0++;
    //     else if(arr[i]==1) count1++;
    //     else count2++;
    // }

    // for(int i=0; i<n; i++){
    //     if(i<count0) arr[i] = 0;
    //     else if(i<count0+count1) arr[i] = 1;
    //     else arr[i] = 2;
    // }

    // for(int i=0; i<n; i++) {
    //     cout << arr[i] << " ";
    // }

    // TC -> O(2N)
    // SC -> O(1)

    // Optimal approach (Dutch National Flag Algorithm)

    int low = 0;
    int mid  = 0;
    int high = n-1;

    while(mid <= high) {
        if(arr[mid]==0) {
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    // TC -> O(N)
    // SC -> O(1)
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
