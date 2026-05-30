#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Brute Approach
class Solution {
private:
    bool isSubsequence(string& s, string& word) {
        int i = 0, j = 0;
        int n = s.size(), m = word.size();
        while(i<n && j<m) {
            if(s[i]==word[j]) j++;
            i++;
        }
        return (j<m);
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        for(string &word: words) {
            ans = (ans + isSubsequence(s,word));
        }

        return ans;
    }

    // This gives TLE
};

// Better Approach
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> pos[26];
        int n = s.size();
        for(int i=0; i<n; i++) {
            pos[s[i]-'a'].push_back(i);
        }
        int ans = 0;
        for(string &word: words) {
            int prev = -1; // This is the index, greater than which we should find the same character withing the string s. 
            bool ok = true;
            for(char ch: word) {
                auto it = upper_bound(pos[ch-'a'].begin(), pos[ch-'a'].end(), prev); // This statement finds the iterator of the smallest element greater than prev in the array pos[ch-'a']
                if(it==pos[ch-'a'].end()) {
                    ok = false;
                    break;
                }
                prev = *it; // This statement gives the position of the found same character to prev, so that when we find the next character, it is found after prev index.
            }
            if(ok) ans++;
        }
        return ans;
    }
};

// Optimal Approach (Bucket Approach)
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<pair<int,int>> buckets[26];

        for(int i=0; i<words.size(); i++) {
            buckets[words[i][0]-'a'].push_back({i,0});
        }

        int ans = 0;
        for(char ch: s) {
            auto curr = move(buckets[ch-'a']);
            buckets[ch-'a'].clear();
            for(auto &[wordIdx,charIdx]: curr) {
                charIdx++;
                if(charIdx==words[wordIdx].size()) ans++;
                else {
                    buckets[words[wordIdx][charIdx]-'a'].push_back({wordIdx,charIdx});   
                }
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
