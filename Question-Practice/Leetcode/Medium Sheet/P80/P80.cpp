#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char task: tasks) {
            freq[task-'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        int cntMax = 0;
        for(int frequency: freq) {
            if(frequency==maxFreq) cntMax++;
        }

        int totalIntervals = maxFreq-1;
        int intervalSize = n+1;
        int minTime = totalIntervals*intervalSize + cntMax;
        int size = tasks.size();
        return max(size, minTime);

        // If number of tasks are enough to fill up the gap-
        // For eg:- tasks = [A,B,C,D,A,E,A, E] , n=2
        // Here, maxFreq = 3, cntMax = 1
        // A _ _ A _ _ A -> A B C A D E A E (here the minimumTime = tasks.size() and not minTime as we had enough tasks to fill the gaps leading to no chance of having idle gaps.)
        // In case the other tasks were not enough, then we would have minimumTime = minTime
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
