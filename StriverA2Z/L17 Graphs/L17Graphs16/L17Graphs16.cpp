#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int ladderLength(string startWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>> q;
    unordered_set<string> st(wordList.begin(),wordList.end());
    st.erase(startWord); // We are erasing the word before pushing it into the queue so that there are no multiple occurances of the same word in the queue that increases the ladder length.
    q.push({startWord,1});

    while(!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        if(word==endWord) return steps;
        q.pop();
        int n = word.size();
        for(int i=0; i<n; i++) {
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++) {
                word[i] = ch;
                if(st.find(word)!=st.end()) {
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i] = original;
        }
    }

    // TC -> (wordSize*26)*(N)*(LogN)
    // wordSize*26 -> For applying edits in one word
    // N -> Worst case that all the words of wordList gets pushed into the queue
    // LogN -> TC to check for a word in the set
    return 0;
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

    string startWord, endWord;
    cin >> startWord >> endWord;

    int n;
    cin >> n;
    vector<string> wordList(n);
    for(int i=0; i<n; i++) {
        cin >> wordList[i];
    }

    int cnt = ladderLength(startWord,endWord,wordList);
    cout << cnt << endl;

    return 0;
}
