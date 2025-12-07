#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int minimumMultiplications(vector<int>& arr, int start, int end) {
    int mod = 100000;
    queue<pair<int,int>> q;
    vector<int> dist(mod,1e9);
    q.push({0,start});
    dist[start] = 0;
    if(start==end) return 0; // This case was not covered by striver, so I added it

    while(!q.empty()) {
        int steps = q.front().first;
        int node = q.front().second;
        q.pop();

        for(auto it: arr) {
            int num = (it*node)%mod; // This makes sure that the num is always lesser 100000
            if(steps+1<dist[num]) {
                dist[num] = steps+1;
                if(num==end) return steps+1;
                q.push({dist[num],num});
            }
        }
    }

    // TC -> O(100000*N) (very hypothetical as it is nearly impossible to generate all the 100000 nodes using the N-sized array)

    return -1;
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

    return 0;
}
