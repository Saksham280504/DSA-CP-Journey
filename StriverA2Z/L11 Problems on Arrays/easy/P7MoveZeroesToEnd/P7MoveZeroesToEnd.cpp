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

    for(int i=0; i<n; i++){
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //My-approach
    for(int i=0; i<n; i++) {
        if(arr[i]==0){
            for(int j=n-1; j>i; j--) {
                if(arr[j]!=0) {
                   swap(arr[j],arr[i]);
                }
            } 
        }
    }

    //TC -> O(N)
    //SC -> O(1)

    //Brute-force method

    // vector<int> temp;
    // for(int i=0; i<n; i++) {
    //     if(arr[i]!= 0) temp.push_back(arr[i]);
    // }

    // for(int i=0; i<n;i++){
    //     if(i<temp.size()) {
    //         arr[i] = temp[i];
    //     }
    //     else arr[i] = 0;
    // }

    // TC-> O(2N)
    // SC -> O(Non-zero numbers)

    // Optimal Approach

    // int j = -1;
    // for(int i=0; i<n; i++) {
    //     if(arr[i]==0) {
    //         j=i;
    //         break;
    //     }
    // }

    // if(j == -1) {
    //     for(int i=0; i<n; i++) {
    //         cout << arr[i] << " ";
    //     }
    //     return 0;
    // }
    
    // for(int i = j+1; i<n; i++) {
    //     if(arr[i]!=0) {
    //         swap(arr[i],arr[j]);
    //         j++;
    //     }
    // }

    // TC -> O(N)
    // SC -> O(1)

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}
