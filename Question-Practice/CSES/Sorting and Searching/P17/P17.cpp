#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll mod = 1e9+7;

    // For every number group present within the input array (a number group holds only 1 number type), we can choose at most one of the numbers from every number group to form all the subsequences with distinct elements. Therefore for a number group having freq frequency, we have freq+1 choices (1 choice of not choosing the number at all) that we can make. Multiplying all these will give us the total number of distinct element subsequences. To get Non-empty subsequences, you may just subtract 1 from the product.
    
    int n;
    cin >> n;
    map<ll,int> mpp;
    for(int i=0; i<n; i++) {
        ll y;
        cin >> y;
        mpp[y]++;
    }
    ll total = 1;
    for(auto it: mpp) {
        total = ((total%mod)*((it.second+1)%mod))%mod; // (a*b)%mod -> ((a%mod)*(b%mod))%mod
    }
    total = ((total%mod)-(1%mod)+mod)%mod; // (a-b)%mod -> ((a%mod)-(b%mod)+mod)%mod
    cout << total << endl;

    return 0;
}