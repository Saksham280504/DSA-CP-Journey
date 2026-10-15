#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Trie {
private:
    struct TrieNode {
        bool isComplete;
        vector<TrieNode*> children;
    };
    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode->isComplete = false;
        newNode->children.assign(26,nullptr);
        return newNode;
    }
    TrieNode* root;
public:
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char ch: word) {
            int idx = ch-'a';
            if(curr->children[idx]==nullptr) {
                curr->children[idx] = getNode();
            }
            curr = curr->children[idx];
        }
        curr->isComplete = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char ch: word) {
            int idx = ch-'a';
            if(curr->children[idx]==nullptr) return false;
            curr = curr->children[idx];
        }
        return curr->isComplete;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char ch: prefix) {
            int idx = ch-'a';
            if(curr->children[idx]==nullptr) return false;
            curr = curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

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
