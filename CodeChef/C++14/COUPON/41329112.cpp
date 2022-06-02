#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
#define INF                 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 100005;
const int MOD = 1e9 + 7;
vector<vector<long long int> > cost, discount, dp[2];
int n, m;

long long int go(int i, int j, bool pre){
	if(i >= n)
		return 0;
	if(j >= m)
		return INF;
	if(dp[pre][i][j] != -1)
		return dp[pre][i][j];
	ll ans = INF;
	if(pre)
		ans = min(go(i, 0, 0), go(i + 1, j, 1) + max((ll) 0, cost[i][j] - discount[i - 1][j]));
	else
		ans = min(go(i, j + 1, 0), go(i + 1, j, 1) + cost[i][j]);
	return dp[pre][i][j] = ans;
}

void solve(){
	cin >> n >> m;
	// clearing / initializing things off :
	cost.clear(), discount.clear(), dp[0].clear(), dp[1].clear();
	dp[0].resize(n + 1, vector<ll>(m + 1, -1));
	dp[1].resize(n + 1, vector<ll>(m + 1, -1));
	cost.resize(n + 1, vector<ll>(m + 1, 0));
	discount.resize(n + 1, vector<ll>(m + 1, 0));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> cost[i][j];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> discount[i][j];
	cout << go(0, 0, 0) << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
