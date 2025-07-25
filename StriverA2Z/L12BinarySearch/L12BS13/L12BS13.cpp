#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool isPossible(vector<int>& arr, int n, int m, int k, int day) {
    int cnt = 0;
    int nob = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]<=day) cnt++;
        else {
            nob += cnt/k;
            cnt = 0;
        }
    }
    nob += cnt/k;

    if(nob>=m) return true;
    return false;
}
int MinDay(vector<int>& arr, int n, int m, int k, int mini, int maxi) {
    if(n<(m*k)) return -1;
    
    for(int day = mini; day<=maxi; day++) {
        bool possibility = isPossible(arr,n,m,k,day);
        if(possibility) return day;
    }

    return -1;
}

int MinDayBS(vector<int>&arr, int n, int m, int k, int mini, int maxi) {
    if(n<(m*k)) return -1;

    int low = mini;
    int high = maxi;
    int ans = INT_MAX;
    while(low<=high) {
        int mid = (low+high)/2;
        bool possiblity = isPossible(arr,n,m,k,mid);
        if(possiblity) {
            ans = min(ans,mid);
            high = mid-1;
        }
        else low = mid+1;
    }

    return ans;
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
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int m, k;
    cin >> m >> k;

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i=0; i<n; i++) {
        mini = min(mini,arr[i]);
        maxi = max(maxi, arr[i]);
    }

    // int miniDay = MinDay(arr,n,m,k,mini,maxi);
    // TC -> O((maxi-mini+1)*N)

    int miniDay = MinDayBS(arr,n,m,k,mini,maxi);
    // TC -> O(log2(maxi-mini+1)*N)

    if(miniDay==-1) cout << "Bouquets not possible" << endl;
    else cout << miniDay << endl;
 
    return 0;
}
