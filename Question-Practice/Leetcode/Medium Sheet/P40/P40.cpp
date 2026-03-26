#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int n = num1.size(), m = num2.size();
        vector<int> result(n+m,0);
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int sum = mul + result[j+i+1];
                result[i+j+1] = sum%10;
                result[i+j] += sum/10;
            }
        }

        string ans = "";
        for(int x: result) {
            if(!(ans.empty() && x==0)) ans += to_string(x);
        }

        return ans.empty() ? "0": ans;
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
