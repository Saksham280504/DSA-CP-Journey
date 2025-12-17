#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class DisJointSet {
    public:
    vector<int> parent;

    DisJointSet(int n) {
        parent.resize(n+1);
        for(int i=0; i<n+1; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node==parent[node]) return node;
        return parent[node] = findParent(parent[node]); // This is the step which gives the overall TC -> O(4*alpha)-> O(constant)
    }
};
class Job {
    public:
    int id;
    int profit;
    int deadline;
};

// TLE Solution
// class Solution {
//     private:
//     static bool comp(const Job& job1, const Job& job2) {
//         return job1.profit > job2.profit;
//     }
//     public:
//     vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
//         // 1. Creation of data structure for sorting
//         int n = deadline.size();
//         vector<Job> arr(n);
//         for(int i=0; i<n; i++) {
//             arr[i].id = i+1;
//             arr[i].profit = profit[i];
//             arr[i].deadline = deadline[i];
//         }
        
//         // 2. Apply the sort Algorithm
//         sort(arr.begin(),arr.end(),comp);
//         // Creation of our hashArr
//         int maxDeadline = -1;
//         for(int i=0; i<n; i++) {
//             maxDeadline = max(maxDeadline,deadline[i]);
//         }
//         vector<int> hash(maxDeadline+1,-1);
//         int maxProfit=0;
//         int numOfJobs=0;
//         for(int i=0; i<n; i++) {
//             for(int deadline = arr[i].deadline; deadline>=1; deadline--) {
//                 if(hash[deadline]==-1) {
//                     hash[deadline]=arr[i].id;
//                     numOfJobs++;
//                     maxProfit += arr[i].profit;
//                     break;
//                 }
//             }
//         }
//         return {numOfJobs,maxProfit};
//     }

//     // TC -> O(N + NlogN + N + N*N) -> TLE
//     // SC -> O(3N)
// };

// Most Optimized Solution
class Solution {
    private:
    static bool comp(const Job& job1, const Job& job2) {
        return job1.profit > job2.profit;
    }
    public:
        vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
            int n = deadline.size();
            vector<Job> arr(n);
            for(int i=0; i<n; i++) {
                arr[i].id = i+1;
                arr[i].deadline = deadline[i];
                arr[i].profit = profit[i];
            }

            sort(arr.begin(),arr.end(),comp);
            int maxDeadline = *max_element(deadline.begin(),deadline.end());
            int numOfJobs = 0;
            int maxProfit = 0;
            DisJointSet ds(maxDeadline);
            for(auto it: arr) {
                int availableSlot = ds.findParent(it.deadline);
                if(availableSlot>0) {
                    ds.parent[availableSlot] = ds.findParent(availableSlot-1);
                    numOfJobs++;
                    maxProfit += it.profit;
                }
            }

            return {numOfJobs,maxProfit};
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
