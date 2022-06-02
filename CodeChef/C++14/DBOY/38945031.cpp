#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1002;
const int MOD = 1e9 + 7;
ll n, k[N], h[N], dp[N][N];

ll solve(int i, long long int req){
	if(req == 0) return 0;
	if(i >= n || req < 0) return INT_MAX;
	if(dp[i][req] != -1) return dp[i][req];
	ll mn = INT_MAX;
	mn = min(mn, solve(i, req - k[i]) + 1);
	mn = min(mn, solve(i + 1, req));
	return dp[i][req] = mn;
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> h[i];
		for(int i = 0; i < n; ++i)
			cin >> k[i];
		ll ans = 0;
		for(int i = 0; i < n; ++i){
			ll req = 2 * h[i];
			ans += solve(0, req);
			// cout << ans << " ";
		}
		cout << ans << "\n";
	}
	return 0;
}
