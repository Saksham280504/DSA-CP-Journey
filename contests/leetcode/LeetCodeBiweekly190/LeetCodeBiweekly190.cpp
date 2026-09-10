#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        char sourceColor, targetColor;
        sourceColor = ((source[0]+source[1])&1) ? 'W' : 'B';
        targetColor = ((target[0]+target[1])&1) ? 'W' : 'B';
        if(sourceColor!=targetColor) return -1;
        // Now either both are 'B' or both are 'W' and for each color block we have 2 diagonals -> y+x = constant or y-x+8 = constant
        // If they share a diagonal, we will reach in 1 move or if not then in 2 moves
        int sy = source[0], sx = source[1];
        int ty = target[0], tx = target[1];
        return (((ty+tx)==(sy+sx)) || ((ty-tx+8)==(sy-sx+8))) ? 1 : 2;
    }
};

// Q2


// 

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
