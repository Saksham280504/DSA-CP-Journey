#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> ls; // ((+ves),(-ves,+ves),(-ves))
        for(int x: asteroids) {
            if(x>0) ls.push_back(x);
            else {
                while(!ls.empty() && ls.back() > 0 && ls.back()<abs(x)) ls.pop_back();
                if(ls.empty() || ls.back()<0) ls.push_back(x);
                else if(!ls.empty() && ls.back()==abs(x)) ls.pop_back();
            }
        }
        vector<int> ans;
        while(!ls.empty()) {
            ans.push_back(ls.front());
            ls.pop_front();
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
