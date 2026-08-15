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
    ll n;
    cin >> n;
    ll FivePower = 5;
    ll ans = 0;
    while(FivePower<=n) {
        ans += (n/FivePower);
        FivePower *= 5;
    }
    cout << ans << endl;

    // We know zero comes from a combination of 5 and 2, so what we do is just count the number of fives we can get till n, as the number of 2s to combine with those 5s will always be sufficient.

    // for eg:- n=25, from here we get 6 5s. One five from 5,10,15 and 20 and 2 5s from 25. Thus telling us that 25! will have 6 zeros in the end.

    // To count first find the number of 5s achievable by dividing n by 5. Then increase the power of 5 and make it 25 and find how many fives are achievable now. 
    
    // NOTE THAT WHEN YOU DIVIDE 25 BY 5, IT COUNTS 25 ONLY ONCE AND THUS THE LAST 5 YOU GET WHEN YOU DIVIDE 25 BY 25. THEREFORE TO GET ALL THE FIVES, KEEP DIVIDING N BY THE POWERS OF 5 TILL THEY ARE SMALLER THAN N AND ADD THE VALUE IN YOUR ANSWER.

    // Dividing by 5^x, only removes the xth occurance of 5 from a number.
    return 0;
}
