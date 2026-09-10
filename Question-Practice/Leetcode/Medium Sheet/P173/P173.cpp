#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int total = (1<<n);
        int maxSize = 0;
        for(int mask=0; mask<total; mask++) {
            set<char> st;
            for(int i=0; i<n; i++) {
                if(mask&(1<<i)) {
                    string &str = arr[i];
                    for(char &ch: str) {
                        if(st.count(ch)) {
                            st.clear();
                            break;
                        }
                        st.insert(ch);
                    }
                    if(st.size()==0) break;
                    int setSize = st.size();
                    maxSize = max(maxSize,setSize);
                }
            }
        }
        return maxSize;
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
