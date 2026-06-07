#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sumOfX = 0;
        for(int x=(n-k); x<=(n+k); x++) {
            if((x&n)==0 && x>0) sumOfX += x;
        }
        return sumOfX;
    }
};

// Q2
class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        int limit = (1<<n);
        vector<string> ans;
        for(int i=0; i<limit; i++) {
            int cost = 0;
            if((i&1) && (i&2)) continue;
            if(i&1) cost += n-1;
            for(int j=1; j<n-1; j++) {
                if(!(i&(1<<j))) continue;
                bool NoAdjacentSet = (!(i&(1<<(j+1))) && !(i&(1<<(j-1))));
                if(!NoAdjacentSet) {
                    cost = k+1;
                    break;
                }
                cost += (n-1-j);
                if(cost>k) break;
            }
            
            if(cost<=k) {
                string temp = "";
                for(int j=n-1; j>=0; j--) {
                    if(i&(1<<j)) temp += '1';
                    else temp += '0';
                }
                ans.push_back(temp);
            }
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
