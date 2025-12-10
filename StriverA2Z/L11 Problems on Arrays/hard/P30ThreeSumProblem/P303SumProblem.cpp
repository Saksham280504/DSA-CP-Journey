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
    
    // brute-force method

    // set<vector<int>> st;

    // for(int i=0; i<n; i++) {
    //     for(int j=i+1; j<n; j++) {
    //         for(int k=j+1; k<n; k++) {
    //             if(arr[i] + arr[j] + arr[k]==0) {
    //                 vector<int> temp = {arr[i], arr[j], arr[k]};
    //                 sort(temp.begin(), temp.end());
    //                 st.insert(temp); 
    //             }
    //         }
    //     }
    // }

    // vector<vector<int>> ans(st.begin(), st.end());

    // TC -> O(N*N*N*log(Number of unique triplets))
    // SC -> O(2*(Number of triplets))

    // Better Solution

    // set<vector<int>> st;

    // for(int i=0; i<n; i++) {
    //     set<int> HashSet;
    //     for(int j=i+1; j<n; j++) {
    //         int third = -(arr[i]+arr[j]);
    //         if(HashSet.find(third) != HashSet.end()) {
    //           vector<int> temp = {arr[i], arr[j], third};  
    //           sort(temp.begin(), temp.end());
    //           st.insert(temp);
    //         }
    //         HashSet.insert(arr[j]);
    //     }
    // }

    // vector<vector<int>> ans(st.begin(), st.end());

    // TC -> O(N*N*M) Here M is a variable which will be dependent upon the position of i & j iterator
    // SC -> O((2*Number of Triplets)) + O(N)

    // Optimal approach
    
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++) {
        if(i > 0 && arr[i]==arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) {
                j++;
                while(j<k && arr[j]==arr[j-1])j++;
            }
            else if(sum > 0) {
                k--;
                while(j<k && arr[k]==arr[k+1])k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]}; // We are neglecting this space complexity because O(3) -> O(1)
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && arr[j]==arr[j-1])j++;
                while(j < k && arr[k]==arr[k+1])k--;
            }
        }
    }

    // TC -> O(NlogN) + O(N*N)
    // SC -> O(Number of triplets) only for printing the array


    int ansSize = ans.size();

    for(int i=0; i<ansSize; i++) {
        for(int j=0; j<3; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
