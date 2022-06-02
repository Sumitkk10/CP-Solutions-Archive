#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll add(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}

ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}

void solve(){
	int k, n;
	cin >> k >> n;
	if(k == 1){
		cout << (n % 3 == 0 ? "1\n" : "0\n");
		return;
	}
	if(k == 2){
		long long int dp[n + 5];
		dp[0] = 1;
		dp[1] = 0;
		dp[2] = 1;
		for(int i = 3; i <= n; ++i)
			dp[i] = (dp[i - 2] + dp[i - 3]) % MOD;
		cout << dp[n] << '\n';
		return;
	}
	long long int f[n + 2] = {0}, g[n + 2] = {0}, h[n + 2] = {0};
	f[1] = f[2] = 1;
	f[3] = 2;
	g[1] = g[2] = 0;
	g[3] = 1;
	h[1] = 0;
	h[2] = h[3] = 1;
	for(int i = 4; i <= n; ++i){
		f[i] = add(f[i - 1], add(f[i - 3], mul(2, g[i - 3])));
		g[i] = add(g[i - 3], h[i - 1]);
		h[i] = add(h[i - 3], f[i - 2]);
	}
	cout << f[n] << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
