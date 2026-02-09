    #include <bits/stdc++.h>
    using namespace std;
    // #define int long long  => when use this convert int main()  to int32_t main()
    // #define endl '/n'

    void solve() {
        int n,m;
        cin >> n >> m;
        vector<vector<long long>> mat(m, vector<long long>(n));
        for(int j=0; j<n; j++) {
            for(int i=0; i<m; i++) {
                cin >> mat[i][j];
            }
        }

        for(int i=0; i<m; i++) {
            sort(mat[i].begin(), mat[i].end());
        }
        long long ans=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans -=  mat[i][j]*(n-1-j);
                ans += mat[i][j]*j;
            }
        }

        cout << ans << endl;

        // TC -> O(m*(nlogn))
        // SC -> O(m*n)
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
