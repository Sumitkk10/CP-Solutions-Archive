#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e6 + 5;
long long n, MOD;

long long power(long long x, long long y){
	x %= MOD;
	long long ans = 1;
	while(y){
		if(y & 1)
			ans = (ans * x) % MOD;
		y >>= 1ll;
		x = (x * x) % MOD;
	}
	return ans;
}

long long sub(long long x, long long y){
	return ((x % MOD) - (y % MOD) + MOD) % MOD;
}

long long add(long long x, long long y){
	return ((x % MOD) + (y % MOD)) % MOD;
}

void solve(){
	cin >> n >> MOD;
	// let dp[n] be the number of non-periodic string of length n
	// dp[n] = 2^n - number of periodic string of length of n
	long long dp[n + 1];
	dp[1] = 2;
	for(int i = 2; i <= n; ++i){
		dp[i] = power(2, i);
		for(int j = 1; j * j <= i; ++j){
			if(i % j) continue;
			dp[i] = sub(dp[i], dp[j]);
			if(i/j != j and i/j != i)
				dp[i] = sub(dp[i], dp[i/j]);
		}
	}
	cout << dp[n] << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}