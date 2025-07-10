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

    for(int i=0; i<n2; i++){
        int nums;
        cin >> nums;
        arr2.push_back(nums);
    }

    // Brute-force method

    // int visited[n2] = {0};

    // vector<int> ans;

    // for(int i=0;i<n1;i++){
    //     for(int j=0; j<n2; j++){
    //         if(arr1[i]==arr2[j] && visited[j]==0) {
    //             ans.push_back(arr1[i]);
    //             visited[j] = 1;
    //             break;
    //         }
    //         if(arr2[j]>arr1[i]) break;
    //     }
    // }

    // // TC -> O(n1*n2);
    // // SC -> O(n2); // Take the visited array to be of the smaller array's size.

    // Optimal Approach
    
    int i =0;
    int j =0;
    vector<int> ans;

    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) {
            i++;
        }
        else if(arr2[j] < arr1[i]){
            j++;
        }
        else {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    // TC -> O(n1+n2) in the worst case
    // SC -> O(1) + O(n) where O(n) is used to store ans and return. Here n is the size of the ans vector where n in the worst case will be equal to the size of the smaller array.
 

    cout << "Intersection array is as follows: " << endl;

    int n = ans.size();

    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
