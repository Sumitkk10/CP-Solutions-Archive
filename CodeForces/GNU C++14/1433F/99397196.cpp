#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 72;
const int MOD = 1e9 + 7;
int n, m, k, a[N][N], dp[N][N][N][N / 2];

long long int go(int i, int j, int mod, int cnt) {
	if (cnt > (m / 2))
		return INT_MIN;
	if (i == n) {
		if (mod)
			return INT_MIN;
		return 0;
	}
	if (dp[i][j][mod][cnt] != -1)
		return dp[i][j][mod][cnt];
	if (j == m)
		return dp[i][j][mod][cnt] = go(i + 1, 0, mod, 0);
	return dp[i][j][mod][cnt] = max(go(i, j + 1, (mod + a[i][j]) % k, cnt + 1) + a[i][j], go(i, j + 1, mod, cnt));
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	cout << go(0, 0, 0, 0) << "\n";
}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	return 0;
}