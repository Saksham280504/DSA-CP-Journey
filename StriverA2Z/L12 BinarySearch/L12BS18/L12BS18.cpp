#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numOfStds(vector<int>& pages, int n, int pageDiff) {
    int HoldingPages = 0;
    int stdCnt = 1;
    for(int i=0; i<n; i++) {
        if(HoldingPages+pages[i]<=pageDiff) {
            HoldingPages += pages[i];
        }
        else {
            stdCnt++;
            HoldingPages = pages[i];
        }
    }
    return stdCnt;
}
int MinOfMax(vector<int>& pages, int n, int stds, int low, int high) {
    if(n < stds) return -1;
    for(int i=low; i<=high; i++) {
        int stdCount = numOfStds(pages,n,i);
        if(stdCount==stds) return i;
    }
    return -1;
}

int MinOfMaxBS(vector<int>& pages, int n, int stds, int low, int high) {
    if(n < stds) return -1;
    
    while(low<=high) {
        int mid=(low+high)/2;
        int stdCount = numOfStds(pages,n,mid);
        if(stdCount > stds) low = mid+1;
        else high = mid-1;
    }

    return low;
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

    int n;
    cin >> n;
    vector<int> pages(n);

    for(int i=0; i<n; i++) {
        cin >> pages[i];
    }

    int stds;
    cin >> stds;

    // To find the minimum of maximum pages held by the student

    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);

    // Brute-force approach

    // int minOfMaxPages = MinOfMax(pages,n,stds,low,high);
    // TC -> O(N*l(sum-max+1)) This can be optimised using BS

    int minOfMaxPages = MinOfMaxBS(pages,n,stds,low,high);
    // TC -> O(N*log2(sum-max+1))

    if(minOfMaxPages==-1) cout << "No distribution possible" << endl;
    else cout << minOfMaxPages << endl;

    return 0;
}
