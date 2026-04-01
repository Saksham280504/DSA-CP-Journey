#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        // Noting down frequencies
        map<int,int> freq;
        for(int b: barcodes) {
            freq[b]++;
        }

        // Sorting of elements by frequency
        priority_queue<pair<int,int>> pq; // {freq,val}
        for(auto it: freq) pq.push({it.second, it.first});

        vector<int> result;

        // Filling of elements at even and odd indices
        while(pq.size()>=2) {
            auto [f1,x1]  = pq.top();
            pq.pop();
            auto [f2,x2] = pq.top();
            pq.pop();
            result.push_back(x1);
            f1--;
            result.push_back(x2);
            f2--;
            if(f1>0) pq.push({f1,x1});
            if(f2>0) pq.push({f2,x2});
        }

        // Leftover
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
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
