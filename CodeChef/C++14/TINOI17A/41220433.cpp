#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, r, c, cnt;
map<pair<int, int>, bool> vis;
vector<pair<int, int> > patches[N];
set<pair<int, int> > s;

void dfs(int i, int j){
	if(vis[{i, j}] or i >= r or j >= c or i < 0 or j < 0)
		return;
	vis[{i, j}] = true;
	patches[cnt].push_back({i, j});
	if(s.find({i + 1, j}) != s.end()) 
		dfs(i + 1, j);
	if(s.find({i, j + 1}) != s.end())
		dfs(i, j + 1);
	if(s.find({i, j - 1}) != s.end())
		dfs(i, j - 1);
	if(s.find({i - 1, j}) != s.end())
		dfs(i - 1, j);
}

int main(){
	fast;
	cin >> r >> c >> n;
	for(int i = 0; i < n; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		s.insert({u, v});
	}
	for(auto k : s){
		if(!vis[{k.first, k.second}]){
			dfs(k.first, k.second);
			cnt++;
		}
	}
	ll ans = 0;
	for(int i = 0; i < cnt; ++i){
		ll area = 0;
		for(auto k : patches[i]){
			if(s.find({k.first + 1, k.second}) == s.end())
				area++;
			if(s.find({k.first, k.second + 1}) == s.end())
				area++;
			if(s.find({k.first - 1, k.second}) == s.end())
				area++;
			if(s.find({k.first, k.second - 1}) == s.end())
				area++;
		}
		ans = max(ans, area);
	}
	cout << ans << '\n';
	return 0;
}
