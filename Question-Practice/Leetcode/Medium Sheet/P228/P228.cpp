#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> free_servers; // {weight,idx}
        for(int i=0; i<n; i++) {
            free_servers.push({servers[i],i});
        }
        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<>> busy_servers; // {avail_time, weight, idx}

        long long time = 0; // time variable will represent the time at which the jth task will get its server.
        for(int j=0; j<m; j++) {
            time = max(time,(long long)j);
            if(free_servers.empty()) {
                time = max(time,get<0>(busy_servers.top()));
            }
            while(!busy_servers.empty() && get<0>(busy_servers.top())<=time) {
                auto [avail_time,wt,idx] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({wt,idx});
            }
            auto [wt,idx] = free_servers.top();
            free_servers.pop();
            ans[j] = idx;
            busy_servers.push({time+(long long)tasks[j],wt,idx});
        }
        return ans;
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
