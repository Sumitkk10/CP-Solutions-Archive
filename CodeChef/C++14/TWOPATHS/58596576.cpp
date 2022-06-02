#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e3 + 2;
int n, m, k, a[N][N], pre_sum[N][N], dp[N][N][21], dp1[N][N][21];

int go(int i, int j, int left){
	if(i == 0)
		return 0; 
	if(dp[i][j][left] != -1)
		return dp[i][j][left];
	int ans = INT_MIN;
	ans = max(ans, go(i - 1, j, left) + pre_sum[i][j]);
	if(left > 0 and j > 1)
		ans = max(ans, go(i - 1, j - 1, left - 1) + pre_sum[i][j]);
	return dp[i][j][left] = ans;
}

int goo(int i, int j, int left){
	if(i == 0)
		return 0;
	if(dp1[i][j][left] != -1)
		return dp1[i][j][left];
	int ans = INT_MAX;
	ans = min(ans, goo(i - 1, j, left) + pre_sum[i][j - 1]);
	if(left > 0 and j > 1)
		ans = min(ans, goo(i - 1, j - 1, left - 1) + pre_sum[i][j - 1]);
	return dp1[i][j][left] = ans;
}

void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> a[i][j];
			pre_sum[i][j] = pre_sum[i][j - 1] + a[i][j];
		}
	}
	memset(dp, -1, sizeof dp);
	memset(dp1, -1, sizeof dp1);
	vector<int> v;
	int mn[m + 1];
	mn[0] = INT_MAX;
	for(int i = 1; i <= m; ++i)
		v.pb(go(n, i, k));
	for(int i = 1; i <= m; ++i){
		int x = goo(n, i, k);
		mn[i] = min(mn[i - 1], x);
	}
	int ans = INT_MIN;
	for(int i = k + 2; i <= m; ++i)
		ans = max(ans, v[i - 1] - mn[i - k - 1]);
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}