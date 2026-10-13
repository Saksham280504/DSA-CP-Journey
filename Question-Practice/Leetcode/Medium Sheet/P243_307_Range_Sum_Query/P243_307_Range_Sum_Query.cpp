#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class NumArray {
private:
    vector<int> nums;
    vector<int> tree;
    int n;
    void add(int i, int del) {
        for(int j=i; j<=n; j += (j & (-j))) {
            tree[j] += del;
        }
    }
    int query(int i) {
        int sum = 0;
        for(int j=i; j>0; j -= (j & (-j))) {
            sum += tree[j];
        }
        return sum;
    }
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        tree.assign(n+1,0);
        for(int i=0; i<n; i++) add(i+1,nums[i]);
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index+1,delta);
    }
    
    int sumRange(int left, int right) {
        return query(right+1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

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
