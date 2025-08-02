#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
using ll = long long;
 
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
        ll a,b;
        cin >> a >> b;
        pair<ll,ll> king;
        cin >> king.first >> king.second;
        pair<ll,ll> queen;
        cin >> queen.first >> queen.second;
        set<pair<ll,ll>> stk;
        set<pair<ll,ll>> stfinal;
        vector<pair<ll,ll>> move;
 
        move.push_back({-1*a,b});
        move.push_back({a,-1*b});
        move.push_back({-1*a,-1*b});
        move.push_back({a,b});
        move.push_back({-1*b,a});
        move.push_back({b,-1*a});
        move.push_back({-1*b,-1*a});
        move.push_back({b,a});
 
        for(int i=0; i<8; i++) {
            ll xk = king.first;
            ll yk = king.second;
            xk += move[i].first;
            yk += move[i].second;
            stk.insert({xk,yk});
        }
        for(int i=0; i<8; i++) {
            ll xq = queen.first;
            ll yq = queen.second;
            xq += move[i].first;
            yq += move[i].second;
            if(stk.find({xq,yq})!=stk.end()) {
                stfinal.insert({xq,yq});
            }
        }
 
        cout << stfinal.size() << endl;
    }
 
    return 0;
}