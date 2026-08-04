#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
vector<int> digits;
ll dp[20][11][2][2];
// pos (0...18), prev(0...9 and 10 = special), tight(0/1), LeadingZero(0/1)

ll dfs(int pos, int prevDigit, int tight, int leadingZero) {
    if(pos==digits.size()) return 1;
    ll &res = dp[pos][prevDigit][tight][leadingZero];
    if(res!=-1) return res;
    res = 0;

    int limit = (tight ? digits[pos] : 9);

    for(int d = 0; d<=limit; d++) {
        if(!leadingZero) {
            if(d==prevDigit) continue;
        }
        int nextTight = (tight && d==limit);
        int nextLeadingZero = (leadingZero && d==0);
        int nextPrev;
        if(nextLeadingZero) nextPrev = 10;
        else nextPrev = d;
        res += dfs(pos+1,nextPrev, nextTight, nextLeadingZero);
    }
    return res;
}

ll countUpto(ll x) {
    if(x<0) return 0;
    digits.clear();
    if(x==0) digits.push_back(x);
    while(x>0) {
        digits.push_back(x%10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    memset(dp,-1,sizeof(dp));
    return dfs(0,10,1,1);
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
    ll a,b;
    cin >> a >> b;
    cout << countUpto(b)-countUpto(a-1) << endl;

    return 0;
}
