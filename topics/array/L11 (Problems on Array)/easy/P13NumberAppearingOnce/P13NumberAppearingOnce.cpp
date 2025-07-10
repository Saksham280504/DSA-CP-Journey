#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int SingleAppearance(vector<int>& arr, int n) {

    //Brute-force method
    // for(int i=0; i<n; i++) {
    //     int num=arr[i];
    //     int counter = 0;
    //     for(int j=0; j<n;j++) {
    //         if(arr[j]==num) counter++;
    //     }
    //     if(counter==1) return num;
    // }
    // TC->O(N*N)
    // SC->O(1)

    //Better-approach-1

    // int maximum = arr[0];

    // for(int i=0; i<n; i++) {
    //     maximum = max(maximum, arr[i]);
    // }

    // int HashArr[maximum+1] = {0};

    // for(int i=0; i<n;i++) {
    //     HashArr[arr[i]]++;
    // }

    // for(int i=0; i<n; i++) {
    //     if(HashArr[arr[i]]==1)
    //     return arr[i];
    // }

    // TC -> O(3N)
    // SC -> O(maximum)
    // Hashing can't be use for large numbers, there you ned to use mapping

    // Better-approach-2

    map<long long, int> mpp;

    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;
    }

    // The TC here is NlogM where N is the length of array and M is the size of the map.

    for(auto it: mpp) {
        if(it.second==1) 
        return it.first;
    }
    // TC for this loop will be O(M) where M is (N/2)+1

    // So, in short, total TC-> O(NlogM + M)
    // and SC-> O(M) where M is (N/2)+1

    // Optimal approach
    // int XOR=0;
    // for(int i=0; i<n; i++) {
    //     XOR = XOR^arr[i];
    // }
    // return XOR;
    // TC-> O(N)
    // SC-> O(1)
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
    
    int n;
    cin >> n;
    vector<int> arr;
    
    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    int SingleNumber = SingleAppearance(arr,n);

    cout << "Number with single appearance: " << SingleNumber;

    return 0;
}
