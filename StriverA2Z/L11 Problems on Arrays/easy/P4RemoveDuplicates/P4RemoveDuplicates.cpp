#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// void RemoveSameElements(vector<int>& arr) {
//         for(int i=0; i<arr.size()-1; i++) {
//             if(arr[i] == arr[i+1]) {
//                 arr.erase(arr.begin()+i+1);
//                 RemoveSameElements(arr);
//                 break;
//         }
//     }
//     return;
// }

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

    //brute-force method

    // cout << "BEFORE REMOVING ";
    // for(int i=0; i<n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // RemoveSameElements(arr);

    // cout << "AFTER REMOVING ";
    // for(int i=0; i<arr.size(); i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // Brute-force method-2

    // set<int> st;
    // for(int i=0; i<n; i++) {
    //     st.insert(arr[i]);
    // }
    // int index = 0;
    // for(auto it: st) {
    //     arr[index] = it;
    //     index++;
    // }

    // cout << "Number of Unique Elements in the sorted array are: " << index;

    // TC is O( NlogN + N)
    // SC is O(N)

    // Better Approach

    int i = 0;

    for(int j=1; j<n; j++) {
        if(arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    // TC -> O(N)
    // SC -> O(1)

    cout << "NUMBER OF UNIQUE ELEMENTS ARE: " << i+1;
    return 0;
}
