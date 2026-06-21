#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
// class Solution {
// public:
//     int maxDistance(string moves) {
//         map<char,int>mpp;
//         for(char ch: moves) {
//             mpp[ch]++;
//         }
//         int Horizontal_pos = mpp['R']-mpp['L'];
//         int Vertical_pos = mpp['U']-mpp['D'];
//         int Horizontal_dist = abs(0-Horizontal_pos);
//         int Vertical_dist = abs(0-Vertical_pos);
//         return (Horizontal_dist+Vertical_dist+mpp['_']);
//     }
// };

// // Q2

class Solution {
public:
    int countValidSubarrays(vector<int>& arr, int x) {
        int n = arr.size();
        int valid_subarrays = 0;
        for(int i=0; i<n; i++) {
            long long ori_sum = 0;
            for(int j=i; j<n; j++) {
                ori_sum = (ori_sum+(long long)arr[j]);
                long long sum = ori_sum;
                int first_digit = sum%10;
                int last_digit = -1;
                while(sum) {
                    last_digit = sum%10;
                    sum /= 10;
                }
                if(last_digit==x && first_digit==x) valid_subarrays++;
            }
        }
        return valid_subarrays;
    }
    // TC -> O(2.925*10^7)
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
