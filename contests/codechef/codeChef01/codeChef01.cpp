#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
// int findRequiredRuns(int opponentScore, int currentScore) {
//     // write your code here 
//     return opponentScore-currentScore+1;
// }

// Q2
// class Solution {
// public:
//     bool isBitSet(long long n, int i) {
//         long long x = 1LL<<i;
//         return n&x;
//     }
// };

// Q3
void makePowerSet(int idx, vector<int>& curr, vector<int>& inputNumbers, vector<vector<int>>& powerSet) {
    if(idx>=inputNumbers.size()) return;
    // Take it
    curr.push_back(inputNumbers[idx]);
    powerSet.push_back(curr);
    makePowerSet(idx+1,curr,inputNumbers,powerSet);
    // Not take it
    curr.pop_back();
    makePowerSet(idx+1,curr,inputNumbers,powerSet);
}
vector<vector<int>> findSubsets(vector<int>& inputNumbers) {
    // write your code here 
    vector<vector<int>> powerSet;
    vector<int> curr = {};
    powerSet.push_back(curr);
    makePowerSet(0,curr,inputNumbers,powerSet);
    return powerSet;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    vector<int> inputNumbers = {0,1,2,3};
    vector<vector<int>> powerSet = findSubsets(inputNumbers);

    for(int i=0; i<powerSet.size(); i++) {
        for(int j=0; j<powerSet[i].size(); j++) {
            cout << powerSet[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
