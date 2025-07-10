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

    // Brute force method
    // vector<int> sortedArr;
    // for(int i=0; i<n; i++) {
    //     sortedArr.push_back(arr[i]);
    // }

    // sort(sortedArr.begin(), sortedArr.end());

    // bool isSorted = 1;
    // for(int i=0; i<n;i++) {
    //     if(sortedArr[i] != arr[i]) {
    //         isSorted = 0;
    //         break;
    //     }
    // }

    // if(isSorted == 0) cout << "NOT SORTED" << endl;
    // else cout << "SORTED" << endl;

    // Better method
    int isSorted = 1;
    for(int i=0; i<n-1; i++) {
        if(arr[i]>arr[i+1]) {
            isSorted = 0;
            break;
        }
    }

    if(isSorted) cout << "SORTED" << endl;
    else cout << "NOT SORTED" << endl;

    return 0;
}
