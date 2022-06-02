#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N];
bool vis[N];
int mx;

void dfs(int source){
	vis[source] = 1;
	++mx;
	for(auto k : graph[source])
		if(!vis[k])
			dfs(k);
}

int main(){
	fast;
	int n, k;
	cin >> n >> k;
	vector<int> id[n];
	for(int i = 0; i < n; ++i){
		int p;
		cin >> p;
		while(p--){
			int x;
			cin >> x;
			id[i].push_back(x);
		}
	}
	for(int i = 0; i < n; ++i){
		unordered_map<int, bool> mp;
		for(auto k : id[i])
			mp[k] = true;
		for(int j = i + 1; j < n; ++j){
			int ok = 0;
			for(auto k : id[j])
				if(mp[k])
					ok++;
			if(ok >= k){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	dfs(0);
	cout << mx << '\n';
	return 0;
}
