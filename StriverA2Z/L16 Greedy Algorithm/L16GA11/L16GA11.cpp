#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    public:
    // We are given an array of rating of students according to which we have to assign cookies to them.
    // The rules of assigning cookies are:-
    // 1. Every student must get atleast one cookie
    // 2. A student with higher rating must get higher cookies than its neighbours

    // Brute-force approach:
    // Go from left to right and check for the left neighbour
    // Then go from right to left and check for the right neighbour
    // Then check for maximum of left[i] and right[i] for every student and assign it to the ans array

    // int candy(vector<int>& ratings) {
    //     int n = ratings.size();
    //     vector<int> left(n), right(n), ans(n);

    //    left[0] = 1;
    //    for(int i=1; i<n; i++) {
    //         if(ratings[i]>ratings[i-1]) left[i] = left[i-1]+1;
    //         else left[i] = 1;
    //     }

    //     right[n-1] = 1;
    //     for(int i=n-2; i>=0; i--) {
    //         if(ratings[i]>ratings[i+1]) right[i] = right[i+1]+1;
    //         else right[i] = 1;
    //     }
        
    //     for(int i=0; i<n; i++) {
    //         ans[i] = max(left[i],right[i]);
    //     }

    //     int sum = 0;
    //     for(int i=0;i<n; i++) sum += ans[i];

    //     return sum;

    //     // TC -> O(4N)
    //     // SC -> O(3N)
    // }

    // Better Approach

    // int candy(vector<int>& ratings) {
    //     int n = ratings.size();
    //     vector<int> ans(n);
    //     ans[0] = 1;

    //     for(int i=1; i<n; i++) {
    //         if(ratings[i]>ratings[i-1]) ans[i] = ans[i-1]+1;
    //         else ans[i] = 1;
    //     }

    //     int sum = max(ans[n-1],1);

    //     for(int i=n-2; i>=0; i--) {
    //         if(ratings[i]>ratings[i+1]) {
    //             sum += max(ans[i],ans[i+1]+1);
    //             ans[i] = ans[i+1]+1;
    //         }
    //         else {
    //             sum += max(ans[i],1);
    //             ans[i] = 1;
    //         }
    //     }

    //     return sum;

    //     // TC -> O(2N)
    //     // SC -> O(N)
    // }

    // Optimal Approach (slope method)

    int candy(vector<int>& ratings) {
        int sum = 1;
        int i = 1;
        int n = ratings.size();
        while(i<n) {
            if(ratings[i]==ratings[i-1]) {
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n && ratings[i]>ratings[i-1]) {
                peak++;
                sum += peak;
                i++;
            }

            int down = 1;
            while(i<n && ratings[i]<ratings[i-1]) {
                sum += down;
                down++;
                i++;
            }

            if(down>peak) {
                sum += (down-peak);
            }
        }

        return sum;

        // TC -> O(N)
        // SC -> O(1)
    }

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
