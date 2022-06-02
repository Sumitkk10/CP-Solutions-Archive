#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
bool ok[N], vis[N];
vector<int> graph[N];
set<int> ans;

void dfs(int source, int par, bool pt) {
	vis[source] = 1;
	bool okk = 0;
	for (auto k : graph[source]) {
		if (!vis[k]) {
			dfs(k, source, ok[k] ? 1 : 0);
			if (!ok[k])
				pt = 0;
		}
	}
	if (pt) ans.insert(source);
}

void solve() {
	int n, source;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int p, c;
		cin >> p >> c;
		if (p == -1) {
			source = i + 1;
			continue;
		}
		graph[i + 1].push_back(p);
		graph[p].push_back(i + 1);
		ok[i + 1] = c;
	}
	dfs(source, -1, 0);
	if (ans.size())
		for (auto k : ans)
			cout << k << ' ';
	else
		cout << "-1\n";
}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	return 0;
}