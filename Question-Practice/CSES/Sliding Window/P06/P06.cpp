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
    int n,k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<ll,ll> freqmpp; // {element, frequency}
    map<ll,set<ll>> inverse_mpp; // {frequency , number of elements}

    int i=0;
    for(int j=0; j<n; j++) {
        // INSERTION
        ll old_freq = freqmpp[arr[j]]++;
        if(old_freq>0) inverse_mpp[old_freq].erase(arr[j]); // You are not adding the element into the window for the first time
        if(inverse_mpp[old_freq].empty()) inverse_mpp.erase(old_freq);
        inverse_mpp[old_freq+1].insert(arr[j]);
        if(j-i+1<k) continue;
        // DELETION
        auto [freq,st] = *inverse_mpp.rbegin(); // Find the highest frequency elements
        cout << *st.begin() << " "; // Print the smallest element among them
        ll fr = freqmpp[arr[i]]--; // Decrease the frequency of the left most element
        if(freqmpp[arr[i]]==0) freqmpp.erase(arr[i]); // If after deletion, frequency becomes 0,, remove from window
        inverse_mpp[fr].erase(arr[i]); // remove the element from the set of elements having the initial frequency.
        if(inverse_mpp[fr].empty()) inverse_mpp.erase(fr); // If the set becomes empty after removal, remove that frequency from map.
        if(fr>1) inverse_mpp[fr-1].insert(arr[i]); // If originally before removal the frequency of element was > 1, then after removal atleast 1 frequency of that element will remain, thus insert that element in the set of elemnts having frequency = fr(original frequency)-1.
        i++;
    }
    cout << endl;

    return 0;
}
