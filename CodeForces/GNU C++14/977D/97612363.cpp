#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 102;
const int MOD = 1e8;
vector<long long int> graph[N], ans;
bool vis[102];

void dfs(int source){
	vis[source] = 1;
	ans.push_back(source);
	for(auto k : graph[source])
		if(!vis[k])
			dfs(k);
}

void solve(){
	int n;
	cin >> n;
	long long int a[n];
	map<long long int, long long int> mp, pos, position;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		mp[a[i]]++;
		pos[a[i]] = i;
		position[i] = a[i];
	}
	for(int i = 0; i < n; ++i){
		if(mp[a[i] / 3] && a[i] % 3 == 0) graph[i].push_back(pos[a[i] / 3]);
		if(mp[2 * a[i]]) graph[i].push_back(pos[2 * a[i]]);
	}
	for(int i = 0; i < n; ++i){
		dfs(i);
		if(ans.size() == n){
			for(auto k : ans) 
				cout << position[k] << ' ';
			return;
		}
		memset(vis, 0, sizeof(vis));
		ans.clear();
	}
	cout << "-1\n";
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
