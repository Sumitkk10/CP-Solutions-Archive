#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define F first
#define S second
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int n, a[N], dis[N][2];
bool vis[N];
vector<int> graph[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		dis[i][0] = dis[i][1] = INT_MAX;
	}
	for(int i = 1; i <= n; ++i){
		if(i + a[i] <= n)
			graph[i + a[i]].push_back(i);
		if(i - a[i] >= 1)
			graph[i - a[i]].push_back(i);
	}
	queue<pair<int, int> > q;
	for(int i = 1; i <= n; ++i){
		if(a[i] % 2){
			vis[i] = true;
			q.push({0, i});
			dis[i][0] = 0; 
		}
	}
	while(!q.empty()){
		int cost = q.front().F, node = q.front().S;
		q.pop();
		for(auto k : graph[node]){
			if(!vis[k]){
				q.push({cost + 1, k});
				if(a[k] % 2 == 0 and dis[k][0] > cost + 1)
					dis[k][0] = cost + 1;
				vis[k] = true;
			}
		}
	}
	memset(vis, 0, sizeof vis);
	for(int i = 1; i <= n; ++i){
		if(a[i] % 2 == 0){
			vis[i] = true;
			q.push({0, i});
			dis[i][1] = 0; 
		}
	}
	while(!q.empty()){
		int cost = q.front().F, node = q.front().S;
		q.pop();
		for(auto k : graph[node]){
			if(!vis[k]){
				q.push({cost + 1, k});
				if(a[k] % 2 == 1 and dis[k][1] > cost + 1)
					dis[k][1] = cost + 1;
				vis[k] = true;
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << (dis[i][a[i] % 2] == INT_MAX ? -1 : dis[i][a[i] % 2]) << ' ';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}