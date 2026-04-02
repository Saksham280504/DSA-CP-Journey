class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_map<int,int> mpp;
//         for(int x: nums) {
//             if(mpp.count(x)) continue;
//             mpp[x] = 1;
//             if(mpp.count(x-1)) mpp[x] = mpp[x-1]+1;
//             if(mpp.count(x+1)) mpp[x+1] = mpp[x]+1;
//         }

//         for(auto it: mpp) {
//             cout << it.second << " ";
//         }
//         cout << endl;
//     }
// };