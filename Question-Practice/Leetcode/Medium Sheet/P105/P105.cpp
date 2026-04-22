#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        // Ranking Matrix Creation
        vector<vector<int>> ranking(n,vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n-1; j++) {
                ranking[i][preferences[i][j]] = j;
            }
        }
        // Mapping partners
        vector<int> partner(n);
        for(auto pair: pairs) {
            partner[pair[0]] = pair[1];
            partner[pair[1]] = pair[0];
        }
        
        int unhappy = 0;
        for(int x=0; x<n; x++) {
            int y = partner[x];
            for(int rank=0; rank<ranking[x][y]; rank++) {
                int u = preferences[x][rank];
                int v = partner[u];
                if(ranking[u][x]<ranking[u][v]) {
                    unhappy++; // This only tells us that x is unhappy, it doesn't tell anything about y,u,v
                    break; // We now know that x is unhappy, so no need to check further for x, move to the next value.
                }
            }
        }

        return unhappy;
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
