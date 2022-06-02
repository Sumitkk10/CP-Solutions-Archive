#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int dp[N];

void solve(){
	int n, m;
	cin >> n >> m;
	int ans = 0;
	while(n){
		int x = n % 10;
		ans = (ans + ((x + m < 10) ? 1 : dp[(x + m - 10)])) % MOD;
		n /= 10;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	for(int i = 0; i <= 8; ++i)
		dp[i] = 2;
	dp[9] = 3;
	for(int i = 10; i < N; ++i)
		dp[i] = (dp[i - 9] + dp[i - 10]) % MOD;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
