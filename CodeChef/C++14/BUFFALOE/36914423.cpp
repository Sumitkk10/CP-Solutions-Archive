#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 403;
const int MOD = 1e9 + 7;
ll n, k, cost[N], dp[N][N][N];

ll go(ll i, ll idx, ll times){
	ll mx = -INT_MAX;
	if(i > n || times >= k) return 0;
	if(dp[i][idx][times] != -1) return dp[i][idx][times];
	mx = max(mx, go(i + 1, idx, times));
	if(idx > 0)
		mx = max(mx, go(i + 1, 0, times + 1) + cost[i] - cost[idx]);
	if(idx == 0)
		mx = max(mx, go(i + 1, i, times + 1));
	return dp[i][idx][times] = mx;
}

int main(){
	fast;
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	for(int i = 1; i <= n; ++i) cin >> cost[i];
	cout << go(1, 0, 0);
	return 0;
}
