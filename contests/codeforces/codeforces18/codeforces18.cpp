#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve1() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }
    map<int,int> mpp;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            mpp[mat[i][j]]++;
        }
    }
    
    int maxi = INT_MIN;
    for(auto it: mpp) {
        maxi = max(maxi,it.second);
    }
    if(maxi<=(n*(n-1))) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

void solve2() {
	int n,k,p,m,cnt=0;
	cin>>n>>k>>p>>m;
    vector<int> a(5005);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cost1=0;
	if(p>k){
		sort(a.begin()+1,a.begin()+p);
		for(int i=1;i<=p-k;i++){
			cost1+=a[i];
		}
		cost1+=a[p];
		if(cost1>m){
			cout<<0<<endl;
			return;
		}
		cnt++;
		m-=cost1;
	}else{
		cost1+=a[p];
		if(cost1>m){
			cout<<0<<endl;
			return;
		}
		cnt++;
		m-=cost1;
	}
	//cout<<"here"<<m<<endl;
	int temp=a[p];
	a[p]=1e9+7;
	sort(a.begin()+1,a.begin()+1+n);
	cost1=0;
	for(int i=1;i<=n-k;i++){
		cost1+=a[i];
	}
	cost1+=temp;
	cnt+=m/cost1;
	cout<<cnt<<endl;
	return;
}

void solve3() {
    int n;
    cin >> n;
    vector<double> c(n), p(n);
    for(int i=0; i<n; i++) cin >> c[i] >> p[i];
    double ans = 0;
    for(int i=n-1; i>=0; i--) ans = max(ans, c[i] + ans*(1-p[i]/100.00));

    cout << fixed << setprecision(10) << ans << endl;
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

    int t;
    cin >> t;
    while(t--) solve3();

    return 0;
}
