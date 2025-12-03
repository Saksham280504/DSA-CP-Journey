#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<vector<string>> ans;
    int level = 0;
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);

    while(!q.empty()) {
        vector<string> vec = q.front();
        q.pop();
        if(level<vec.size()) {
            level++;
            for(auto it: usedOnLevel) {
                st.erase(it);
            }
            usedOnLevel.clear();
        }

        string word = vec.back();
        int n = word.size();

        if(word==endWord) {
            if(ans.size()==0) {
                ans.push_back(vec);
            }
            else if(ans[0].size()==vec.size()) {
                ans.push_back(vec);
            }
        }
        
        for(int i=0; i<n; i++) {
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++) {
                word[i] = ch;
                if(st.find(word)!=st.end()) {
                    usedOnLevel.push_back(word);
                    vec.push_back(word);
                    q.push(vec);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }

    return ans;

    // This solution gives us memory limit exceeded on LeetCode, but this is what you answer in interview. This is a standard answer.
}

// This solution is entirely for CP purposes
unordered_map<string,int> mpp;
vector<vector<string>> ans;
string b;
int n;
void dfs(string word, vector<string>& vec) {
    if(word==b) {
        reverse(vec.begin(),vec.end());
        ans.push_back(vec);
        reverse(vec.begin(),vec.end());
        return;
    }
    int steps = mpp[word];
    for(int i=0; i<n; i++) {
        char original = word[i];
            for(char ch='a'; ch<='z'; ch++) {
                word[i] = ch;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1 == steps) {
                    vec.push_back(word);
                    dfs(word,vec);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
}

vector<vector<string>> findLaddersCP(string beginWord, string endWord, vector<string>& wordList) {
    queue<string> q;
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);
    q.push(beginWord);
    b=beginWord;
    mpp[beginWord]=1;
    n = beginWord.size();

    while(!q.empty()) {
        string word = q.front();
        int steps = mpp[word];
        q.pop();
        for(int i=0; i<n; i++) {
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++) {
                word[i] = ch;
                if(st.count(word)) { // Similar as if(st.find(word)!=st.end())
                    st.erase(word);
                    q.push(word);
                    mpp[word]=steps+1;
                }
            }
            word[i] = original;
        }
    }
    if(mpp.find(endWord)!=mpp.end()) {
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord,seq);
    }
    return ans;
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


    return 0;
}
