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

    int n1;
    cin >> n1;
    vector<int> arr1;

    for(int i=0; i<n1; i++) {
        int nums;
        cin >> nums;
        arr1.push_back(nums);
    }

    int n2;
    cin >> n2;
    vector<int> arr2;

    for(int i=0; i<n2; i++) {
        int nums;
        cin >> nums;
        arr2.push_back(nums);
    }

    //Brute-force method:
    // set<int> st;
    // for(int i=0; i<n1; i++) {
    //     st.insert(arr1[i]); // TC -> (n1LogN) where N is the size of set
    // }
    // for(int i=0; i<n2; i++) {
    //     st.insert(arr2[i]); // TC -> (n2LogN) where N is the size of set
    //     // Set will always have elements in sorted order
    // }

    // vector<int> unionArr;
    // for(auto it: st) {
    //     unionArr.push_back(it); // TC ->> O(n1+n2) which is the worst case
    // }

    // TC(final) _> O(n1logN + n2logN) +O(n1+n2)
    // SC -> O(n1+n2) + O(n1+n2), here only one O(n1+n2) was truly needed to solve the problem, the other one is just needed for putting elements in union array.
    // Here O(n1+n2) is the worst case scenario


    // Optimal Approach:

    int i=0;
    int j=0;
    vector<int> unionArr;

    while(i<n1 && j<n2) {
        if(arr1[i]<=arr2[j]) {
            if(unionArr.size() == 0 || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else {
            if(unionArr.size() == 0 || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    
    while(j<n2) {
        if(unionArr.size() == 0 || unionArr.back() != arr2[j]) {
            unionArr.push_back(arr2[j]);
        }
        i++;
    }

    while(i<n2) {
        if(unionArr.size() == 0 || unionArr.back() != arr1[i]) {
            unionArr.push_back(arr1[i]);
        }
        j++;
    }

    // TC -> O(n1+n2) for any case
    // SC -> O(n1+n2) for worst case, this SC is only used for creation of Union array.

    cout << "Union Array is as following: " << endl;
    for(int i=0; i<unionArr.size();i++) {
        cout << unionArr[i] << " ";
    }

    return 0;
}
