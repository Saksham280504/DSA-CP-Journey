#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    int n;
    cin >> n;
    stack<pair<ll,int>> st; // st.top() will represent the next smaller number to the left of the current entering element.
    for(int i=1; i<=n; i++) {
        ll val;
        cin >> val;
        while(!st.empty() && st.top().first>=val) st.pop(); // until the stack has the element on its top which is greater than equal to the entering element, it will never be the next smaller element to the upcoming element as the entering element will be much closer to them.
        if(st.empty()) cout << 0 << " "; // If stack becomes empty then that means that none of the elements existed in the left that were smaller than the current entering element
        else cout << st.top().second << " ";
        st.push({val,i});
    }

    return 0;
}
