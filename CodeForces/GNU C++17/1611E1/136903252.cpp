#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, k, pos[N];
vector<int> graph[N];

void solve(){
	cin >> n >> k;
	queue<int> q;
	vector<int> dis(n + 1, INT_MAX), dis1(n + 1, INT_MAX);
	for(int i = 1; i <= k; ++i){
		cin >> pos[i];
		q.push(pos[i]);
		dis[pos[i]] = 0;
	}
	for(int i = 1; i <= n; ++i)
		graph[i].clear();
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto k : graph[node]){
			if(dis[k] > dis[node] + 1){
				dis[k] = dis[node] + 1;
				q.push(k);
			}
		}
	}
	q.push(1);
	dis1[1] = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto k : graph[node]){
			if(dis1[k] > dis1[node] + 1){
				dis1[k] = dis1[node] + 1;
				q.push(k);
			}
		}
	}
	for(int i = 2; i <= n; ++i){
		if(graph[i].size() == 1 and dis1[i] < dis[i]){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";

}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}