#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll int
#define pb push_back
#define F first 
#define S second
#define pii pair<long long, pair<int, pair<int, int> > > 
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
long long n, m, dp[N][2][2];
vector<pair<int, int> > g[N];
bool vis[N][2][2];

void dijk(int source){
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 2; ++j)
			dp[i][j][0] = dp[i][j][1] = 1e16;
	}
	dp[source][0][0] = 0;
	set<pii> pq;
	pq.insert({0, {1, {0, 0}}});
	while(!pq.empty()){
		pii cur = *pq.begin();
		pq.erase(pq.begin());
		// if(cur.F != dp[cur.S.F][cur.S.S.F][cur.S.S.S]) continue;
		for(auto k : g[cur.S.F]){
			bool mx = cur.S.S.F, mn = cur.S.S.S;
			for(int j = 0; j <= 1 - mx; ++j){
				for(int i = 0; i <= 1 - mn; ++i){
					if(dp[k.F][mx | j][mn | i] > dp[cur.S.F][mx][mn] + k.S + (j == 0 ? -k.S : 0) + (i == 0 ? k.S : 0)){
						auto kk = pq.find({dp[k.F][mx | j][mn | i], {k.F, {mx | j, mn | i}}});
						if(kk != pq.end())
							pq.erase(kk);
						dp[k.F][mx | j][mn | i] = dp[cur.S.F][mx][mn] + k.S + (j == 0 ? -k.S : 0) + (i == 0 ? k.S : 0);
						pq.insert({dp[k.F][mx | j][mn | i], {k.F, {mx | j, mn | i}}});
					}
				}
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		g[u].pb({v, c});
		g[v].pb({u, c});
	}
	dijk(1);
	for(int i = 2; i <= n; ++i)
		cout << dp[i][1][1] << ' ';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}