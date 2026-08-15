#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool nextPermutation(string &s) {
    int n = s.size();
    int i=n-2;
    while(i>=0 && s[i+1]<=s[i]) {
        i--;
    }
    if(i<0) { // The string is reverse sorted, no more increasing permutation is possible
        reverse(s.begin(),s.end());
        return false;
    }

    int j=n-1;
    while(j>i && s[j]<=s[i]) {
        j--;
    }

    swap(s[j],s[i]);

    reverse(s.begin()+i+1,s.end());
    return true;
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
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans;

    do {
        ans.push_back(s);
    }
    while(nextPermutation(s));

    cout << ans.size() << endl;
    for(string a: ans) {
        cout << a << endl;
    }

    return 0;
}
