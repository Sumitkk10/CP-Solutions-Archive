#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	int a[n + 1];
	vector<int> pos[n + 1];
	for (int i = 1; i <= n; ++i)
		pos[i].push_back(0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i)
		pos[i].push_back(n + 1);
	int ans = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		if (pos[i].size() == 2) continue;
		int ct = 0;
		for (int j = 1; j < pos[i].size(); ++j)
			if (pos[i][j - 1] != pos[i][j] - 1)
				ct++;
		ans = min(ans, ct);
	}
	cout << ans << '\n';
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}