#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Common Solution -> TC -> O(N*KlogK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(string s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            mpp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto &it: mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

// Optimal Solution -> TC -> O(N*K)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(string s: strs) {
            vector<int> freq(26,0);
            for(char c: s) {
                freq[c-'a']++;
            }

            string key = "";
            for(int f: freq) {
                key += "#" + to_string(f);
            }
            mpp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto &it: mpp) {
            ans.push_back(it.second);
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
