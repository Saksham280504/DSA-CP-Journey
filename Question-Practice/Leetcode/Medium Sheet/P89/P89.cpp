#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

//  The core principle of this problem is not to generate all the substrings and then check for palindrome (TC-> O(N^3)), whereas expand from every index or space between two indices and give the number of palindromic substrings possible from that expansion.
class Solution {
private:
    int expand(string& word, int left, int right) {
        int cnt = 0;
        while(left>=0 && right<word.size() && word[left]==word[right]) {
            cnt++;
            left--;
            right++;
        }

        return cnt;
    }
public:
    int countSubstrings(string& s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            // odd length
            cnt += expand(s,i,i);
            // even length
            cnt += expand(s,i,i+1);
        }
        return cnt;
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
