#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<pair<int, int> > graph[N];
ll dp[N][(ll) log2(N)], n, lvl[N], dis[N], distance1[N], mx;

void dfs(int source, int par, int level) {
	dp[source][0] = par;
	lvl[source] = level;
	for (auto k : graph[source]) {
		if (k.first != par) {
			dis[k.first] = dis[source] + k.second;
			dfs(k.first, source, level + 1);
		}
	}
}

void init() {
	dfs(1, -1, 0);
	for (int i = 1; i <= (log2(n)); ++i)
		for (int j = 1; j <= n; ++j)
			if (dp[j][i - 1] != -1)
				dp[j][i] = dp[dp[j][i - 1]][i - 1];
}

ll LCA(int u, int v) {
	if (lvl[u] > lvl[v]) swap(u, v);
	ll d = lvl[v] - lvl[u];
	while (d) {
		int jump = log2(d);
		v = dp[v][jump];
		d -= pow(2, jump);
	}
	if (v == u)
		return v;
	for (int i = log2(n); i >= 0; --i) {
		if (dp[v][i] != -1 && dp[v][i] != dp[u][i]) {
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[v][0];
}

void dfs1(int source) {
	distance1[source] = 0;
	for (auto k : graph[source]) {
		if (k.first != dp[source][0]) {
			dfs1(k.first);
			distance1[source] = max(distance1[source], distance1[k.first] + k.second);
		}
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		int q;
		cin >> n >> q;
		for (int i = 1; i <= n - 1; ++i) {
			long long int u, v, c;
			cin >> u >> v >> c;
			graph[u].push_back({v, c});
			graph[v].push_back({u, c});
		}
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= log2(n); ++j)
				dp[i][j] = -1;
		init();
		dfs1(1);
		while (q--) {
			long long int a, b, x;
			cin >> a >> b >> x;
			long long distance = dis[a] + dis[b] - 2 * dis[LCA(a, b)];
			distance = max(distance, distance1[a] + distance1[b] + x);
			cout << distance << '\n';
		}
		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
			distance1[i] = 0;
			lvl[i] = 0;
			dis[i] = 0;
		}
		mx = 0;
	}
	return 0;
}
