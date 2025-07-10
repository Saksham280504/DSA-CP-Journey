#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    int n,l;
    cin >> n >> l;
    vector<vector<int>> arr;
    vector<int> rowArr;
    for(int i=0; i<n; i++) {
        for(int j=0; j<l; j++) {
            int nums;
            cin >> nums;
            rowArr.push_back(nums);
        }
        arr.push_back(rowArr);
        rowArr.clear();
    }

    // Optimal approach -> depends on two things : 1) Implementation and 2) Clean code-writing

    vector<int> ansArr;
    int left = 0;
    int right = l-1;
    int top = 0;
    int bottom = n-1;

    while(top<=bottom && left<=right) {    
    for(int i=left; i<=right; i++) {
        ansArr.push_back(arr[top][i]);
    }
    top++;
    for(int i=top; i<=bottom; i++) {
        ansArr.push_back(arr[i][right]);
    }
    right--;
    
    if(top<=bottom){
    for(int i=right; i>=left; i--) {
        ansArr.push_back(arr[bottom][i]);
    }
    bottom--;
    }

    if(left<=right) {
    for(int i=bottom; i>=top; i--) {
        ansArr.push_back(arr[i][left]);
    }
    left++;
    }
}

int m = ansArr.size();

for(int i=0; i<n; i++){
    for(int j=0; j<l; j++) {
        cout << arr[i][j] << " ";
    }
    cout << endl;
}

for(int i=0; i<m; i++) {
    if(i%l==0) cout << endl << ansArr[i] << " ";
    else cout << ansArr[i] << " ";
}
    return 0;
}

// TC -> O(N*L)
// SC -> O(N*L)