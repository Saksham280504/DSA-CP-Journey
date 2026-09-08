#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    int countRotations(string s, int k) {
        int ans = 0;
        int n = s.size();
        do {
            int cnt = 0;
            for(int i=0; i<(s.size()-1); i++) {
                if(s[i]==s[i+1]) cnt++;
            }
            if(cnt==k) ans++;
            auto it = s.begin();
            char ch = *it;
            s.erase(it);
            s += ch;
            n--;
        }
        while(n>0);
        return ans;
    }
};

// Q2
#define ll long long
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        for(int idx=0; idx<n; idx++) {
            int num = nums[idx];
            nums.push_back(num);
        }
       int i=0, j=0;
        ll leftSum = 0;
        while(j<(n/2)) {
            leftSum += (ll)nums[j];
            j++;
        }
        j--;
        int k=n/2, l=n/2;
        ll rightSum = 0;
        while(l<n) {
            rightSum += (ll)nums[l];
            l++;
        }
        l--;
        int cnt = 0;
        while(l<(2*n-1)) {
            if(leftSum>rightSum) cnt++;
            leftSum -= (ll)nums[i];
            i++;
            j++;
            leftSum += (ll)nums[j];
            rightSum -= (ll)nums[k];
            k++;
            l++;
            rightSum += (ll)nums[l];
        }
        return cnt;
    }
};

// Q3
class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        vector<int> combined_speeds;
        int n = position.size();
        for(int i=0; i<n; i++) {
                if(i==n-1 || (position[i+1]-position[i])>distance)      combined_speeds.push_back(speed[i]);
        }
        int cnt = 0;
        int min_right_speed = 2e9;
        for(int i=combined_speeds.size()-1; i>=0; i--) {
            if(combined_speeds[i]<=min_right_speed) {
                cnt++;
                min_right_speed = combined_speeds[i];
            }
        }
        return cnt;
    }
};

// Q4
struct State {
    public:
    int cost;
    int r;
    int c;
    int dir;
    int turns;
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(); 
        int m = grid[0].size();
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        vector<vector<vector<vector<int>>>> dist(n,vector<vector<vector<int>>>(m,vector<vector<int>>(5,vector<int>(k+1,1e9))));
        dist[0][0][4][0] = grid[0][0];
        priority_queue<State,vector<State>, greater<State>> pq;
        pq.push({grid[0][0],0,0,4,0});
        while(!pq.empty()) {
            auto [cost,r,c,dir,turns] = pq.top();
            pq.pop();
            if(r==n-1 && c==m-1) return cost;
            if(cost > dist[r][c][dir][turns]) continue;
            for(int nd=0; nd<4; nd++) {
                int nr = r + dr[nd];
                int nc = c + dc[nd];
                if(nr>=0 && nc>=0 && nr<n && nc<m) {
                    int nturns = (dir==4 || dir==nd) ? turns : turns+1;
                    if(nturns<=k) {
                        int ncost = cost + grid[nr][nc];
                        if(ncost<dist[nr][nc][nd][nturns]) {
                            pq.push({ncost,nr,nc,nd,nturns});
                            dist[nr][nc][nd][nturns] = ncost;
                        }
                    }
                }
            }
        }
        return -1;
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

    // 1st Question -> Loop
    // 2nd Question -> Sliding Window
    // 3rd Question -> Counting (After combining, any speed if smaller than or equal to the minimum speed on the right will never be able to combine to the right and thus will start a new group)
    // 4th Question -> Djikstra's Algorithm + Priority_queue on structs

    return 0;
}
