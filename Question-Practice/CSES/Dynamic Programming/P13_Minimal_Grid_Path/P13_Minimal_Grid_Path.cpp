#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int n;
string ans;

string solve1(int x, int y, vector<string>& grid) {
    if(x>n-1 || y>n-1) return "a"; // ASCII value of smaller alphabets is bigger.
    if(x==n-1 && y==n-1) return to_string(grid[x][y]);
    string down = solve1(x,y+1,grid);
    string right = solve1(x+1,y,grid);
    return min(down,right);

    // TC -> O(N^3) - >TLE
}
void solve(int x, int y, vector<string>& grid, vector<vector<int>>& hash) {
    ans.push_back(grid[x][y]);
    if(x==n-1 && y==n-1) return;
    int hash1 = 1e9, hash2 = 1e9;
    if((x+1)<n) hash1 = min(hash1,hash[x+1][y]);
    if((y+1)<n) hash2 = min(hash2,hash[x][y+1]);
    if(hash1<hash2) solve(x+1,y,grid,hash);
    else solve(x,y+1,grid,hash);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    cin >> n;
    vector<string> grid(n);
    for(int i=0; i<n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> hash(n,vector<int>(n));

    for(int i=2*n-2; i>=0; i--) {
        vector<pair<int,int>> diagonal; 
        // {compressed, x cord}
        for(int j=0; j<n; j++) {
            int x = j;
            int y = i-x;
            if(y<0 || y>=n) continue;
            char c = grid[x][y];
            int bestHash = 2*n;
            if(x+1<n) bestHash = min(bestHash, hash[x+1][y]);
            if(y+1<n) bestHash = min(bestHash, hash[x][y+1]);
            int compressed = ((c-'A')*10000) + bestHash; // Compressed is used to provide each suffix of a diagonal a unique identity, so that when we apply sorting, we first get the smallest ordering(highest preference).
            // Multiplication by 10000 simply ensures the character dominates. Since bestHash is at most about 2*n (<= 6000 in CSES constraints), 10000 is safely larger, so different characters never overlap numerically.
            diagonal.push_back({compressed,x});
        }
        sort(diagonal.begin(),diagonal.end());
        for(int j=0; j<diagonal.size(); j++) {
            int x = diagonal[j].second;
            int y = i - x;
            hash[x][y] = j;
            // By assigning ranks to each cell of a diagonal we have discarded the need for storing and comparing suffix strings forever. This is exactly SUFFIX ARRAY RANKING, where long substrings are replaced by integer ranks.
        }
    }
    // TC -> O(2n*(n+nlogn+n)) -> O(2n^2(logn))
    solve(0,0,grid,hash);
    // By using hash, we turned the problem from string comparison to computing suffix ranks.
    cout << ans << endl;

    return 0;
}
