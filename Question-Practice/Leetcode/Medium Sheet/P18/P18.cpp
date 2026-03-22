#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<unordered_map<char,int>> arr(26);
        for(string s: equations) {
            if(s[1]=='=') {
                if(arr[s[3]].find(s[0])!=arr[s[3]].end()) {
                    if(arr[s[3]][s[0]]==-1) return false;
                }
                arr[s[0]][s[3]] = 1;
            }
            else {
                if(arr[s[3]].find(s[0])!=arr[s[3]].end()) {  
                    if(arr[s[3]][s[0]]==1) return false;
                }
                arr[s[0]][s[3]] = -1;
            }
        }

        return true;
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
