#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 5002;
const int MOD = 1e9 + 7;
long long int n, m, q[N], pre_sum[N], dp[N][N], greedy[N];
pair<long long int, long long int> P[N];

bool cmp(pair<long long int, long long int> a, pair<long long int, long long int> b){
	return a.second < b.second;
}

void solve(){
	cin >> n >> m;
	pre_sum[0] = greedy[0] = 0;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			dp[i][j] = LLONG_MAX;
	for(int i = 1; i <= n; ++i)
		cin >> q[i];
	for(int i = 1; i <= m; ++i)
		cin >> P[i].first; // p[i];
	for(int i = 1; i <= m; ++i)
		cin >> P[i].second; // t[i];
	sort(P + 1, P + m + 1, cmp);
	dp[0][0] = 0;
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= m; ++j){
			if(i){
				if(dp[i - 1][j] != LLONG_MAX) 
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + q[i]);
			}
			if(j){
				if(dp[i][j - 1] >= P[j].second) 
					continue;
				else if(dp[i][j - 1] + P[j].first <= P[j].second)
					dp[i][j] = min(dp[i][j], P[j].second);
				else
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + P[j].first);
			}
		}
	}
	cout << (dp[n][m] == LLONG_MAX ? -1 : dp[n][m]) << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
