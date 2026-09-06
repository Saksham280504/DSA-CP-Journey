#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n' 

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>>vis(m,vector<int>(n,-1));
        int k=0;
        int sr=0,sc=0;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) {
            if(classroom[i][j]=='S') {
                sr=i;sc=j;
            }
            else if(classroom[i][j]=='L') {
                vis[i][j]=k++;
            }
        }
        if(k==0)
        return 0;
        int tmask=(1<<k)-1;
        vector<vector<vector<int>>>best(m,vector<vector<int>>(n,vector<int>(1<<k,-1)));
        struct state{
            int r,c,mask,ener,moves;
        };
        queue<state>q;
        best[sr][sc][0]=energy;
        q.push({sr,sc,0,energy,0});
        vector<int>dr={1,0,0,-1};
        vector<int>dc={0,-1,1,0};
        while(!q.empty()){
            state cur=q.front();
            q.pop();
            for(int d=0;d<4;d++){
                    int nr=cur.r+dr[d];
                    int nc=cur.c+dc[d];
                    if(nr<0||nr>=m||nc<0||nc>=n)
                    continue;
                    if(classroom[nr][nc]=='X')
                    continue;
                int newener=cur.ener-1;
                if(newener<0)
                continue;
                int nmask=cur.mask;
                if(classroom[nr][nc]=='R'){
                    newener=energy;
                }
                if(classroom[nr][nc]=='L')
                {
                    nmask|=(1<<vis[nr][nc]);

                }
                if(nmask==tmask){
                    return cur.moves+1;
                }
                if(newener<=best[nr][nc][nmask])
                continue;

                best[nr][nc][nmask]=newener;
                q.push({nr,nc,nmask,newener,cur.moves+1});
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
