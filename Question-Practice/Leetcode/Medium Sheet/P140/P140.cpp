#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis(deadends.begin(),deadends.end());
        if(vis.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        vis.insert("0000");
        int turns = 0;
        while(!q.empty()) {
            int level_size = q.size();
            while(level_size--) {
                string curr = q.front();
                q.pop();
                if(curr==target) return turns;
                for(int i=0; i<4; i++) {
                    // Forward rotation
                    string up = curr;
                    up[i] = ((up[i]=='9') ? '0' : up[i]+1); 
                    if(!vis.count(up)) {
                        q.push(up);
                        vis.insert(up);
                    }
                    // Backward rotation
                    string down = curr;
                    down[i] = ((down[i]=='0')? '9' : down[i]-1); 
                    if(!vis.count(down)) {
                        q.push(down);
                        vis.insert(down);
                    }
                }
            }
            turns++;
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
