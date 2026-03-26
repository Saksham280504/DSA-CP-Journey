#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'


// My Solution -> TC -> O(n*m*n*logm)
class Solution {
private:
    bool isSumThere(long long sum, vector<long long>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(sum==arr[mid]) return true;
            if(arr[mid]<sum) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        vector<vector<long long>> preSum;
        set<long long> st;
        for(int i=0; i<n; i++) {
            int m = wall[i].size();
            vector<long long> curr(m);
            for(int j=0; j<m-1; j++) {
                if(j==0) curr[j] = wall[i][0];
                else curr[j] = wall[i][j] + curr[j-1];
                st.insert(curr[j]);
            }
            preSum.push_back(curr);
        }
        
        int mini = INT_MAX;
        for(long long sum: st) {
            int cnt = 0;
            for(int i=0; i<n; i++) {
                if(!isSumThere(sum,preSum[i])) cnt++;
            }
            mini = min(mini,cnt);
        }

        return mini == INT_MAX ? n : mini;
    }
};

// Optimal Solution-> TC -> O(n*m)

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<long long, int> mpp;
        for(auto& row: wall) {
            long long sum = 0;
            for(int i=0; i<row.size()-1; i++) {
                sum += row[i];
                mpp[sum]++;
            }
        }

        int maxEdges = 0;
        for(auto &it : mpp) {
            maxEdges = max(maxEdges,it.second);
        }

        return wall.size()-maxEdges;
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
