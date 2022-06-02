#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<pair<long long int, long long int> > graph[N];
long long n, m, dis[N];
void dijkstra(int source, int distance){
	set<pair<long long int, int> > s; // distance -- node;	
	dis[source] = 0;
	s.insert({0, 1});
	while(!s.empty()){
		long long node = s.begin()->second, cost = s.begin()->first;
		s.erase(s.begin());
		for(auto e : graph[node]){
			if(dis[e.first] > cost + e.second){
				s.erase({dis[e.first], e.first});
				dis[e.first] = cost + e.second;
				s.insert({dis[e.first], e.first});
			}
		}
	}
}

void calc(){
	int cur = n;
	vector<int> ans;
	while(cur != 1){
		ans.push_back(cur);
		for(auto k : graph[cur]){
			if(dis[k.first] + k.second == dis[cur]){
				cur = k.first;
				break;
			}
		}
	}
	ans.push_back(1);
	for(int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main(){
	fast;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		dis[i] = LLONG_MAX;
	for(int i = 0; i < m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({v, c});
		graph[v].push_back({u, c});
	}
	dijkstra(1, 0);
	if(dis[n] == LLONG_MAX){
		cout << "-1\n";
		return 0;
	}
	calc();
	return 0;
}
