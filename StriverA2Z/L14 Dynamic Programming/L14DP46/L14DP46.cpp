#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int lbs(int n, vector<int> &arr)
{
    vector<int> dp1(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp1[i] < dp1[j] + 1)
                dp1[i] = dp1[j] + 1;
        }
    }

    int maxi = 0;
    vector<int> dp2(n, 1);

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j] && dp2[i] < dp2[j] + 1)
                dp2[i] = dp2[j] + 1;
        }
        maxi = max(maxi, dp2[i] + dp1[i] - 1);
    }

    return maxi;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    // Here we are asked to print the length of the largest bitonic subsequence, which is a sequence that have an increasing, decreasing or at most both of them in a single subsequence of an array.
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int longest = lbs(n, arr);
    cout << longest << endl;

    return 0;
}
