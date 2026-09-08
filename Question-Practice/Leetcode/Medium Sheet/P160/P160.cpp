#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<vector<bool>> can_speak(m+1,vector<bool>(n+1,false));
        for(int i=0; i<m; i++) {
            int person = i+1;
            for(int lang: languages[i]) can_speak[person][lang] = true;
        }
        set<int> users_to_teach;
        for(auto &e: friendships) {
            int u = e[0], v = e[1];
            bool can_talk = false;
            for(int l=1; l<=n; l++) {
                if(can_speak[u][l] && can_speak[v][l]) {
                    can_talk = true;
                    break;
                }
            }
            if(can_talk) continue;
            users_to_teach.insert(u);
            users_to_teach.insert(v);
        }

        if(users_to_teach.empty()) return 0;
        int min_cnt = users_to_teach.size();
        for(int l=1; l<=n; l++) {
            int cnt = 0;
            for(int user: users_to_teach) {
                if(!can_speak[user][l]) cnt++;
            }
            min_cnt = min(min_cnt, cnt);
        }
        return min_cnt;
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
