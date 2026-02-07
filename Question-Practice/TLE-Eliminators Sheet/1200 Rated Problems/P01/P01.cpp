#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> maxVector(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int,int>> freq(n);
    for(int i=0; i<n; i++) freq.push_back({arr[i],i});
    sort(freq.rbegin(),freq.rend());
    vector<int> ans;
    for(int i=0; i<3; i++) ans.push_back(freq[i].second);
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> friends;
    for(int i=0; i<3; i++) {
        vector<int> arr(n);
        for(int j=0; j<n; j++) {
            cin >> arr[j];
        }
        friends.push_back(arr);
    }
    
    vector<int> maxA = maxVector(friends[0]); // O(nlogn)
    vector<int> maxB = maxVector(friends[1]); // O(nlogn)
    vector<int> maxC = maxVector(friends[2]); // O(nlogn)

    int ans = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                int x = maxA[i];
                int y = maxB[j];
                int z = maxC[k];
                if(x==y || y==z || z==x) continue;
                ans = max(ans,friends[0][x] + friends[1][y] + friends[2][z]);
            }
        }
    }

    cout << ans << endl;

    // TC -> O(NlogN)
    // SC -> O(3N)
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
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
