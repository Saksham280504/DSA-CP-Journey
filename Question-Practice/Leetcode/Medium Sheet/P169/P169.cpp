#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    pair<int,int> QueenAttack(int i, int j, set<pair<int,int>>& queenPos, pair<int,int>& d) {
        if(i<0 || j <0 || i>=8 || j>=8) return {-1,-1};
        if(queenPos.count({i,j})) return {i,j};
        return QueenAttack(i+d.first,j+d.second,queenPos,d);
    }
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<pair<int,int>> queenPos;
        for(auto &queen: queens) {
            queenPos.insert({queen[0],queen[1]});
        }
        vector<pair<int,int>> dir = {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};
        vector<vector<int>> Queens;
        for(auto p: dir) {
            pair<int,int> pos = QueenAttack(king[0],king[1],queenPos,p);
            if(pos.first==-1) continue;
            vector<int> ans = {pos.first,pos.second};
            Queens.push_back(ans);
        }
        return Queens;
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
