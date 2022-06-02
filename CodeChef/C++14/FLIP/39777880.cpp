#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve() {
	string a, b;
	cin >> a >> b;
	int vis[a.size()], ans = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == b[i] or vis[i]) continue;
		for (int j = i + 2; j < a.size(); j += 2) {
			if (vis[j] or a[j] == b[j]) break;
			vis[j] = 1;
		}
		ans++;
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
