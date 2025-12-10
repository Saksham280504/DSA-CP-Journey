#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool ls(vector<int>& arr, int x) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        if(arr[i]==x) return true;
    }
    return false;
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

    // brute-force method

    // int longest = 1;
    // for(int i=0; i<n;i++) {
    //     int x = arr[i];
    //     int cnt = 1;
    //     while(ls(arr,x+1)==true) {
    //         x++;
    //         cnt++;
    //     }
    //     longest=max(longest,cnt);
    // }

    // TC-> O(N*N)
    // SC->O(1)

    // Better solution

    // sort(arr.begin(), arr.end());
    // int longest = 1;
    // int lntCur = 0;
    // int lastSmaller = INT_MIN;
    // for(int i=0; i<n; i++) {
    //     if(arr[i] == lastSmaller + 1) {
    //         lastSmaller = arr[i];
    //         lntCur++;
    //     }else if(arr[i] != lastSmaller) {
    //         lntCur = 1;
    //         lastSmaller = arr[i];
    //     } 
    //     longest = max(longest, lntCur);
    // }

    // TC -> O(NlogN + N)
    // SC-> O(1)

    // Optimal Solution (constraints)

    int longest = 1;
    unordered_set<int> st;

    for(int i=0; i<n; i++) {
        st.insert(arr[i]); // This operation for unordered_set takes O(1) as the TC for the best and average case. For the worst case, if multiple collisions occur, then only the TC becomes O(N)
    }
    // TC -> O(N)
    for(auto it: st) {
        if(st.find(it-1)==st.end()) {
            int cnt = 1;
            int x  = it;
            while(st.find(x+1) != st.end()) {
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    } // TC -> O(2N)

    // TC -> O(N + 2N) -> O(3N)
    // SC -> O(N) (worst case)

    cout << longest << endl;
    return 0;
}
