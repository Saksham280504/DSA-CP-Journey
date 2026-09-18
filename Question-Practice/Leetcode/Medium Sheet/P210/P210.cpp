#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    pair<int,int> get_coord(int s, int n) {
        int row_index_from_bottom = (s-1)/n;
        int r = n-1-row_index_from_bottom;
        int c = (s-1)%n;
        if(row_index_from_bottom&1) {
            c = n-1-c; 
        }
        return {r,c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n*n;
        queue<pair<int,int>> q;
        vector<bool> vis(target+1,false);
        q.push({1,0});
        vis[1] = true;
        while(!q.empty()) {
            auto [s,moves] = q.front();
            q.pop();
            if(s==target) return moves;
            for(int i=1; i<=6; i++) {
                int next_s = s + i;
                if(next_s>target) break;
                auto [r,c] = get_coord(next_s,n);
                int dest = (board[r][c]!=-1 ? board[r][c]: next_s);
                if(!vis[dest]) {
                    vis[dest] = true;
                    q.push({dest,moves+1});
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

    return 0;
}
