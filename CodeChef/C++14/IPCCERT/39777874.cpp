#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve() {
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x;
			sum += x;
		}
		int x; cin >> x;
		ans += (x <= 10 and sum >= m);
	}
	cout << ans << '\n';
}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	return 0;
}
