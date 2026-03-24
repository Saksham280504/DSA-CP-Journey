#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Brute-force solution -> O(n^3)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mpp;
        vector<int> preXOR(n,0);
        set<vector<int>> st;
        preXOR[0] = arr[0];
        for(int i=1; i<n; i++) {
            preXOR[i] = preXOR[i-1]^arr[i];
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int a = preXOR[j-1];
                if(i>0) a ^= preXOR[i-1];
                for(int k=j; k<n; k++) {
                    int b = preXOR[k]^preXOR[j-1];
                    if(a==b) {
                        vector<int> arr = {i,j,k};
                        sort(arr.begin(), arr.end());
                        st.insert(arr);
                    }
                }
            }
        }

        int ans = st.size();
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
