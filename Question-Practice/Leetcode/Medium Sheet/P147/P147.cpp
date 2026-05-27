#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        for(char ch: s) freq[ch-'a']++;
        int mx = *max_element(freq.begin(),freq.end());
        if(mx>(n+1)/2) return "";

        vector<pair<int,char>> pairs;
        for(int i=0; i<26; i++) {
            if(freq[i]>0) pairs.push_back({freq[i],char(i+'a')});
        }
        sort(pairs.rbegin(),pairs.rend());

        string str = "";

        for(auto p: pairs) {
            str += string(p.first,p.second);
        }

        string result = string(n,' ');
        int idx = 0;
        for(int i=0; i<n; i+=2) result[i] = str[idx++];
        for(int i=1; i<n; i+=2) result[i] = str[idx++];

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
