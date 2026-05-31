#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int> mpp;
        while(n) {
            int d = n%10;
            mpp[d]++;
            n = n/10;
        }

        int score = 0;
        for(auto it: mpp) {
            score += (it.first*it.second);
        }

        return score;
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

    int n = 545;
    map<int,int> mpp;
    while(n) {
        int d = n%10;
        mpp[d]++;
        n = n/10;
    }
    int score = 0;
    for(auto it: mpp) {
        score += (it.first*it.second);
    }

    cout << score << endl;


    return 0;
}
