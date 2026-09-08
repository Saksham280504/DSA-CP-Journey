#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    int countRotations(string s, int k) {
        int ans = 0;
        int n = s.size();
        do {
            int cnt = 0;
            for(int i=0; i<(s.size()-1); i++) {
                if(s[i]==s[i+1]) cnt++;
            }
            if(cnt==k) ans++;
            auto it = s.begin();
            char ch = *it;
            s.erase(it);
            s += ch;
            n--;
        }
        while(n>0);
        return ans;
    }
};

// Q2
#define ll long long
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        for(int idx=0; idx<n; idx++) {
            int num = nums[idx];
            nums.push_back(num);
        }
       int i=0, j=0;
        ll leftSum = 0;
        while(j<(n/2)) {
            leftSum += (ll)nums[j];
            j++;
        }
        j--;
        int k=n/2, l=n/2;
        ll rightSum = 0;
        while(l<n) {
            rightSum += (ll)nums[l];
            l++;
        }
        l--;
        int cnt = 0;
        while(l<(2*n-1)) {
            if(leftSum>rightSum) cnt++;
            leftSum -= (ll)nums[i];
            i++;
            j++;
            leftSum += (ll)nums[j];
            rightSum -= (ll)nums[k];
            k++;
            l++;
            rightSum += (ll)nums[l];
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
