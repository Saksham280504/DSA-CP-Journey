#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Brute-force solution -> O(n^3)
// class Solution {
// public:
//     int countTriplets(vector<int>& arr) {
//         int n = arr.size();
//         map<int,int> mpp;
//         vector<int> preXOR(n,0);
//         set<vector<int>> st;
//         preXOR[0] = arr[0];
//         for(int i=1; i<n; i++) {
//             preXOR[i] = preXOR[i-1]^arr[i];
//         }
//         for(int i=0; i<n; i++) {
//             for(int j=i+1; j<n; j++) {
//                 int a = preXOR[j-1];
//                 if(i>0) a ^= preXOR[i-1];
//                 for(int k=j; k<n; k++) {
//                     int b = preXOR[k]^preXOR[j-1];
//                     if(a==b) {
//                         vector<int> arr = {i,j,k};
//                         sort(arr.begin(), arr.end());
//                         st.insert(arr);
//                     }
//                 }
//             }
//         }

//         int ans = st.size();
//         return ans;
//     }
// };

// Better Solution -> TC -> O(n^2)

// arr[i]^arr[i+1]^arr[i+2]^...^arr[j-1] = arr[j]^arr[j+1]^...^arr[k]
// prefix[i-1] = prefix[k]
// Also, arr[i]^arr[i+1]^...^arr[j-1]^arr[j]^arr[j+1]^...^arr[k] = 0 => so for every pair (i,k), number of triplets will be (i<j<=k) = (k-i)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            int xr = 0;
            for(int k=i; k<n; k++) {
                xr ^= arr[k];
                if(xr==0 && k>i) ans += (k-i);
            }
        }
        return ans;
    }
};


// Optimal Solution -> TC -> O(N)

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> count;
        unordered_map<int, int> total;
        count[0] = 1;
        total[0] = 0;

        int prefix = 0;
        int ans = 0;
        for(int k=0; k<n; k++) {
            prefix ^= arr[k];
            if(count.find(prefix)!= count.end()) {
                ans += count[prefix]*k - total[prefix]; 
            }
            count[prefix]++;
            total[prefix] += (k+1);
        }

        return ans;
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
