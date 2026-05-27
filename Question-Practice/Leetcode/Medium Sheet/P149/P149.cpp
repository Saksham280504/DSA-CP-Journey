#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long x = 1;
        while((2*(x)*(x+1)*(2*x+1))<neededApples) x++;
        return 8*x;

        // The number of apples on the perimeter of a square whose edge is at distance x from (0,0) (center) = 12*x^2
        // Sum of all the apples from dist = 1 to dist = x => SUM(12*x^2) = 2*(x)*(x+1)*(2*x+1)
        // Perimeter = 8*x
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
