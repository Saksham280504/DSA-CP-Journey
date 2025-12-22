#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        list<int> ls; //(all +ves) , (-ves, +ves) , (all -ves)
        for(int i=0; i<n; i++) {
            if(asteroids[i]>0) { ls.push_back(asteroids[i]); // i represents the position of the asteroid, so even if we encounter a positive asteroid when the list is only having negatives, then that positive asteroid will not be affected by those negative asteroids as they will never cross path. That's why +ves have no dependency on the -ves
            }
            else {
                while(!ls.empty() && ls.back()>0 && ls.back()<abs(asteroids[i])) ls.pop_back();
                if(!ls.empty() && ls.back()==abs(asteroids[i])) ls.pop_back();
                else if(ls.empty() || ls.back()<0) ls.push_back(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!ls.empty()) {
            ans.push_back(ls.front());
            ls.pop_front();
        }
        return ans;

        // TC -> O(2N)
        // SC -> O(N+N)
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
