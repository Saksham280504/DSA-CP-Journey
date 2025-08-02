#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int32_t main() {
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool Three_Consecutive_Cells = false;
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(s[i]=='.' && i+1 < n && s[i+1]=='.' && i+2 < n && s[i+2]=='.')
            {
                Three_Consecutive_Cells = true;
                break;
            }
            else if(s[i]=='.') cnt++;
        }
        if(Three_Consecutive_Cells) cout << 2 << endl;
        else cout << cnt << endl;
    }
    return 0;
}

// Argument of the problem was that if during iterating the string, I find 3 consecutive empty cells, then the answer is 2 otherwise the answer is count of the total number of cells.
// The reason for this is that for those 3 consecutive cells whose middle cell is at ith position, I can apply operation 1 for i-1 and i+1 positioned cell which will automatically keep filling the ith cell. Then, I can apply operation 2 on the ith cell to extract water out of it and place that water in all the other cells, as the water will get replenished again in the ith cell after some time.