#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define pii pair<long long, pair<int, int> >
#define F first 
#define S second
using namespace std;
const int N = 1e3 + 5, MOD = 1e9 + 7;
long long n, k, b[N], c[N], dp[N][20005];
vector<long long> v, dpp(N, INT_MAX);

long long go(int i, int left){
	if(i == n)
		return 0;
	if(dp[i][left] != -1)
		return dp[i][left];
	long long ans = 0;
	ans = max(ans, go(i + 1, left));
	if(left + v[i] <= k)
		ans = max(ans, go(i + 1, left + v[i]) + c[i]);
	return dp[i][left] = ans;
}

void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	for(int i = 0; i < n; ++i)
		cin >> c[i];
	// initially, all elements are 1 in a[].
	v.clear();
	for(int i = 0; i < n; ++i)
		v.pb(dpp[b[i]]);
	/*
	for(auto k : v)
		cout << k << ' ';
	cout << endl;
	*/
	memset(dp, -1, sizeof dp);
	cout << go(0, 0) << '\n';
}

int main(){
	fast;
	dpp[1] = 0;
	for(int i = 1; i < N; ++i){
		for(int j = 1; j <= i; ++j){
			if(i + i/j >= N) continue;
			dpp[i + i/j] = min(dpp[i + i/j], dpp[i] + 1);
		}
	}
	int t = 1;
	cin >> t;
	while(t--)
		solve();
}