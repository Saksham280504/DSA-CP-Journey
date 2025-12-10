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
    // Array hashing
    /*
    int n;
    cin >> n;
    int arr[n];
    for(int i=1; i<=n; i++){
        cin >> arr[i-1];
    }

    // pre compute
    
    int hash[13] = {0};
    for(int i=1; i<=n; i++){
        hash[arr[i-1]] += 1;
    }

    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;
        //fetch
        cout << hash[number] << endl;
    }
    */
    // String hashing
    /*
        string s;
    cin >> s;

    //pre compute
    // int hash[26] = {0};
    int hash[256] = {0};
    for(int i=1; i<=s.size(); i++) {
        // hash[s[i-1]-'a'] +=1;
        hash[s[i-1]] +=1;
    }

    int q;
    cin >> q;
    while(q--) {
        char c;
        cin >> c;
        // cout << hash[c-'a'] << endl;
        cout << hash[c] << endl;
        //fetch
    }
    */
    // Mapping
    /*
    int n;
    cin >> n;
    int arr[n];
    for(int i=1;i<=n;i++){
        cin >> arr[i-1];
    }
    // pre compute
    // map<int, int> mpp;
    unordered_map<int, int> mpp;
    for(int i=1; i<=n; i++){
        mpp[arr[i-1]]++;
    }

    //iterate in the map
    for(auto it: mpp) {
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        //fetch
        cout << mpp[number] << endl;
    }
    */
    // Problem

    int n;
    cin >> n;
    int arr[n];
    for(int i=1; i<=n; i++){
        cin >> arr[i-1];
    }

    // precompute
    map<int, int> mpp;
    for(int i=1; i<=n; i++){
        mpp[arr[i-1]]++;
    }

    int maxFreq = 0;
    int minFreq = n;
    vector<int> v1;
    vector<int> v2;

    for(auto it : mpp) {
        if(maxFreq <= it.second) {
            maxFreq = it.second;
        }
        if(it.second <= minFreq) {
            minFreq = it.second;
        }
    }

    for(auto it: mpp) {
        if(maxFreq == it.second) {
            v1.push_back(it.first);
        }
        if(minFreq == it.second) {
            v2.push_back(it.first);
        }
    }

    if(v1.size()==1) cout << "The element with maximum frequency " << maxFreq << "is " << v1[0] << endl;
    else {  
        cout << "The elements with maximum frequency " << maxFreq << " are: ";
        for(int i=1; i<=v1.size(); i++) {
            cout << v1[i-1] << " ";
        }
        cout << endl;
    }
    if(v2.size()==1) cout << "The element with minimum frequency " << minFreq << " is " << v2[0] << endl;
    else {  
        cout << "The elements with minimum frequency " << minFreq << " are: ";
        for(int i=1; i<=v2.size(); i++) {
            cout << v2[i-1] << " ";
        }
        cout << endl;
    }



    return 0;
}
