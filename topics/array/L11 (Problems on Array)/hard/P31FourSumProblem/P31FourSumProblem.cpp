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

    // set<vector<int>> st;

    // for(int i=0; i<n; i++) {
    //     for(int j=i+1; j<n; j++) {
    //         for(int k=j+1; k<n; k++) {
    //             for(int l=k+1; l<n; l++) {
    //                 long long sum = arr[i] + arr[j];
    //                 sum += arr[k];
    //                 sum += arr[l];
    //                 // This is done so that overflowing doesn't occur -> the sum don't get out from the limit of INT
    //                 if(sum==target) {
    //                     vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
    //                     sort(temp.begin(), temp.end());
    //                     st.insert(temp);
    //                 }
    //             }
    //         }
    //     }
    // }

    // vector<vector<int>> ans(st.begin(), st.end());

    // TC -> O(N*N*N*N)
    // SC -> O(2*(number of quarts))

    // Better Approach

    // set<vector<int>> st;

    // for(int i=0; i<n; i++) {
    //     for(int j = i+1; j<n; j++) {
    //         set<long long> HashSet;
    //         for(int k = j+1; k<n; k++) {
    //             int sum = arr[i] + arr[j];
    //             sum += arr[k];
    //             int fourth = target - sum;
    //             if(HashSet.find(fourth) != HashSet.end()) {
    //                 vector<int> temp = {arr[i], arr[j], arr[k], fourth};
    //                 sort(temp.begin(), temp.end());
    //                 st.insert(temp);
    //             }
    //             HashSet.insert(arr[k]); // INT can be type-casted to LONG LONG, but LONG LONG can't be type-casted to INT
    //         }
    //     }
    // }
    // TC -> O(N*N*N*log(Number of elements in the HashMap))
    // SC -> O(2*(number of quarts)) + O(N)

    // vector<vector<int>> ans(st.begin(), st.end());

    // Optimal Approach

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++) {
        if(i > 0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1; j<n; j++) {
            if(j > i+1 && arr[j]==arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum < target) {
                    k++;
                    while(k < l && arr[k]==arr[k-1]) k++;
                }
                else if(sum > target) {
                    l--;
                    while(k < l && arr[l]==arr[l+1])l--;
                }
                else {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && arr[k]==arr[k-1])k++;
                    while(k < l && arr[l]==arr[l+1])l--;
                }
            }
        }
    }

    // TC -> O(N*N*N)
    // SC -> O(number of quarts)

    int ansSize = ans.size();


    for(int i=0; i<ansSize; i++) {
        for(int j=0; j<4; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
