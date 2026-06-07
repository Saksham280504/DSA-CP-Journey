#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    bool consecutiveSetBits(int n) {
        int isPrevSet = 0;
        int isTrue = 0;
        int cnt = 0;
        for(int i=0; i<31; i++) {
            if((1<<i)&n) {
                if(isPrevSet==0) isPrevSet++;
                else if(isTrue>0) {
                    isTrue = -1;
                    cnt--;
                }
                else if(isPrevSet>0 && isTrue==-1) isPrevSet++;
                else {
                    isTrue = 1;
                    cnt++;
                }
            }
            else if(isPrevSet) {
                isTrue = 0;   
                isPrevSet = 0;
            }
        }

        return (cnt==1);
    }
};

// Q2
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        // Finding minimum number of on bulbs
        vector<bool> Illuminous(n,false);
        int onBulbs = 0;
        int numIlluminated = 0;
        int idx = 1;
        if(n==1) numIlluminated = brightness;
        while(n>1 && idx<n) {
            if(numIlluminated>=brightness) break;
            else { // numIlluminated < brightness
                if(Illuminous[idx-1]) {
                    numIlluminated++;
                    Illuminous[idx] = true;
                }
                else {
                    if((idx+1)<n) {
                        numIlluminated += 3;
                        Illuminous[idx] = true;
                        Illuminous[idx-1] = true;
                        Illuminous[idx+1] = true;
                        if((idx+2)>=(n-1)) {
                            idx += 2;
                        }
                        else {
                            idx += 3;
                        }
                    }
                    else {
                        numIlluminated += 2;
                        Illuminous[idx] = true;
                        Illuminous[idx-1] = true;
                        idx++;
                    }
                }
            }
        }
        vector<vector<int>> overLappingIntervals;
        sort(intervals.begin(),intervals.end());
        vector<int> interval = intervals[0];
        int m = intervals.size();
        for(int i=1; i<m; i++) {
            if(intervals[i][0]<=intervals[i-1][1]) {
                interval[0] = min(interval[0],intervals[i][0]);
                interval[1] = max(interval[1],intervals[i][1]);
            }
            else {
                overLappingIntervals.push_back(interval);
                interval = intervals[i];
            }
        }

        overLappingIntervals.push_back(interval);

        int totalTime = 0;
        for(auto inter: overLappingIntervals) {
            totalTime += (inter[1]-inter[0]+1);
        }

        return numIlluminated*totalTime;
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

    int n;
    cin >> n;
        int isPrevSet = 0;
        int isTrue = 0;
        int cnt = 0;
        for(int i=0; i<31; i++) {
            if((1<<i)&n) {
                if(isPrevSet==0) isPrevSet++;
                else if(isTrue>0) {
                    isTrue = -1;
                    cnt--;
                }
                else if(isPrevSet>0 && isTrue==-1) isPrevSet++;
                else {
                    isTrue = 1;
                    cnt++;
                }
            }
            else if(isPrevSet) {
                isTrue = 0;   
                isPrevSet = 0;
            }
        }

        cout << (cnt==1) << endl;

    return 0;
}
