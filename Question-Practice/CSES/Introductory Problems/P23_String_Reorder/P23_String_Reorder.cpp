#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26,0);
    for(char ch: s) {
        freq[ch-'A']++;
    }
    int mx = *max_element(freq.begin(), freq.end());
    if(mx>((n+1)/2)) {
        cout << - 1 << endl;
        return 0;
    }
    string ans = "";
    int prev_char = -1;
    for(int i=0; i<n; i++) {
        int rem = n-i;
        for(int j=0; j<26; j++) {
            if(freq[j]==0 || prev_char==j) continue;
            freq[j]--;
            int mx = *max_element(freq.begin(), freq.end());
            if(mx<=(rem/2)) {
                prev_char = j;
                ans.push_back(j+'A');
                break;
            }
            else freq[j]++;
        }
    }

    cout << ans << endl;

    return 0;
}
