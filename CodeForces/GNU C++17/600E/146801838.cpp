#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define pb push_back
#define S second
#define F first
using namespace std;
const int N = 1e5 + 2;
int n, col[N], tin[N], tout[N], timer, block = 1000, cnt[N];
vector<int> g[N], euler;

void dfs(int node, int par){
	euler.pb(node);
	tin[node] = ++timer;
	for(auto k : g[node])
		if(k != par)
			dfs(k, node);
	tout[node] = timer;
}

bool cmp(pair<int, pair<int, int> > x, pair<int, pair<int, int> > y){
	if(x.F / block == y.F / block)
		return x.S.F < y.S.F;
	return x.F / block < y.F / block;
}

void solve(){
	euler.pb(0);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> col[i];
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	vector<pair<int, pair<int, int> > > query;
	for(int i = 1; i <= n; ++i)
		query.pb({tin[i], {tout[i], i}});
	sort(query.begin(), query.end(), cmp);
	vector<int> ans(n + 1, 0);
	int l = 1, r = 0;
	multiset<pair<int, int> > s;
	for(int i = 0; i < query.size(); ++i){
		int _l = query[i].F, _r = query[i].S.F, idx = query[i].S.S;
		// cout << _l << ' ' << _r << ' ' << idx << endl;
		while(l < _l){
			auto k = s.lower_bound({cnt[col[euler[l]]], 0});
			if(k != s.end() and (*k).F == cnt[col[euler[l]]]){
				s.erase(k);
				if((*k).S - col[euler[l]] > 0)
					s.insert({(*k).F, (*k).S - col[euler[l]]});
			}
			cnt[col[euler[l]]]--;
			k = s.lower_bound({cnt[col[euler[l]]], 0});
			if(k != s.end() and (*k).F == cnt[col[euler[l]]]){
				s.erase(k);
				s.insert({(*k).F, (*k).S + col[euler[l]]});
			}
			else
				s.insert({cnt[col[euler[l]]], col[euler[l]]});
			++l;
		}
		while(r < _r){
			++r;
			auto k = s.lower_bound({cnt[col[euler[r]]], 0});
			if(k != s.end() and (*k).F == cnt[col[euler[r]]]){
				s.erase(k);
				if((*k).S - col[euler[r]] > 0)
					s.insert({(*k).F, (*k).S - col[euler[r]]});
			}
			cnt[col[euler[r]]]++;
			k = s.lower_bound({cnt[col[euler[r]]], 0});
			if(k != s.end() and (*k).F == cnt[col[euler[r]]]){
				s.erase(k);
				s.insert({(*k).F, (*k).S + col[euler[r]]});
			}
			else
				s.insert({cnt[col[euler[r]]], col[euler[r]]});
		}
		while(l > _l){
			--l;
			auto k = s.lower_bound({cnt[col[euler[l]]], 0});
			if(k != s.end() and (*k).F == cnt[col[euler[l]]]){
				s.erase(k);
				if((*k).S - col[euler[l]] > 0)
					s.insert({(*k).F, (*k).S - col[euler[l]]});
			}
			cnt[col[euler[l]]]++;
			k = s.lower_bound({cnt[col[euler[l]]], 0});
			if(k != s.end() and (*k).F == cnt[col[euler[l]]]){
				s.erase(k);
				s.insert({(*k).F, (*k).S + col[euler[l]]});
			}
			else
				s.insert({cnt[col[euler[l]]], col[euler[l]]});
		}
		while(r > _r){
			auto k = s.lower_bound({cnt[col[euler[r]]], 0});
			if(k != s.end() and (*k).F == cnt[col[euler[r]]]){
				s.erase(k);
				if((*k).S - col[euler[r]] > 0)
					s.insert({(*k).F, (*k).S - col[euler[r]]});
			}
			cnt[col[euler[r]]]--;
			k = s.lower_bound({cnt[col[euler[r]]], 0});
			if(k != s.end() and (*k).F == cnt[col[euler[r]]]){
				s.erase(k);
				s.insert({(*k).F, (*k).S + col[euler[r]]});
			}
			else
				s.insert({cnt[col[euler[r]]], col[euler[r]]});
			--r;
		}
		ans[idx] = (*s.rbegin()).S;
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}

int32_t main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0ll;
}