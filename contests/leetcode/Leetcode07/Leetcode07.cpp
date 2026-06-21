#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    int maxDistance(string moves) {
        map<char,int>mpp;
        for(char ch: moves) {
            mpp[ch]++;
        }
        int Horizontal_pos = mpp['R']-mpp['L'];
        int Vertical_pos = mpp['U']-mpp['D'];
        int Horizontal_dist = abs(0-Horizontal_pos);
        int Vertical_dist = abs(0-Vertical_pos);
        return (Horizontal_dist+Vertical_dist+mpp['_']);
    }
};

// Q2

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
