#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5;
const int MOD = 1e9 + 7;
ll n, a[N], b[N], c[N], dp[N][3];

ll solve(int i, int pre){
	if(i >= n) return 0;
	ll mn = 1e10;
	if(dp[i][pre] != -1)
		return dp[i][pre];
	if(pre == 0){
		mn = min(mn, solve(i + 1, 1));
		mn = min(mn, solve(i + 1, 2) + c[i]);
	}
	else if(pre == 1){
		if(i != 0){
			if(a[i] >= a[i - 1]) mn = min(mn, solve(i + 1, 1));
			if(b[i] >= a[i - 1]) mn = min(mn, solve(i + 1, 2) + c[i]);
		}
	}
	else{
		if(i != 0){
			if(a[i] >= b[i - 1]) mn = min(mn, solve(i + 1, 1));
			if(b[i] >= b[i - 1]) mn = min(mn, solve(i + 1, 2) + c[i]);
		}
	}
	return dp[i][pre] = mn;
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for(int i = 0; i < n; ++i) 
			cin >> a[i];
		for(int i = 0; i < n; ++i) 
			cin >> b[i];
		for(int i = 0; i < n; ++i) 
			cin >> c[i];
		ll ans = solve(0, 0);
		if(ans == 1e10) cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
} 