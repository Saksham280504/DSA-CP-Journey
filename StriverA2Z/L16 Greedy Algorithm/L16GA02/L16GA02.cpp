#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    bool static comp(vector<int>& item1, vector<int>& item2) {
        return ((double)item1[0]/(double)item1[1])>=((double)item2[0]/(double)item2[1]);
    }
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> Item(n); // I need this Item vector because I need to perform the sorting operation and this makes it much more easier

        for(int i=0; i<n; i++) {
            vector<int> temp = {val[i],wt[i]};
            Item[i] = temp;
        }

        // Sort the Item vector
        sort(Item.begin(),Item.end(),comp); // comp is a custom comparator function that we use to sort the Item

        // Create a TotalVal
        double totalVal = 0;
        for(int i=0; i<n; i++) { // Here we didn't apply loop on capacity because it might happen that the capacity might be so big that all are items get filled into the bag
            if(Item[i][1]<=capacity) {
                totalVal += Item[i][0];
                capacity -= Item[i][1];
            }
            else {
                totalVal += ((double)Item[i][0]/(double)Item[i][1])*capacity;
                break;
            }
        }

        return totalVal;

        // TC -> O(NlogN + N)
        // SC -> O(2N) (necessary otherwise we would have to run the sorting function twice)
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
