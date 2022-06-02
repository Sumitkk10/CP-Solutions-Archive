#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 500;
const int MOD = 1e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;
	int dp[n];
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; ++i)
		dp[i] = (dp[i - 1] + dp[max(0, i - k)]) % MOD;
	cout << dp[n] << "\n";
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
