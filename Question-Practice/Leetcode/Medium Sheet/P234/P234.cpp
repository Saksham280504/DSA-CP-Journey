#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        for(int i=1; i<=9; i++) q.push(i); // Now the queue have all single length numbers (digits)
        
        for(int level=1; level<n; level++) { // After every iteration of ith level, the queue will have numbers of i+1 length
            int q_size = q.size();
            while(q_size--) {
                int num = q.front();
                q.pop();
                int last_digit = num%10;
                if(last_digit + k <= 9) q.push(num*10 + last_digit + k);
                if(k && last_digit-k>=0) q.push(num*10 + last_digit - k);
            }
        }
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
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
