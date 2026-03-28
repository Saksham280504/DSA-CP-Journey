#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// This is giving TLE
class Solution {
private:
    bool dfs(int i, int j, int ind, vector<vector<char>>& board, string& word, vector<vector<int>>& del) {
        if(ind==word.size()) return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[ind]) return false;

        char temp = board[i][j];
        board[i][j] = '#'; // marked visited
        bool found = false;
        for(auto d: del) {
            found = found || dfs(i+d[0],j+d[1],ind+1,board,word,del);
        }
        board[i][j] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> del = {{0,1},{1,0},{0,-1},{-1,0}}; // Using this will give TLE, because even after finding a true state, the loop will still continue for 4 states
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dfs(i,j,0,board,word,del)) return true;
            }
        }
        return false;
    }
};

// Optimal Solution
class Solution {
private:
    bool dfs(int i, int j, int ind, vector<vector<char>>& board, string& word) {
        if(ind==word.size()) return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[ind]) return false;

        char temp = board[i][j];
        board[i][j] = '#'; // marked visited
        bool found = dfs(i,j+1,ind+1,board,word) || 
                     dfs(i+1,j,ind+1,board,word) || 
                     dfs(i,j-1,ind+1,board,word) ||
                     dfs(i-1,j,ind+1,board,word); // This will stop whenever a true state is found.
        board[i][j] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dfs(i,j,0,board,word)) return true;
            }
        }
        return false;
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
