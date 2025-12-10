#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// void recurPermute(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<bool>& freq) {
//     if(ds.size() == nums.size()) {
//         ans.push_back(ds);
//         return;
//     }

//     for (int i=0; i<nums.size(); i++) {
//         if(!freq[i]) {
//             freq[i] = true;
//             ds.push_back(nums[i]);

//             recurPermute(nums, ds, ans, freq);

//             ds.pop_back();

//             freq[i] = false;
//         }
//     }
// }

// vector<vector<int>> permute(vector<int>& nums) {
//     vector<vector<int>> ans;
//     vector<int> ds;
//     vector<bool> freq(nums.size(), false);

//     recurPermute(nums, ds, ans, freq);
//     return ans;
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

    // Recursion L-12 (Print all Permutations of a String/Array | Recursion | Approach -1)

    // Total number of permutations of an array of n elements = n!

    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    // Optimal Approach
    int index = -1;

    for(int i=n-2;i>=0; i--) {
        if(arr[i] < arr[i+1]) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        reverse(arr.begin(), arr.end());
    }
    else {
        for(int i=n-1; i>=index; i--) {
            if(arr[i]>arr[index]) {
                swap(arr[i], arr[index]);
                break;
            }
        }
    reverse(arr.begin() + index + 1, arr.end());
    }

    cout << "Next permutation is: " << endl;

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    // TC-> O(3N) (approx.) (worst case)
    // SC-> O(1)
    return 0;
}
