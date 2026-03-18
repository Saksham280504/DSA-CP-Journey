#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    double totalAreaBelow(double H, vector<vector<int>>& squares) {
        double Area = 0;
        for(auto sq: squares) {
            double y = sq[1];
            double l = sq[2];
            if(H<=y) continue;
            if(H>=y+l) Area += l*l;
            else Area += (H-y)*l;
        }

        return Area;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double low = 1e18, high = 0;
        for(auto sq: squares) {
            double y = sq[1];
            double l = sq[2];
            totalArea += l*l;
            low = min(low,y);
            high = max(high,y+l);
        }
        
        double target = totalArea/2.0;

        for(int i=0; i<100; i++) { // Binary search on real numbers (enough for precision)
            double mid = (low+high)/2.0;
            if(totalAreaBelow(mid,squares)>=target) high = mid;
            else low = mid;
        }

        return low;
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
