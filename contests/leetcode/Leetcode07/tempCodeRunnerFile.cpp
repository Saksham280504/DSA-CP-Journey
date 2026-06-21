class Solution {
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

// class Solution {
// public:
//     int countValidSubarrays(vector<int>& arr, int x) {
//         int n = arr.size();
//         int valid_subarrays = 0;
//         for(int i=0; i<n; i++) {
//             int sum = 0;
//             for(int j=i; j<n; j++) {
//                 sum += arr[j];
//                 int first_digit = sum%10;
//                 int last_digit = -1;
//                 while(sum) {
//                     last_digit = sum%10;
//                     sum /= 10;
//                 }
//                 if(last_digit==x && first_digit==x) valid_subarrays++;
//             }
//         }
//         return valid_subarrays;
//     }
//     // TC -> O(2.925*10^7)
// };